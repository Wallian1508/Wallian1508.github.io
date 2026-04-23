#include <iostream>
#include <conio.h> // Windows 特有標頭檔
#include <windows.h> // 用於 Sleep
#include <random>
using namespace std;

void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() 
{
    int side = 4;//<=16
    cout<< "PLEASE MAKE SURE YOUR WINDOWS CAN DISPLAY ALL THE THING!!!" <<endl;
    cout << "enter the side\n(MAX = 16):";
    cin>> side;
    gotoxy(0, 0);
    cout<< "                                                          \n              \n                     " <<flush;
    
    gotoxy(0, 0);
    for(int i = 0; i < side * 2; i++)
    {
        for(int j = 0; j < side; j++)
            cout<< "       " << flush;
        cout<< "|\n" <<flush;
    }
    for(int i = 0; i < side; i++)
        cout<< "-------" <<flush;
    cout<< "|\n" <<endl;
    cout<< "Use [arrow keys] to play\n[R] for reset\n[B] for reset the side\n[backsapce] for exit\nPLEASE MAKE SURE YOUR WINDOWS CAN DISPLAY ALL THE THING!!!" <<endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> loc(0, side * side - 1);
    uniform_int_distribution<> tf(0, 9);
    int data[16][16]; // MAX
    bool end = 0;
    for(int i = 0; i < side; i++)
    {
        for(int j = 0; j < side; j++)
        {
            data[i][j] = 0;
        }
    }

    int loca = loc(gen);
    int num = tf(gen);

    if(num == 0)
        num = 4;
    else
        num = 2;

    data[loca / side][loca % side] = num;

    bool f = false;
    while(!f)
    {
        loca = loc(gen);
        num = tf(gen);

        if(num == 0)
            num = 4;
        else
            num = 2;

        if(data[loca / side][loca % side] == 0)
        {
            data[loca / side][loca % side] = num;
            f = true;
        }
    }

    gotoxy(0, 0);
    
    for(int i = 0; i < side; i++)
    {
        for(int j = 0; j < side; j++)
        {
            if(data[i][j] == 0)
                cout<< "     " << flush;
            else if(data[i][j] < 10)
                cout<< "    " << data[i][j] <<flush;
            else if(data[i][j] / 10 < 10)
                cout<< "   " << data[i][j] <<flush;
            else if(data[i][j] / 100 < 10)
                cout<< "  " << data[i][j] <<flush;
            else if(data[i][j] / 1000 < 10)
                cout<< " " << data[i][j] <<flush;
            else
                cout<< data[i][j] <<flush;
            cout<< "  " <<flush;
        }
        cout<< "\n\n" <<flush;
    }

    while(true)
    {
        // 檢查是否有按鍵輸入
        if(_kbhit()) {
            char in = _getch(); // 取得按下的字元
            if(in == 8) 
                break; // 退出條件
            
            if(in == 'r' || in == 'R')
            {
                end = 0;
                if(side % 2)
                    gotoxy(0, side - 2);
                else
                    gotoxy(0, side - 1);

                for(int i = 0; i < side; i++)
                    cout<< "       " <<flush;

                cout<< "|\n\n" << flush;
                for(int i = 0; i < side; i++)
                    cout<< "       " <<flush;

                cout<< "|" << flush;

                for(int i = 0; i < side; i++)
                {
                    for(int j = 0; j < side; j++)
                    {
                        data[i][j] = 0;
                    }
                }

                loca = loc(gen);
                num = tf(gen);

                if(num == 0)
                    num = 4;
                else
                    num = 2;

                data[loca / side][loca % side] = num;

                f = false;
                while(!f)
                {
                    loca = loc(gen);
                    num = tf(gen);

                    if(num == 0)
                        num = 4;
                    else
                        num = 2;

                    if(data[loca / side][loca % side] == 0)
                    {
                        data[loca / side][loca % side] = num;
                        f = true;
                    }
                }
                gotoxy(0, 0);
                for(int i = 0; i < side; i++)
                {
                    for(int j = 0; j < side; j++)
                    {
                        if(data[i][j] == 0)
                            cout<< "      " << flush;
                        else if(data[i][j] < 10)
                            cout<< "     " << data[i][j] <<flush;
                        else if(data[i][j] / 10 < 10)
                            cout<< "    " << data[i][j] <<flush;
                        else if(data[i][j] / 100 < 10)
                            cout<< "   " << data[i][j] <<flush;
                        else if(data[i][j] / 1000 < 10)
                            cout<< "  " << data[i][j] <<flush;
                        else if(data[i][j] / 10000 < 10)
                            cout<< " " << data[i][j] <<flush;
                        else
                            cout<< data[i][j] <<flush;
                        cout<< " " <<flush;
                    }
                    cout<< "\n\n" <<flush;
                }
            }

            if(in == 'b' || in == 'B')
            {
                gotoxy(0, 0);
                for(int i = 0; i < 38; i++)
                {
                    for(int j = 0; j < 16; j++)
                    {
                        cout<< "       " <<flush;
                    }
                    cout<< " \n" <<flush;
                }
                cout<< "                                                          " <<flush;

                gotoxy(0, 0);
                cout<< "PLEASE MAKE SURE YOUR WINDOWS CAN DISPLAY ALL THE THING!!!" <<endl;
                cout << "enter the side\n(MAX = 16):";
                cin>> side;
                gotoxy(0, 0);
                cout<< "                                                          \n              \n                     " <<flush;

                gotoxy(0, 0);
                for(int i = 0; i < side * 2; i++)
                {
                    for(int j = 0; j < side; j++)
                        cout<< "       " << flush;
                    cout<< "|\n" <<flush;
                }
                for(int i = 0; i < side; i++)
                    cout<< "-------" <<flush;
                cout<< "|\n" <<endl;
                cout<< "Use [arrow keys] to play\n[R] for reset\n[B] for reset the side\n[backsapce] for exit\nPLEASE MAKE SURE YOUR WINDOWS CAN DISPLAY ALL THE THING!!!" <<endl;
                end = 0;
                if(side % 2)
                    gotoxy(0, side - 2);
                else
                    gotoxy(0, side - 1);

                for(int i = 0; i < side; i++)
                    cout<< "       " <<flush;

                cout<< "|\n\n" << flush;
                for(int i = 0; i < side; i++)
                    cout<< "       " <<flush;

                cout<< "|" << flush;

                for(int i = 0; i < side; i++)
                {
                    for(int j = 0; j < side; j++)
                    {
                        data[i][j] = 0;
                    }
                }

                loca = loc(gen);
                num = tf(gen);

                if(num == 0)
                    num = 4;
                else
                    num = 2;

                data[loca / side][loca % side] = num;

                f = false;
                while(!f)
                {
                    loca = loc(gen);
                    num = tf(gen);

                    if(num == 0)
                        num = 4;
                    else
                        num = 2;

                    if(data[loca / side][loca % side] == 0)
                    {
                        data[loca / side][loca % side] = num;
                        f = true;
                    }
                }
                gotoxy(0, 0);
                for(int i = 0; i < side; i++)
                {
                    for(int j = 0; j < side; j++)
                    {
                        if(data[i][j] == 0)
                            cout<< "      " << flush;
                        else if(data[i][j] < 10)
                            cout<< "     " << data[i][j] <<flush;
                        else if(data[i][j] / 10 < 10)
                            cout<< "    " << data[i][j] <<flush;
                        else if(data[i][j] / 100 < 10)
                            cout<< "   " << data[i][j] <<flush;
                        else if(data[i][j] / 1000 < 10)
                            cout<< "  " << data[i][j] <<flush;
                        else if(data[i][j] / 10000 < 10)
                            cout<< " " << data[i][j] <<flush;
                        else
                            cout<< data[i][j] <<flush;
                        cout<< " " <<flush;
                    }
                    cout<< "\n\n" <<flush;
                }
            }

            f = true;
            if(in == 72)//Up
            {
                f = true;
                for(int k = 0; k < side - 1; k++)
                {
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = 1; j < side; j++)
                        {
                            if(data[j - 1][i] == 0 && data[j][i] != 0)
                            {
                                data[j - 1][i] = data[j][i];
                                data[j][i] = 0;
                                f = false;
                            }
                        }
                    }
                }

                for(int i = 0; i < side; i++)
                {
                    for(int j = 1; j < side; j++)
                    {
                        if(data[j - 1][i] == data[j][i] && data[j][i] != 0)
                        {
                            data[j - 1][i] *= 2;
                            data[j][i] = 0;
                            f = false;
                        }
                    }
                }

                for(int k = 0; k < side - 1; k++)
                {
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = 1; j < side; j++)
                        {
                            if(data[j - 1][i] == 0 && data[j][i] != 0)
                            {
                                data[j - 1][i] = data[j][i];
                                data[j][i] = 0;
                                f = false;
                            }
                        }
                    }
                }
            }
            else if(in == 80)//Down
            {
                f = true;
                for(int k = 0; k < side - 1; k++)
                {
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = side - 2; j >= 0; j--)
                        {
                            if(data[j + 1][i] == 0 && data[j][i] != 0)
                            {
                                data[j + 1][i] = data[j][i];
                                data[j][i] = 0;
                                f = false;
                            }
                        }
                    }
                }

                for(int i = 0; i < side; i++)
                {
                    for(int j = side - 2; j >= 0; j--)
                    {
                        if(data[j + 1][i] == data[j][i] && data[j][i] != 0)
                        {
                            data[j + 1][i] *= 2;
                            data[j][i] = 0;
                            f = false;
                        }
                    }
                }

                for(int k = 0; k < side - 1; k++)
                {
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = side - 2; j >= 0; j--)
                        {
                            if(data[j + 1][i] == 0 && data[j][i] != 0)
                            {
                                data[j + 1][i] = data[j][i];
                                data[j][i] = 0;
                                f = false;
                            }
                        }
                    }
                }
            }
            else if(in == 75)//Left
            {
                f = true;
                for(int k = 0; k < side - 1; k++)
                {
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = 1; j < side; j++)
                        {
                            if(data[i][j - 1] == 0 && data[i][j] != 0)
                            {
                                data[i][j - 1] = data[i][j];
                                data[i][j] = 0;
                                f = false;
                            }
                        }
                    }
                }

                for(int i = 0; i < side; i++)
                {
                    for(int j = 1; j < side; j++)
                    {
                        if(data[i][j - 1] == data[i][j] && data[i][j] != 0)
                        {
                            data[i][j - 1] *= 2;
                            data[i][j] = 0;
                            f = false;
                        }
                    }
                }

                for(int k = 0; k < side - 1; k++)
                {
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = 1; j < side; j++)
                        {
                            if(data[i][j - 1] == 0 && data[i][j] != 0)
                            {
                                data[i][j - 1] = data[i][j];
                                data[i][j] = 0;
                                f = false;
                            }
                        }
                    }
                }
            }
            else if(in == 77)//Right
            {
                f = true;
                for(int k = 0; k < side - 1; k++)
                {
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = side - 2; j >= 0; j--)
                        {
                            if(data[i][j + 1] == 0 && data[i][j] != 0)
                            {
                                data[i][j + 1] = data[i][j];
                                data[i][j] = 0;
                                f = false;
                            }
                        }
                    }
                }

                for(int i = 0; i < side; i++)
                {
                    for(int j = side - 2; j >= 0; j--)
                    {
                        if(data[i][j + 1] == data[i][j] && data[i][j] != 0)
                        {
                            data[i][j + 1] *= 2;
                            data[i][j] = 0;
                            f = false;
                        }
                    }
                }

                for(int k = 0; k < side - 1; k++)
                {
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = side - 2; j >= 0; j--)
                        {
                            if(data[i][j + 1] == 0 && data[i][j] != 0)
                            {
                                data[i][j + 1] = data[i][j];
                                data[i][j] = 0;
                                f = false;
                            }
                        }
                    }
                }
            }
            
            bool have0 = 0, move = 1;

            for(int i = 0; i < side && !have0; i++)
            {
                for(int j = 0; j < side && !have0; j++)
                {
                    if(data[i][j] == 0)
                        have0 = 1;
                }
            }

            for(int k = 0; k < side && move; k++)
            {
                for(int l = 0; l < side - 1 && move; l++)
                {
                    if(data[k][l] == data[k][l + 1] || data[l][k] == data[l + 1][k])
                    {
                        move = 0;
                    }
                }
            }

            if(!have0 && move && !end)
            {
                end = 1;
                if(side % 2)
                {
                    gotoxy(((7 * side) - 18) / 2, side - 2);
                    cout<< "     GAME OVER    \n" << endl;
                    gotoxy(((7 * side) - 18) / 2, side);
                    cout<< "press [R] to Reset" << endl;
                }
                else
                {
                    gotoxy(((7 * side) - 18) / 2, side - 1);
                    cout<< "     GAME OVER    \n" << endl;
                    gotoxy(((7 * side) - 18) / 2, side + 1);
                    cout<< "press [R] to Reset" << endl;
                }
            }

            while(!f)
            {
                loca = loc(gen);
                num = tf(gen);

                if(num)
                    num = 2;
                else
                    num = 4;

                if(data[loca / side][loca % side] == 0)
                {
                    data[loca / side][loca % side] = num;
                    
                    gotoxy(0, 0);
                    for(int i = 0; i < side; i++)
                    {
                        for(int j = 0; j < side; j++)
                        {
                            if(data[i][j] == 0)
                                cout<< "      " << flush;
                            else if(data[i][j] < 10)
                                cout<< "     " << data[i][j] <<flush;
                            else if(data[i][j] / 10 < 10)
                                cout<< "    " << data[i][j] <<flush;
                            else if(data[i][j] / 100 < 10)
                                cout<< "   " << data[i][j] <<flush;
                            else if(data[i][j] / 1000 < 10)
                                cout<< "  " << data[i][j] <<flush;
                            else if(data[i][j] / 10000 < 10)
                                cout<< " " << data[i][j] <<flush;
                            else
                                cout<< data[i][j] <<flush;
                            cout<< " " <<flush;
                        }
                        cout<< "\n\n" <<flush;
                    }
                    f = true;
                }
            }
        }

        Sleep(16); 
    }

    return 0;
}