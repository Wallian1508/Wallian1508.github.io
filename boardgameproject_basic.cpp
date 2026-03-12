#include <iostream>
#include <vector>
using namespace std;

vector<string> A(vector<string> now, int x, int y, int g)       //檢查A能不能放入
{
    if(g == 1 && y > 0 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y - 1] == '0'))  //7
    {
        now[x][y] = 'A';
        now[x - 1][y] = 'A';
        now[x - 2][y] = 'A';
        now[x - 2][y - 1] = 'A';    //放入
        return now;      //回傳
    }
    else if(g == 2 && y < 10 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y + 1] == '0'))  //F
    {
        now[x][y] = 'A';
        now[x - 1][y] = 'A';
        now[x - 2][y] = 'A';
        now[x - 2][y + 1] = 'A';
        return now;
    }
    else if(g == 3 && y > 0 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y - 1] == '0'))  //J
    {
        now[x][y] = 'A';
        now[x + 1][y] = 'A';
        now[x + 2][y] = 'A';
        now[x + 2][y - 1] = 'A';
        return now;
    }
    else if(g == 4 && y < 10 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y + 1] == '0'))  //L
    {
        now[x][y] = 'A';
        now[x + 1][y] = 'A';
        now[x + 2][y] = 'A';
        now[x + 2][y + 1] = 'A';
        return now;
    }
    else if(g == 5 && y > 1 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 1][y - 2] == '0'))  //7~
    {
        now[x][y] = 'A';
        now[x + 1][y] = 'A';
        now[x + 1][y - 1] = 'A';
        now[x + 1][y - 2] = 'A';
        return now;
    }
    else if(g == 6 && y > 1 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 1][y - 2] == '0'))  //F~
    {
        now[x][y] = 'A';
        now[x - 1][y] = 'A';
        now[x - 1][y - 1] = 'A';
        now[x - 1][y - 2] = 'A';
        return now;
    }
    else if(g == 7 && y < 9 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 1][y + 2] == '0'))  //J~
    {
        now[x][y] = 'A';
        now[x + 1][y] = 'A';
        now[x + 1][y + 1] = 'A';
        now[x + 1][y + 2] = 'A';
        return now;
    }
    else if(g == 8 && y < 9 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0' && now[x - 1][y + 2] == '0'))  //L~
    {
        now[x][y] = 'A';
        now[x - 1][y] = 'A';
        now[x - 1][y + 1] = 'A';
        now[x - 1][y + 2] = 'A';
        return now;
    }
    else//紀錄不能放入
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> B(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y > 0 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y - 1] == '0' && now[x - 1][y - 1] == '0'))  //7
    {
        now[x][y] = 'B';
        now[x - 1][y] = 'B';
        now[x - 2][y] = 'B';
        now[x - 1][y - 1] = 'B';
        now[x - 2][y - 1] = 'B';
        return now;
    }
    else if(g == 2 && y < 10 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y + 1] == '0' && now[x - 1][y + 1] == '0'))  //F
    {
        now[x][y] = 'B';
        now[x - 1][y] = 'B';
        now[x - 2][y] = 'B';
        now[x - 1][y + 1] = 'B';
        now[x - 2][y + 1] = 'B';
        return now;
    }
    else if(g == 3 && y > 0 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y - 1] == '0' && now[x + 1][y - 1] == '0'))  //J
    {
        now[x][y] = 'B';
        now[x + 1][y] = 'B';
        now[x + 2][y] = 'B';
        now[x + 1][y - 1] = 'B';
        now[x + 2][y - 1] = 'B';
        return now;
    }
    else if(g == 4 && y < 10 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y + 1] == '0' && now[x + 1][y + 1] == '0'))  //L
    {
        now[x][y] = 'B';
        now[x + 1][y] = 'B';
        now[x + 2][y] = 'B';
        now[x + 1][y + 1] = 'B';
        now[x + 2][y + 1] = 'B';
        return now;
    }
    else if(g == 5 && y > 1 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 1][y - 2] == '0' && now[x][y - 1] == '0'))  //7~
    {
        now[x][y] = 'B';
        now[x][y - 1] = 'B';
        now[x + 1][y] = 'B';
        now[x + 1][y - 1] = 'B';
        now[x + 1][y - 2] = 'B';
        return now;
    }
    else if(g == 6 && y > 1 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 1][y - 2] == '0' && now[x][y - 1] == '0'))  //F~
    {
        now[x][y] = 'B';
        now[x][y - 1] = 'B';
        now[x - 1][y] = 'B';
        now[x - 1][y - 1] = 'B';
        now[x - 1][y - 2] = 'B';
        return now;
    }
    else if(g == 7 && y < 9 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 1][y + 2] == '0' && now[x][y + 1] == '0'))  //J~
    {
        now[x][y] = 'B';
        now[x][y + 1] = 'B';
        now[x + 1][y] = 'B';
        now[x + 1][y + 1] = 'B';
        now[x + 1][y + 2] = 'B';
        return now;
    }
    else if(g == 8 && y < 9 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0' && now[x - 1][y + 2] == '0' && now[x][y + 1] == '0'))  //L~
    {
        now[x][y] = 'B';
        now[x][y + 1] = 'B';
        now[x - 1][y] = 'B';
        now[x - 1][y + 1] = 'B';
        now[x - 1][y + 2] = 'B';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> C(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y > 0 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y] == '0' && now[x - 3][y - 1] == '0'))  //7
    {
        now[x][y] = 'C';
        now[x - 1][y] = 'C';
        now[x - 2][y] = 'C';
        now[x - 3][y] = 'C';
        now[x - 3][y - 1] = 'C';
        return now;
    }
    else if(g == 2 && y < 10 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y] == '0' && now[x - 3][y + 1] == '0'))  //F
    {
        now[x][y] = 'C';
        now[x - 1][y] = 'C';
        now[x - 2][y] = 'C';
        now[x - 3][y] = 'C';
        now[x - 3][y + 1] = 'C';
        return now;
    }
    else if(g == 3 && y > 0 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0' && now[x + 3][y - 1] == '0'))  //J
    {
        now[x][y] = 'C';
        now[x + 1][y] = 'C';
        now[x + 2][y] = 'C';
        now[x + 3][y] = 'C';
        now[x + 3][y - 1] = 'C';
        return now;
    }
    else if(g == 4 && y < 10 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0' && now[x + 3][y + 1] == '0'))  //L
    {
        now[x][y] = 'C';
        now[x + 1][y] = 'C';
        now[x + 2][y] = 'C';
        now[x + 3][y] = 'C';
        now[x + 3][y + 1] = 'C';
        return now;
    }
    else if(g == 5 && y > 2 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 1][y - 2] == '0' && now[x + 1][y - 3] == '0'))  //7~
    {
        now[x][y] = 'C';
        now[x + 1][y] = 'C';
        now[x + 1][y - 1] = 'C';
        now[x + 1][y - 2] = 'C';
        now[x + 1][y - 3] = 'C';
        return now;
    }
    else if(g == 6 && y > 2 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 1][y - 2] == '0' && now[x - 1][y - 3] == '0'))  //F~
    {
        now[x][y] = 'C';
        now[x - 1][y] = 'C';
        now[x - 1][y - 1] = 'C';
        now[x - 1][y - 2] = 'C';
        now[x - 1][y - 3] = 'C';
        return now;
    }
    else if(g == 7 && y < 8 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 1][y + 2] == '0' && now[x + 1][y + 3] == '0'))  //J~
    {
        now[x][y] = 'C';
        now[x + 1][y] = 'C';
        now[x + 1][y + 1] = 'C';
        now[x + 1][y + 2] = 'C';
        now[x + 1][y + 3] = 'C';
        return now;
    }
    else if(g == 8 && y < 8 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0' && now[x - 1][y + 2] == '0' && now[x - 1][y + 3] == '0'))  //L~
    {
        now[x][y] = 'C';
        now[x - 1][y] = 'C';
        now[x - 1][y + 1] = 'C';
        now[x - 1][y + 2] = 'C';
        now[x - 1][y + 3] = 'C';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> D(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y > 0 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y] == '0' && now[x - 2][y - 1] == '0'))  //7
    {
        now[x][y] = 'D';
        now[x - 1][y] = 'D';
        now[x - 2][y] = 'D';
        now[x - 3][y] = 'D';
        now[x - 2][y - 1] = 'D';
        return now;
    }
    else if(g == 2 && y < 10 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y] == '0' && now[x - 2][y + 1] == '0'))  //F
    {
        now[x][y] = 'D';
        now[x - 1][y] = 'D';
        now[x - 2][y] = 'D';
        now[x - 3][y] = 'D';
        now[x - 2][y + 1] = 'D';
        return now;
    }
    else if(g == 3 && y > 0 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0' && now[x + 2][y - 1] == '0'))  //J
    {
        now[x][y] = 'D';
        now[x + 1][y] = 'D';
        now[x + 2][y] = 'D';
        now[x + 3][y] = 'D';
        now[x + 2][y - 1] = 'D';
        return now;
    }
    else if(g == 4 && y < 10 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0' && now[x + 2][y + 1] == '0'))  //L
    {
        now[x][y] = 'D';
        now[x + 1][y] = 'D';
        now[x + 2][y] = 'D';
        now[x + 3][y] = 'D';
        now[x + 2][y + 1] = 'D';
        return now;
    }
    else if(g == 5 && y < 8 && x > 0 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x][y + 3] == '0' && now[x - 1][y + 2] == '0'))  //7~
    {
        now[x][y] = 'D';
        now[x][y + 1] = 'D';
        now[x][y + 2] = 'D';
        now[x][y + 3] = 'D';
        now[x - 1][y + 2] = 'D';
        return now;
    }
    else if(g == 6 && y < 8 && x < 4 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x][y + 3] == '0' && now[x + 1][y + 2] == '0'))  //F~
    {
        now[x][y] = 'D';
        now[x][y + 1] = 'D';
        now[x][y + 2] = 'D';
        now[x][y + 3] = 'D';
        now[x + 1][y + 2] = 'D';
        return now;
    }
    else if(g == 7 && y > 2 && x > 0 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x][y - 2] == '0' && now[x][y - 3] == '0' && now[x - 1][y - 2] == '0'))  //J~
    {
        now[x][y] = 'D';
        now[x][y - 1] = 'D';
        now[x][y - 2] = 'D';
        now[x][y - 3] = 'D';
        now[x - 1][y - 2] = 'D';
        return now;
    }
    else if(g == 8 && y > 2 && x < 4 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x][y - 2] == '0' && now[x][y - 3] == '0' && now[x + 1][y - 2] == '0'))  //L~
    {
        now[x][y] = 'D';
        now[x][y - 1] = 'D';
        now[x][y - 2] = 'D';
        now[x][y - 3] = 'D';
        now[x + 1][y - 2] = 'D';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> E(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y > 0 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y - 1] == '0' && now[x - 2][y - 1] == '0'))  //7
    {
        now[x][y] = 'E';
        now[x - 1][y] = 'E';
        now[x - 2][y] = 'E';
        now[x - 3][y - 1] = 'E';
        now[x - 2][y - 1] = 'E';
        return now;
    }
    else if(g == 2 && y < 10 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y + 1] == '0' && now[x - 2][y + 1] == '0'))  //F
    {
        now[x][y] = 'E';
        now[x - 1][y] = 'E';
        now[x - 2][y] = 'E';
        now[x - 3][y + 1] = 'E';
        now[x - 2][y + 1] = 'E';
        return now;
    }
    else if(g == 3 && y > 0 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y - 1] == '0' && now[x + 2][y - 1] == '0'))  //J
    {
        now[x][y] = 'E';
        now[x + 1][y] = 'E';
        now[x + 2][y] = 'E';
        now[x + 3][y - 1] = 'E';
        now[x + 2][y - 1] = 'E';
        return now;
    }
    else if(g == 4 && y < 10 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y + 1] == '0' && now[x + 2][y + 1] == '0'))  //L
    {
        now[x][y] = 'E';
        now[x + 1][y] = 'E';
        now[x + 2][y] = 'E';
        now[x + 3][y + 1] = 'E';
        now[x + 2][y + 1] = 'E';
        return now;
    }
    else if(g == 5 && y < 8 && x > 0 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x - 1][y + 3] == '0' && now[x - 1][y + 2] == '0'))  //7~
    {
        now[x][y] = 'E';
        now[x][y + 1] = 'E';
        now[x][y + 2] = 'E';
        now[x - 1][y + 3] = 'E';
        now[x - 1][y + 2] = 'E';
        return now;
    }
    else if(g == 6 && y < 8 && x < 4 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x + 1][y + 3] == '0' && now[x + 1][y + 2] == '0'))  //F~
    {
        now[x][y] = 'E';
        now[x][y + 1] = 'E';
        now[x][y + 2] = 'E';
        now[x + 1][y + 3] = 'E';
        now[x + 1][y + 2] = 'E';
        return now;
    }
    else if(g == 7 && y > 2 && x > 0 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x][y - 2] == '0' && now[x - 1][y - 3] == '0' && now[x - 1][y - 2] == '0'))  //J~
    {
        now[x][y] = 'E';
        now[x][y - 1] = 'E';
        now[x][y - 2] = 'E';
        now[x - 1][y - 3] = 'E';
        now[x - 1][y - 2] = 'E';
        return now;
    }
    else if(g == 8 && y > 2 && x < 4 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x][y - 2] == '0' && now[x + 1][y - 3] == '0' && now[x + 1][y - 2] == '0'))  //L~
    {
        now[x][y] = 'E';
        now[x][y - 1] = 'E';
        now[x][y - 2] = 'E';
        now[x + 1][y - 3] = 'E';
        now[x + 1][y - 2] = 'E';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> F(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y > 0 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0'))  //7
    {
        now[x][y] = 'F';
        now[x - 1][y] = 'F';
        now[x - 1][y - 1] = 'F';
        return now;
    }
    else if(g == 2 && y < 10 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0'))  //F
    {
        now[x][y] = 'F';
        now[x - 1][y] = 'F';
        now[x - 1][y + 1] = 'F';
        return now;
    }
    else if(g == 3 && y > 0 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0'))  //J
    {
        now[x][y] = 'F';
        now[x + 1][y] = 'F';
        now[x + 1][y - 1] = 'F';
        return now;
    }
    else if(g == 4 && y < 10 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0'))  //L
    {
        now[x][y] = 'F';
        now[x + 1][y] = 'F';
        now[x + 1][y + 1] = 'F';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> G(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y > 1 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y - 1] == '0' && now[x - 2][y - 2] == '0'))  //7
    {
        now[x][y] = 'G';
        now[x - 1][y] = 'G';
        now[x - 2][y] = 'G';
        now[x - 2][y - 1] = 'G';
        now[x - 2][y - 2] = 'G';
        return now;
    }
    else if(g == 2 && y < 9 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y + 1] == '0' && now[x - 2][y + 2] == '0'))  //F
    {
        now[x][y] = 'G';
        now[x - 1][y] = 'G';
        now[x - 2][y] = 'G';
        now[x - 2][y + 1] = 'G';
        now[x - 2][y + 2] = 'G';
        return now;
    }
    else if(g == 3 && y > 1 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y - 1] == '0' && now[x + 2][y - 2] == '0'))  //J
    {
        now[x][y] = 'G';
        now[x + 1][y] = 'G';
        now[x + 2][y] = 'G';
        now[x + 2][y - 1] = 'G';
        now[x + 2][y - 2] = 'G';
        return now;
    }
    else if(g == 4 && y < 9 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y + 1] == '0' && now[x + 2][y + 2] == '0'))  //L
    {
        now[x][y] = 'G';
        now[x + 1][y] = 'G';
        now[x + 2][y] = 'G';
        now[x + 2][y + 1] = 'G';
        now[x + 2][y + 2] = 'G';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> H(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y > 1 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 2][y - 1] == '0' && now[x - 2][y - 2] == '0'))  //7
    {
        now[x][y] = 'H';
        now[x - 1][y] = 'H';
        now[x - 1][y - 1] = 'H';
        now[x - 2][y - 1] = 'H';
        now[x - 2][y - 2] = 'H';
        return now;
    }
    else if(g == 2 && y < 9 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0' && now[x - 2][y + 1] == '0' && now[x - 2][y + 2] == '0'))  //F
    {
        now[x][y] = 'H';
        now[x - 1][y] = 'H';
        now[x - 1][y + 1] = 'H';
        now[x - 2][y + 1] = 'H';
        now[x - 2][y + 2] = 'H';
        return now;
    }
    else if(g == 3 && y > 1 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 2][y - 1] == '0' && now[x + 2][y - 2] == '0'))  //J
    {
        now[x][y] = 'H';
        now[x + 1][y] = 'H';
        now[x + 1][y - 1] = 'H';
        now[x + 2][y - 1] = 'H';
        now[x + 2][y - 2] = 'H';
        return now;
    }
    else if(g == 4 && y < 9 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 2][y + 1] == '0' && now[x + 2][y + 2] == '0'))  //L
    {
        now[x][y] = 'H';
        now[x + 1][y] = 'H';
        now[x + 1][y + 1] = 'H';
        now[x + 2][y + 1] = 'H';
        now[x + 2][y + 2] = 'H';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> I(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y < 10 && x > 1 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x - 1][y + 1] == '0' && now[x - 2][y + 1] == '0' && now[x - 2][y] == '0'))  //3
    {
        now[x][y] = 'I';
        now[x][y + 1] = 'I';
        now[x - 1][y + 1] = 'I';
        now[x - 2][y + 1] = 'I';
        now[x - 2][y] = 'I';
        return now;
    }
    else if(g == 2 && y > 0 && x > 1 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x - 1][y - 1] == '0' && now[x - 2][y - 1] == '0' && now[x - 2][y] == '0'))  //C
    {
        now[x][y] = 'I';
        now[x][y - 1] = 'I';
        now[x - 1][y - 1] = 'I';
        now[x - 2][y - 1] = 'I';
        now[x - 2][y] = 'I';
        return now;
    }
    else if(g == 3 && y > 1 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 1][y - 2] == '0' && now[x][y - 2] == '0'))  //U
    {
        now[x][y] = 'I';
        now[x + 1][y] = 'I';
        now[x + 1][y - 1] = 'I';
        now[x + 1][y - 2] = 'I';
        now[x][y - 2] = 'I';
        return now;
    }
    else if(g == 4 && y > 1 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 1][y - 2] == '0' && now[x][y - 2] == '0'))  //M
    {
        now[x][y] = 'I';
        now[x - 1][y] = 'I';
        now[x - 1][y - 1] = 'I';
        now[x - 1][y - 2] = 'I';
        now[x][y - 2] = 'I';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> J(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y >= 0 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0'))  //|
    {
        now[x][y] = 'J';
        now[x + 1][y] = 'J';
        now[x + 2][y] = 'J';
        now[x + 3][y] = 'J';
        return now;
    }
    else if(g == 2 && y < 8 && x >= 0 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x][y + 3] == '0'))  //-
    {
        now[x][y] = 'J';
        now[x][y + 1] = 'J';
        now[x][y + 2] = 'J';
        now[x][y + 3] = 'J';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> K(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y < 10 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x][y + 1] == '0' && now[x + 1][y + 1] == '0'))
    {
        now[x][y] = 'K';
        now[x + 1][y] = 'K';
        now[x][y + 1] = 'K';
        now[x + 1][y + 1] = 'K';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

vector<string> L(vector<string> now, int x, int y, int g)
{
    if(g == 1 && y > 0 && y < 10 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 1][y - 1] == '0' && now[x + 2][y] == '0'))
    {
        now[x][y] = 'L';
        now[x + 1][y] = 'L';
        now[x + 1][y + 1] = 'L';
        now[x + 1][y - 1] = 'L';
        now[x + 2][y] = 'L';
        return now;
    }
    else
    {
        now[0][0] = '-';
        return now;
    }
}

