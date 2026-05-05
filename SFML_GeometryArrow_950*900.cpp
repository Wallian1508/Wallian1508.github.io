#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>
#include <cmath>

sf::Color hslToColor(float h, float s, float l) 
{
    // 確保數值在正常範圍內
    h = fmod(h, 360.0f);
    if (h < 0) h += 360.0f;
    s = std::max(0.0f, std::min(1.0f, s));
    l = std::max(0.0f, std::min(1.0f, l));

    float c = (1.0f - std::abs(2.0f * l - 1.0f)) * s;
    float x = c * (1.0f - std::abs(fmod(h / 60.0f, 2.0f) - 1.0f));
    float m = l - c / 2.0f;

    float r, g, b;
    if (h < 60) { r = c; g = x; b = 0; }
    else if (h < 120) { r = x; g = c; b = 0; }
    else if (h < 180) { r = 0; g = c; b = x; }
    else if (h < 240) { r = 0; g = x; b = c; }
    else if (h < 300) { r = x; g = 0; b = c; }
    else { r = c; g = 0; b = x; }

    return sf::Color(
        static_cast<sf::Uint8>((r + m) * 255),
        static_cast<sf::Uint8>((g + m) * 255),
        static_cast<sf::Uint8>((b + m) * 255)
    );
}

