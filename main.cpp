#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>

int main() {
    // 宣告變數
    bool space = false, countornot = false;
    int Count = 0;
    int CaveSize = 300;

    std::cout << '0' << std::endl;
    
    // 創建遊戲窗口(600 * 900像素)
    sf::RenderWindow window(sf::VideoMode(600, 900), "Bird");

    window.setVerticalSyncEnabled(false);

    // 使用隨機設備來生成種子
    std::random_device rd;

    // 使用梅森旋轉演算法 (Mersenne Twister) 來生成隨機數
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(150, 550);

    // 創建鳥
    sf::CircleShape bird(10.f);  // 半徑為 10
    bird.setFillColor(sf::Color::Yellow);
    bird.setPosition(100.f, 450.f);  // 初始位置

    sf::RectangleShape tube1(sf::Vector2f(100.f, 900.f));                               // 管子1
    tube1.setFillColor(sf::Color::Green);                                               // 顏色為綠色
    tube1.setPosition(600.f, distrib(gen) - window.getSize().y);                        // 設定初始位置

    sf::RectangleShape tube2(sf::Vector2f(100.f, 900.f));                               // 管子2
    tube2.setFillColor(sf::Color::Green);                                               // 顏色為綠色
    tube2.setPosition(600.f, tube1.getPosition().y + window.getSize().y + CaveSize);    // 設定初始位置

    sf::RectangleShape tube3(sf::Vector2f(100.f, 900.f));                               // 管子3
    tube3.setFillColor(sf::Color::Green);                                               // 顏色為綠色
    tube3.setPosition(950.f, distrib(gen) - window.getSize().y);                        // 設定初始位置

    sf::RectangleShape tube4(sf::Vector2f(100.f, 900.f));                               // 管子4
    tube4.setFillColor(sf::Color::Green);                                               // 顏色為綠色
    tube4.setPosition(950.f, tube3.getPosition().y + window.getSize().y + CaveSize);    // 設定初始位置

    // 球的速度與管子速度
    sf::Vector2f birdSpeed(0.f, 300.f);          // 鳥的初速為每幀向下0.2個像素
    sf::Vector2f tube1Speed(-300.f, 0.f);        // 管子的初速為每幀向左0.2個像素
    sf::Vector2f tube2Speed(-300.f, 0.f);
    sf::Vector2f tube3Speed(-300.f, 0.f);
    sf::Vector2f tube4Speed(-300.f, 0.f);
    sf::Clock clock;

    // 遊戲主循環
    while (window.isOpen()) 
    {
        float dt = clock.restart().asSeconds();         //紀錄每幀有多少秒

        // 處理事件
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 更新遊戲邏輯&算出每幀應該怎麼根據"秒"而移動
        bird.move(birdSpeed * dt);
        tube1.move(tube1Speed * dt);
        tube2.move(tube2Speed * dt);
        tube3.move(tube3Speed * dt);
        tube4.move(tube4Speed * dt);

        // 檢查鳥是否出界（上下）
        if (bird.getPosition().y <= 0 || bird.getPosition().y >= 900 - bird.getRadius() * 2) 
        {
            Count = 0;                                                                          //將計數器重整
            std::cout << "0" << std::endl;
            tube1.setPosition(600.f, distrib(gen) - window.getSize().y);
            tube2.setPosition(600.f, tube1.getPosition().y + window.getSize().y + CaveSize);
            tube3.setPosition(950.f, distrib(gen) - window.getSize().y);
            tube4.setPosition(950.f, tube3.getPosition().y + window.getSize().y + CaveSize);
            bird.setPosition(100.f, 450.f);                                                     // 全部物件回到初始位置
        }

        // 檢查鳥是否碰到水管
        if (bird.getGlobalBounds().intersects(tube1.getGlobalBounds()) || bird.getGlobalBounds().intersects(tube2.getGlobalBounds()) || bird.getGlobalBounds().intersects(tube3.getGlobalBounds()) || bird.getGlobalBounds().intersects(tube4.getGlobalBounds()))
        {
            Count = 0;                                                                          //將計數器歸零
            std::cout << "0" <<std::endl;
            tube1.setPosition(600.f, distrib(gen) - window.getSize().y);
            tube2.setPosition(600.f, tube1.getPosition().y + window.getSize().y + CaveSize);
            tube3.setPosition(950.f, distrib(gen) - window.getSize().y);
            tube4.setPosition(950.f, tube3.getPosition().y + window.getSize().y + CaveSize);    
            bird.setPosition(100.f, 450.f);                                                     // 全部物件回到初始位置
        }
        
        // 避免玩家在長按Space鍵時鳥會直接飛到最頂導致遊戲結束
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && space)          // 這幀沒有按下Space鍵且上一幀有按下Space鍵
        {
            space = false;      // 記錄：這幀沒有按下Space鍵
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !space)          // 這幀有按下Space鍵且上一幀沒有按下Space鍵
        {
            bird.setPosition(bird.getPosition().x, bird.getPosition().y - 100); // 將鳥的位置向上100的像素
            space = true;       // 記錄：這幀有按下Space鍵
        }

        // 讓管子循環出現
        if (tube1.getPosition().x <= -100)                                      // 當一號管子完全離開視窗的左方邊界時
        {
            tube1.setPosition(600.f, distrib(gen) - window.getSize().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
            tube2.setPosition(600.f, tube1.getPosition().y + window.getSize().y + CaveSize);    //將二號管子傳送至右方的視窗邊界外, 高度為一號管子正下方
        }

        if (tube3.getPosition().x <= -100)                                      // 當三號管子完全離開視窗的左方邊界時
        {
            tube3.setPosition(600.f, distrib(gen) - window.getSize().y);                        //將三號管子傳送至右方的視窗邊界外, 隨機高度
            tube4.setPosition(600.f, tube3.getPosition().y + window.getSize().y + CaveSize);    //將四號管子傳送至右方的視窗邊界外, 高度為一號管子正下方
        }

        // 紀錄、輸出分數
        if ((tube1.getPosition().x <= 0 || tube3.getPosition().x <= 0) && !countornot)           // 當管子的x座標小於0時(最小到達-100，每幀0.2向左像素)
        {
            countornot = true;
            Count++;
            std::cout << Count << std::endl;
        }

        if (!(tube1.getPosition().x <= 0 || tube3.getPosition().x <= 0))          // 當管子的x座標小於0時(最小到達-100，每幀0.2向左像素)
        {
            countornot = false;
        }

        // 清除上一幀
        window.clear();

        // 繪製遊戲物件
        window.draw(bird);
        window.draw(tube1);
        window.draw(tube2);
        window.draw(tube3);
        window.draw(tube4);

        // 顯示新的幀
        window.display();
    }

    return 0;
}