void dfs(vector<string>& data, vector<bool>& already, int a, vector<string> now)    //僅data會影響外面(&)
{
    int k = 0;

    while(a < 12 && already[a])     //跳過已經在棋盤上的拼圖
    {
        a++;
    }

    if(a > 11)  //全部都排上棋盤後
    {
        for(int i = 0; i < 5; i++)
        {
            data[i] = now[i];     //將數據存入data
        }
    }

    for(int i = 0; i < 13 && a < 12; i++)//X座標
    {
        for(int j = 0; j < 5; j++)  //Y座標
        {
            if(isalpha(now[j][i]))  //非空格
                continue;           //跳過
            
            if(a == 10 || a == 11)  //4對稱軸：KL
                k = 1;  //1種方向
            else if(a == 9)         //2對稱軸：J
                k = 2;  //2種方向
            else if(a >= 5 && a <= 8)//1對稱軸：FGHI
                k = 4;  //4種方向
            else                    //0對稱軸：ABCDE
                k = 8;  //8種方向
            
            for(int g = 1; g <= k && !isalpha(now[j][i]) ; g++) //方向
            {
                if(a == 0) //A
                {
                    if(A(now, j, i, g)[0][0] == '-')    //填不進去
                    {
                        continue;
                    }
                    else                                //填進去了
                    {
                        already[a] = 1;            //紀錄為A在棋盤上
                        dfs(data, already, a + 1, A(now, j, i, g)); //呼叫自己開始算下一個(a+1)
                        already[a] = 0;         //退出來後：紀錄為A不在棋盤上
                    }
                }
                else if(a == 1) //B
                {
                    if(B(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, B(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 2) //C
                {
                    if(C(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, C(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 3) //D
                {
                    if(D(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, D(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 4) //E
                {
                    if(E(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, E(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 5) //F
                {
                    if(F(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, F(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 6) //G
                {
                    if(G(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, G(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 7) //H
                {
                    if(H(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, H(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 8) //I
                {
                    if(I(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, I(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 9) //J
                {
                    if(J(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, J(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 10) //K
                {
                    if(K(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, K(now, j, i, g));
                        already[a] = 0;
                    }
                }
                else if(a == 11) //L
                {
                    if(L(now, j, i, g)[0][0] == '-')
                    {
                        continue;
                    }
                    else
                    {
                        already[a] = 1;
                        dfs(data, already, a + 1, L(now, j, i, g));
                        already[a] = 0;
                    }
                }
            }
        }
    }
    return; //回傳
}

int main()
{
    vector<string> data(5);  //初始數據 和 最後答案
    vector<bool>  already(12);  //紀錄是否在棋盤上
    int tmp;

    for(int i = 0; i < 5; i++)  //輸入
    {
        cin>> data[i];
    }

    for(int i = 0; i < 12; i++) //清空紀錄
    {
        already[i] = 0;
    }

    for(int j = 0; j < 13; j++)     //找出棋盤上已有的拼圖
    {
        for(int k = 0; k < 5; k++)
        {
            tmp = data[k][j];
            tmp -= 65;
            if(isalpha(data[k][j]) && tmp >= 0 && tmp < 12)
                already[tmp] = 1;
        }
    }


    dfs(data, already, 0, data);    //開始遞迴DFS求解

    cout<< "--------------\n";          //輸出分格線

    for(int i = 0; i < 5; i++)
    {
        cout<< data[i] <<endl;  //輸出答案
    }
    
    return 0;   //結束
}