int main() 
{
    // 宣告變數
    bool space = false, countornot = false, upornot = false;
    int Count = 0;
    int CaveSize = 300;
    float color = 0;
    float gamemode = 0;   //>0

    while (true)
    {
        gamemode = 0;
        while (gamemode <= 0)
        {
            std::cout << "1 for easy, 2 for normal, >2 for more difficult--(can be float)" << std::endl;
            std::cout << "enter the game difficulty(>0):" << std::flush;
            std::cin >> gamemode;
        }

        // 創建遊戲窗口(600 * 900像素)
        sf::RenderWindow window(sf::VideoMode(950, 900), "GeometryArrow");

        window.setVerticalSyncEnabled(false);

        // 使用隨機設備來生成種子
        std::random_device rd;

        // 使用梅森旋轉演算法 (Mersenne Twister) 來生成隨機數
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> distrib(150, 550);

        // 創建鳥
        sf::RectangleShape bird(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        bird.setFillColor(sf::Color::White);
        bird.setPosition(100.f, 450.f);  // 初始位置

        sf::RectangleShape shadow0(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow1(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow2(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow3(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow4(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow5(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow6(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow7(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow8(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow9(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow10(sf::Vector2f(20.f, 20.f));  // 半徑為 10
        sf::RectangleShape shadow11(sf::Vector2f(20.f, 20.f));  // 半徑為 10

        shadow0.setFillColor(sf::Color::White);
        shadow1.setFillColor(sf::Color::White);
        shadow2.setFillColor(sf::Color::White);
        shadow3.setFillColor(sf::Color::White);
        shadow4.setFillColor(sf::Color::White);
        shadow5.setFillColor(sf::Color::White);
        shadow6.setFillColor(sf::Color::White);
        shadow7.setFillColor(sf::Color::White);
        shadow8.setFillColor(sf::Color::White);
        shadow9.setFillColor(sf::Color::White);
        shadow10.setFillColor(sf::Color::White);
        shadow11.setFillColor(sf::Color::White);

        shadow0.setPosition(-10.f, 340.f);  // 初始位置
        shadow1.setPosition(0.f, 350.f);  // 初始位置
        shadow2.setPosition(10.f, 360.f);  // 初始位置
        shadow3.setPosition(20.f, 370.f);  // 初始位置
        shadow4.setPosition(30.f, 380.f);  // 初始位置
        shadow5.setPosition(40.f, 390.f);  // 初始位置
        shadow6.setPosition(50.f, 400.f);  // 初始位置
        shadow7.setPosition(60.f, 410.f);  // 初始位置
        shadow8.setPosition(70.f, 420.f);  // 初始位置
        shadow9.setPosition(80.f, 430.f);  // 初始位置
        shadow10.setPosition(90.f, 440.f);  // 初始位置
        shadow11.setPosition(100.f, 450.f);  // 初始位置

        sf::RectangleShape tube1(sf::Vector2f(100.f, 900.f));                               // 管子1
        tube1.setFillColor(sf::Color::Blue);                                               // 顏色為綠色
        tube1.setPosition(1650.f, distrib(gen) - window.getSize().y);                        // 設定初始位置

        sf::RectangleShape tube2(sf::Vector2f(100.f, 900.f));                               // 管子2
        tube2.setFillColor(sf::Color::Blue);                                               // 顏色為綠色
        tube2.setPosition(1650.f, tube1.getPosition().y + window.getSize().y + CaveSize);    // 設定初始位置

        sf::RectangleShape tube3(sf::Vector2f(100.f, 900.f));                               // 管子3
        tube3.setFillColor(sf::Color::Blue);                                               // 顏色為綠色
        tube3.setPosition(950.f, distrib(gen) - window.getSize().y);                        // 設定初始位置

        sf::RectangleShape tube4(sf::Vector2f(100.f, 900.f));                               // 管子4
        tube4.setFillColor(sf::Color::Blue);                                               // 顏色為綠色
        tube4.setPosition(950.f, tube3.getPosition().y + window.getSize().y + CaveSize);    // 設定初始位置

        sf::RectangleShape tube5(sf::Vector2f(100.f, 900.f));                               // 管子3
        tube5.setFillColor(sf::Color::Blue);                                               // 顏色為綠色
        tube5.setPosition(1300.f, distrib(gen) - window.getSize().y);                        // 設定初始位置

        sf::RectangleShape tube6(sf::Vector2f(100.f, 900.f));                               // 管子4
        tube6.setFillColor(sf::Color::Blue);                                               // 顏色為綠色
        tube6.setPosition(1300.f, tube5.getPosition().y + window.getSize().y + CaveSize);    // 設定初始位置

        // 球的速度與管子速度
        sf::Vector2f birdSpeed(0.f, 300.f);          // 鳥的初速為每幀向下0.2個像素
        sf::Vector2f tubeSpeed(-300.f, 0.f);        // 管子的初速為每幀向左0.2個像素
        sf::Clock clock;

        // 遊戲主循環
        while (window.isOpen())
        {
            float dt = clock.restart().asSeconds();         //紀錄每幀有多少秒
            dt *= gamemode;

            // 處理事件
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // 更新遊戲邏輯&算出每幀應該怎麼根據"秒"而移動
            if (upornot)
                bird.move(birdSpeed * -dt);
            else
                bird.move(birdSpeed * dt);
            tube1.move(tubeSpeed * dt);
            tube2.move(tubeSpeed * dt);
            tube3.move(tubeSpeed * dt);
            tube4.move(tubeSpeed * dt);
            tube5.move(tubeSpeed * dt);
            tube6.move(tubeSpeed * dt);
            shadow0.move(tubeSpeed * dt);
            shadow1.move(tubeSpeed * dt);
            shadow2.move(tubeSpeed * dt);
            shadow3.move(tubeSpeed * dt);
            shadow4.move(tubeSpeed * dt);
            shadow5.move(tubeSpeed * dt);
            shadow6.move(tubeSpeed * dt);
            shadow7.move(tubeSpeed * dt);
            shadow8.move(tubeSpeed * dt);
            shadow9.move(tubeSpeed * dt);
            shadow10.move(tubeSpeed * dt);
            shadow11.move(tubeSpeed * dt);


            // 檢查鳥是否出界（上下）
            if (bird.getPosition().y <= 0 || bird.getPosition().y >= 900 - bird.getSize().y)
            {
                upornot = false;
                if (Count != 0)
                    std::cout << "0" << std::endl;
                Count = 0;                                                                          //將計數器重整
                tube1.setPosition(1650.f, distrib(gen) - window.getSize().y);
                tube2.setPosition(1650.f, tube1.getPosition().y + window.getSize().y + CaveSize);
                tube3.setPosition(950.f, distrib(gen) - window.getSize().y);
                tube4.setPosition(950.f, tube3.getPosition().y + window.getSize().y + CaveSize);
                tube5.setPosition(1300.f, distrib(gen) - window.getSize().y);
                tube6.setPosition(1300.f, tube5.getPosition().y + window.getSize().y + CaveSize);
                bird.setPosition(100.f, 450.f);                                                     // 全部物件回到初始位置
                shadow0.setPosition(-10.f, 340.f);  // 初始位置
                shadow1.setPosition(0.f, 350.f);  // 初始位置
                shadow2.setPosition(10.f, 360.f);  // 初始位置
                shadow3.setPosition(20.f, 370.f);  // 初始位置
                shadow4.setPosition(30.f, 380.f);  // 初始位置
                shadow5.setPosition(40.f, 390.f);  // 初始位置
                shadow6.setPosition(50.f, 400.f);  // 初始位置
                shadow7.setPosition(60.f, 410.f);  // 初始位置
                shadow8.setPosition(70.f, 420.f);  // 初始位置
                shadow9.setPosition(80.f, 430.f);  // 初始位置
                shadow10.setPosition(90.f, 440.f);  // 初始位置
                shadow11.setPosition(100.f, 450.f);  // 初始位置
            }

            // 檢查鳥是否碰到水管
            if (bird.getGlobalBounds().intersects(tube1.getGlobalBounds()) || bird.getGlobalBounds().intersects(tube2.getGlobalBounds()) || bird.getGlobalBounds().intersects(tube3.getGlobalBounds()) || bird.getGlobalBounds().intersects(tube4.getGlobalBounds()) || bird.getGlobalBounds().intersects(tube5.getGlobalBounds()) || bird.getGlobalBounds().intersects(tube6.getGlobalBounds()))
            {
                upornot = false;
                if (Count != 0)
                    std::cout << "0" << std::endl;
                Count = 0;                                                                          //將計數器歸零
                tube1.setPosition(1650.f, distrib(gen) - window.getSize().y);
                tube2.setPosition(1650.f, tube1.getPosition().y + window.getSize().y + CaveSize);
                tube3.setPosition(950.f, distrib(gen) - window.getSize().y);
                tube4.setPosition(950.f, tube3.getPosition().y + window.getSize().y + CaveSize);
                tube5.setPosition(1300.f, distrib(gen) - window.getSize().y);
                tube6.setPosition(1300.f, tube5.getPosition().y + window.getSize().y + CaveSize);
                bird.setPosition(100.f, 450.f);                                                     // 全部物件回到初始位置
                shadow0.setPosition(-10.f, 340.f);  // 初始位置
                shadow1.setPosition(0.f, 350.f);  // 初始位置
                shadow2.setPosition(10.f, 360.f);  // 初始位置
                shadow3.setPosition(20.f, 370.f);  // 初始位置
                shadow4.setPosition(30.f, 380.f);  // 初始位置
                shadow5.setPosition(40.f, 390.f);  // 初始位置
                shadow6.setPosition(50.f, 400.f);  // 初始位置
                shadow7.setPosition(60.f, 410.f);  // 初始位置
                shadow8.setPosition(70.f, 420.f);  // 初始位置
                shadow9.setPosition(80.f, 430.f);  // 初始位置
                shadow10.setPosition(90.f, 440.f);  // 初始位置
                shadow11.setPosition(100.f, 450.f);  // 初始位置
            }

            // 避免玩家在長按Space鍵時鳥會直接飛到最頂導致遊戲結束
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && space)          // 這幀沒有按下Space鍵且上一幀有按下Space鍵
            {
                space = false;      // 記錄：這幀沒有按下Space鍵
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !space)          // 這幀有按下Space鍵且上一幀沒有按下Space鍵
            {
                upornot ^= true;
                space = true;       // 記錄：這幀有按下Space鍵
            }

            // 讓管子循環出現
            if (tube1.getPosition().x <= -100)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                tube1.setPosition(950.f, distrib(gen) - window.getSize().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                tube2.setPosition(950.f, tube1.getPosition().y + window.getSize().y + CaveSize);    //將二號管子傳送至右方的視窗邊界外, 高度為一號管子正下方
            }

            if (tube3.getPosition().x <= -100)                                      // 當三號管子完全離開視窗的左方邊界時
            {
                tube3.setPosition(950.f, distrib(gen) - window.getSize().y);                        //將三號管子傳送至右方的視窗邊界外, 隨機高度
                tube4.setPosition(950.f, tube3.getPosition().y + window.getSize().y + CaveSize);    //將四號管子傳送至右方的視窗邊界外, 高度為一號管子正下方
            }

            if (tube5.getPosition().x <= -100)                                      // 當三號管子完全離開視窗的左方邊界時
            {
                tube5.setPosition(950.f, distrib(gen) - window.getSize().y);                        //將三號管子傳送至右方的視窗邊界外, 隨機高度
                tube6.setPosition(950.f, tube5.getPosition().y + window.getSize().y + CaveSize);    //將四號管子傳送至右方的視窗邊界外, 高度為一號管子正下方
            }

            // 讓影子循環出現
            if (shadow0.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow0.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow1.setPosition(-10.f, shadow1.getPosition().y);
                shadow2.setPosition(0.f, shadow2.getPosition().y);
                shadow3.setPosition(10.f, shadow3.getPosition().y);
                shadow4.setPosition(20.f, shadow4.getPosition().y);
                shadow5.setPosition(30.f, shadow5.getPosition().y);
                shadow6.setPosition(40.f, shadow6.getPosition().y);
                shadow7.setPosition(50.f, shadow7.getPosition().y);
                shadow8.setPosition(60.f, shadow8.getPosition().y);
                shadow9.setPosition(70.f, shadow9.getPosition().y);
                shadow10.setPosition(80.f, shadow10.getPosition().y);
                shadow11.setPosition(90.f, shadow11.getPosition().y);
            }

            if (shadow1.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow1.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow2.setPosition(-10.f, shadow2.getPosition().y);
                shadow3.setPosition(0.f, shadow3.getPosition().y);
                shadow4.setPosition(10.f, shadow4.getPosition().y);
                shadow5.setPosition(20.f, shadow5.getPosition().y);
                shadow6.setPosition(30.f, shadow6.getPosition().y);
                shadow7.setPosition(40.f, shadow7.getPosition().y);
                shadow8.setPosition(50.f, shadow8.getPosition().y);
                shadow9.setPosition(60.f, shadow9.getPosition().y);
                shadow10.setPosition(70.f, shadow10.getPosition().y);
                shadow11.setPosition(80.f, shadow11.getPosition().y);
                shadow0.setPosition(90.f, shadow0.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
            }

            if (shadow2.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow2.setPosition(100.f, bird.getPosition().y);
                shadow3.setPosition(-10.f, shadow3.getPosition().y);
                shadow4.setPosition(0.f, shadow4.getPosition().y);
                shadow5.setPosition(10.f, shadow5.getPosition().y);
                shadow6.setPosition(20.f, shadow6.getPosition().y);
                shadow7.setPosition(30.f, shadow7.getPosition().y);
                shadow8.setPosition(40.f, shadow8.getPosition().y);
                shadow9.setPosition(50.f, shadow9.getPosition().y);
                shadow10.setPosition(60.f, shadow10.getPosition().y);
                shadow11.setPosition(70.f, shadow11.getPosition().y);
                shadow0.setPosition(80.f, shadow0.getPosition().y);
                shadow1.setPosition(90.f, shadow1.getPosition().y);
            }

            if (shadow3.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow3.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow4.setPosition(-10.f, shadow4.getPosition().y);
                shadow5.setPosition(0.f, shadow5.getPosition().y);
                shadow6.setPosition(10.f, shadow6.getPosition().y);
                shadow7.setPosition(20.f, shadow7.getPosition().y);
                shadow8.setPosition(30.f, shadow8.getPosition().y);
                shadow9.setPosition(40.f, shadow9.getPosition().y);
                shadow10.setPosition(50.f, shadow10.getPosition().y);
                shadow11.setPosition(60.f, shadow11.getPosition().y);
                shadow0.setPosition(70.f, shadow0.getPosition().y);
                shadow1.setPosition(80.f, shadow1.getPosition().y);
                shadow2.setPosition(90.f, shadow2.getPosition().y);
            }

            if (shadow4.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow4.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow5.setPosition(-10.f, shadow5.getPosition().y);
                shadow6.setPosition(0.f, shadow6.getPosition().y);
                shadow7.setPosition(10.f, shadow7.getPosition().y);
                shadow8.setPosition(20.f, shadow8.getPosition().y);
                shadow9.setPosition(30.f, shadow9.getPosition().y);
                shadow10.setPosition(40.f, shadow10.getPosition().y);
                shadow11.setPosition(50.f, shadow11.getPosition().y);
                shadow0.setPosition(60.f, shadow0.getPosition().y);
                shadow1.setPosition(70.f, shadow1.getPosition().y);
                shadow2.setPosition(80.f, shadow2.getPosition().y);
                shadow3.setPosition(90.f, shadow3.getPosition().y);
            }

            if (shadow5.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow5.setPosition(100.f, bird.getPosition().y);
                shadow6.setPosition(-10.f, shadow6.getPosition().y);
                shadow7.setPosition(0.f, shadow7.getPosition().y);
                shadow8.setPosition(10.f, shadow8.getPosition().y);
                shadow9.setPosition(20.f, shadow9.getPosition().y);
                shadow10.setPosition(30.f, shadow10.getPosition().y);
                shadow11.setPosition(40.f, shadow11.getPosition().y);
                shadow0.setPosition(50.f, shadow0.getPosition().y);
                shadow1.setPosition(60.f, shadow1.getPosition().y);
                shadow2.setPosition(70.f, shadow2.getPosition().y);
                shadow3.setPosition(80.f, shadow3.getPosition().y);
                shadow4.setPosition(90.f, shadow4.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
            }

            if (shadow6.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow6.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow7.setPosition(-10.f, shadow7.getPosition().y);
                shadow8.setPosition(0.f, shadow8.getPosition().y);
                shadow9.setPosition(10.f, shadow9.getPosition().y);
                shadow10.setPosition(20.f, shadow10.getPosition().y);
                shadow11.setPosition(30.f, shadow11.getPosition().y);
                shadow0.setPosition(40.f, shadow0.getPosition().y);
                shadow1.setPosition(50.f, shadow1.getPosition().y);
                shadow2.setPosition(60.f, shadow2.getPosition().y);
                shadow3.setPosition(70.f, shadow3.getPosition().y);
                shadow4.setPosition(80.f, shadow4.getPosition().y);
                shadow5.setPosition(90.f, shadow5.getPosition().y);
            }

            if (shadow7.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow7.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow8.setPosition(-10.f, shadow8.getPosition().y);
                shadow9.setPosition(0.f, shadow9.getPosition().y);
                shadow10.setPosition(10.f, shadow10.getPosition().y);
                shadow11.setPosition(20.f, shadow11.getPosition().y);
                shadow0.setPosition(30.f, shadow0.getPosition().y);
                shadow1.setPosition(40.f, shadow1.getPosition().y);
                shadow2.setPosition(50.f, shadow2.getPosition().y);
                shadow3.setPosition(60.f, shadow3.getPosition().y);
                shadow4.setPosition(70.f, shadow4.getPosition().y);
                shadow5.setPosition(80.f, shadow5.getPosition().y);
                shadow6.setPosition(90.f, shadow6.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
            }

            if (shadow8.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow8.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow9.setPosition(-10.f, shadow9.getPosition().y);
                shadow10.setPosition(0.f, shadow10.getPosition().y);
                shadow11.setPosition(10.f, shadow11.getPosition().y);
                shadow0.setPosition(20.f, shadow0.getPosition().y);
                shadow1.setPosition(30.f, shadow1.getPosition().y);
                shadow2.setPosition(40.f, shadow2.getPosition().y);
                shadow3.setPosition(50.f, shadow3.getPosition().y);
                shadow4.setPosition(60.f, shadow4.getPosition().y);
                shadow5.setPosition(70.f, shadow5.getPosition().y);
                shadow6.setPosition(80.f, shadow6.getPosition().y);
                shadow7.setPosition(90.f, shadow7.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
            }

            if (shadow9.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow9.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow10.setPosition(-10.f, shadow10.getPosition().y);
                shadow11.setPosition(0.f, shadow11.getPosition().y);
                shadow0.setPosition(10.f, shadow0.getPosition().y);
                shadow1.setPosition(20.f, shadow1.getPosition().y);
                shadow2.setPosition(30.f, shadow2.getPosition().y);
                shadow3.setPosition(40.f, shadow3.getPosition().y);
                shadow4.setPosition(50.f, shadow4.getPosition().y);
                shadow5.setPosition(60.f, shadow5.getPosition().y);
                shadow6.setPosition(70.f, shadow6.getPosition().y);
                shadow7.setPosition(80.f, shadow7.getPosition().y);
                shadow8.setPosition(90.f, shadow8.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度

            }

            if (shadow10.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow10.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow11.setPosition(-10.f, shadow11.getPosition().y);
                shadow0.setPosition(0.f, shadow0.getPosition().y);
                shadow1.setPosition(10.f, shadow1.getPosition().y);
                shadow2.setPosition(20.f, shadow2.getPosition().y);
                shadow3.setPosition(30.f, shadow3.getPosition().y);
                shadow4.setPosition(40.f, shadow4.getPosition().y);
                shadow5.setPosition(50.f, shadow5.getPosition().y);
                shadow6.setPosition(60.f, shadow6.getPosition().y);
                shadow7.setPosition(70.f, shadow7.getPosition().y);
                shadow8.setPosition(80.f, shadow8.getPosition().y);
                shadow9.setPosition(90.f, shadow9.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
            }

            if (shadow11.getPosition().x <= -20)                                      // 當一號管子完全離開視窗的左方邊界時
            {
                shadow11.setPosition(100.f, bird.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
                shadow0.setPosition(-10.f, shadow0.getPosition().y);
                shadow1.setPosition(0.f, shadow1.getPosition().y);
                shadow2.setPosition(10.f, shadow2.getPosition().y);
                shadow3.setPosition(20.f, shadow3.getPosition().y);
                shadow4.setPosition(30.f, shadow4.getPosition().y);
                shadow5.setPosition(40.f, shadow5.getPosition().y);
                shadow6.setPosition(50.f, shadow6.getPosition().y);
                shadow7.setPosition(60.f, shadow7.getPosition().y);
                shadow8.setPosition(70.f, shadow8.getPosition().y);
                shadow9.setPosition(80.f, shadow9.getPosition().y);
                shadow10.setPosition(90.f, shadow10.getPosition().y);                        //將一號管子傳送至右方的視窗邊界外, 隨機高度
            }

            // 紀錄、輸出分數
            if ((tube1.getPosition().x <= 0 || tube3.getPosition().x <= 0 || tube5.getPosition().x <= 0) && !countornot)           // 當管子的x座標小於0時(最小到達-100，每幀0.2向左像素)
            {
                countornot = true;
                Count++;
                std::cout << Count << std::endl;
            }

            if (!(tube1.getPosition().x <= 0 || tube3.getPosition().x <= 0 || tube5.getPosition().x <= 0))          // 當管子的x座標小於0時(最小到達-100，每幀0.2向左像素)
            {
                countornot = false;
            }

            color += 0.015;
            if (color > 360)
                color -= 360;
            tube1.setFillColor(hslToColor(color, 1.0f, 0.5f));
            tube2.setFillColor(hslToColor(color, 1.0f, 0.5f));
            tube3.setFillColor(hslToColor(color, 1.0f, 0.5f));
            tube4.setFillColor(hslToColor(color, 1.0f, 0.5f));
            tube5.setFillColor(hslToColor(color, 1.0f, 0.5f));
            tube6.setFillColor(hslToColor(color, 1.0f, 0.5f));

            // 清除上一幀
            window.clear();

            // 繪製遊戲物件
            window.draw(bird);
            window.draw(tube1);
            window.draw(tube2);
            window.draw(tube3);
            window.draw(tube4);
            window.draw(tube5);
            window.draw(tube6);
            window.draw(shadow0);
            window.draw(shadow1);
            window.draw(shadow2);
            window.draw(shadow3);
            window.draw(shadow4);
            window.draw(shadow5);
            window.draw(shadow6);
            window.draw(shadow7);
            window.draw(shadow8);
            window.draw(shadow9);
            window.draw(shadow10);
            window.draw(shadow11);

            // 顯示新的幀
            window.display();
        }
    }
}
