import java.util.Scanner;

public class boardgameproject{
    public static char[][] A(char[][] now, int x, int y, int g)       //檢查A能不能放入
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }

        if(g == 1 && y > 0 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y - 1] == '0'))  //7
        {
            copy[x][y] = 'A';
            copy[x - 1][y] = 'A';
            copy[x - 2][y] = 'A';
            copy[x - 2][y - 1] = 'A';    //放入
            return copy;      //回傳
        }
        else if(g == 2 && y < 10 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y + 1] == '0'))  //F
        {
            copy[x][y] = 'A';
            copy[x - 1][y] = 'A';
            copy[x - 2][y] = 'A';
            copy[x - 2][y + 1] = 'A';
            return copy;
        }
        else if(g == 3 && y > 0 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y - 1] == '0'))  //J
        {
            copy[x][y] = 'A';
            copy[x + 1][y] = 'A';
            copy[x + 2][y] = 'A';
            copy[x + 2][y - 1] = 'A';
            return copy;
        }
        else if(g == 4 && y < 10 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y + 1] == '0'))  //L
        {
            copy[x][y] = 'A';
            copy[x + 1][y] = 'A';
            copy[x + 2][y] = 'A';
            copy[x + 2][y + 1] = 'A';
            return copy;
        }
        else if(g == 5 && y > 1 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 1][y - 2] == '0'))  //7~
        {
            copy[x][y] = 'A';
            copy[x + 1][y] = 'A';
            copy[x + 1][y - 1] = 'A';
            copy[x + 1][y - 2] = 'A';
            return copy;
        }
        else if(g == 6 && y > 1 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 1][y - 2] == '0'))  //F~
        {
            copy[x][y] = 'A';
            copy[x - 1][y] = 'A';
            copy[x - 1][y - 1] = 'A';
            copy[x - 1][y - 2] = 'A';
            return copy;
        }
        else if(g == 7 && y < 9 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 1][y + 2] == '0'))  //J~
        {
            copy[x][y] = 'A';
            copy[x + 1][y] = 'A';
            copy[x + 1][y + 1] = 'A';
            copy[x + 1][y + 2] = 'A';
            return copy;
        }
        else if(g == 8 && y < 9 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0' && now[x - 1][y + 2] == '0'))  //L~
        {
            copy[x][y] = 'A';
            copy[x - 1][y] = 'A';
            copy[x - 1][y + 1] = 'A';
            copy[x - 1][y + 2] = 'A';
            return copy;
        }
        else//紀錄不能放入
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] B(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }

        if(g == 1 && y > 0 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y - 1] == '0' && now[x - 1][y - 1] == '0'))  //7
        {
            copy[x][y] = 'B';
            copy[x - 1][y] = 'B';
            copy[x - 2][y] = 'B';
            copy[x - 1][y - 1] = 'B';
            copy[x - 2][y - 1] = 'B';
            return copy;
        }
        else if(g == 2 && y < 10 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y + 1] == '0' && now[x - 1][y + 1] == '0'))  //F
        {
            copy[x][y] = 'B';
            copy[x - 1][y] = 'B';
            copy[x - 2][y] = 'B';
            copy[x - 1][y + 1] = 'B';
            copy[x - 2][y + 1] = 'B';
            return copy;
        }
        else if(g == 3 && y > 0 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y - 1] == '0' && now[x + 1][y - 1] == '0'))  //J
        {
            copy[x][y] = 'B';
            copy[x + 1][y] = 'B';
            copy[x + 2][y] = 'B';
            copy[x + 1][y - 1] = 'B';
            copy[x + 2][y - 1] = 'B';
            return copy;
        }
        else if(g == 4 && y < 10 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y + 1] == '0' && now[x + 1][y + 1] == '0'))  //L
        {
            copy[x][y] = 'B';
            copy[x + 1][y] = 'B';
            copy[x + 2][y] = 'B';
            copy[x + 1][y + 1] = 'B';
            copy[x + 2][y + 1] = 'B';
            return copy;
        }
        else if(g == 5 && y > 1 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 1][y - 2] == '0' && now[x][y - 1] == '0'))  //7~
        {
            copy[x][y] = 'B';
            copy[x][y - 1] = 'B';
            copy[x + 1][y] = 'B';
            copy[x + 1][y - 1] = 'B';
            copy[x + 1][y - 2] = 'B';
            return copy;
        }
        else if(g == 6 && y > 1 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 1][y - 2] == '0' && now[x][y - 1] == '0'))  //F~
        {
            copy[x][y] = 'B';
            copy[x][y - 1] = 'B';
            copy[x - 1][y] = 'B';
            copy[x - 1][y - 1] = 'B';
            copy[x - 1][y - 2] = 'B';
            return copy;
        }
        else if(g == 7 && y < 9 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 1][y + 2] == '0' && now[x][y + 1] == '0'))  //J~
        {
            copy[x][y] = 'B';
            copy[x][y + 1] = 'B';
            copy[x + 1][y] = 'B';
            copy[x + 1][y + 1] = 'B';
            copy[x + 1][y + 2] = 'B';
            return copy;
        }
        else if(g == 8 && y < 9 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0' && now[x - 1][y + 2] == '0' && now[x][y + 1] == '0'))  //L~
        {
            copy[x][y] = 'B';
            copy[x][y + 1] = 'B';
            copy[x - 1][y] = 'B';
            copy[x - 1][y + 1] = 'B';
            copy[x - 1][y + 2] = 'B';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] C(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y > 0 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y] == '0' && now[x - 3][y - 1] == '0'))  //7
        {
            copy[x][y] = 'C';
            copy[x - 1][y] = 'C';
            copy[x - 2][y] = 'C';
            copy[x - 3][y] = 'C';
            copy[x - 3][y - 1] = 'C';
            return copy;
        }
        else if(g == 2 && y < 10 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y] == '0' && now[x - 3][y + 1] == '0'))  //F
        {
            copy[x][y] = 'C';
            copy[x - 1][y] = 'C';
            copy[x - 2][y] = 'C';
            copy[x - 3][y] = 'C';
            copy[x - 3][y + 1] = 'C';
            return copy;
        }
        else if(g == 3 && y > 0 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0' && now[x + 3][y - 1] == '0'))  //J
        {
            copy[x][y] = 'C';
            copy[x + 1][y] = 'C';
            copy[x + 2][y] = 'C';
            copy[x + 3][y] = 'C';
            copy[x + 3][y - 1] = 'C';
            return copy;
        }
        else if(g == 4 && y < 10 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0' && now[x + 3][y + 1] == '0'))  //L
        {
            copy[x][y] = 'C';
            copy[x + 1][y] = 'C';
            copy[x + 2][y] = 'C';
            copy[x + 3][y] = 'C';
            copy[x + 3][y + 1] = 'C';
            return copy;
        }
        else if(g == 5 && y > 2 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 1][y - 2] == '0' && now[x + 1][y - 3] == '0'))  //7~
        {
            copy[x][y] = 'C';
            copy[x + 1][y] = 'C';
            copy[x + 1][y - 1] = 'C';
            copy[x + 1][y - 2] = 'C';
            copy[x + 1][y - 3] = 'C';
            return copy;
        }
        else if(g == 6 && y > 2 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 1][y - 2] == '0' && now[x - 1][y - 3] == '0'))  //F~
        {
            copy[x][y] = 'C';
            copy[x - 1][y] = 'C';
            copy[x - 1][y - 1] = 'C';
            copy[x - 1][y - 2] = 'C';
            copy[x - 1][y - 3] = 'C';
            return copy;
        }
        else if(g == 7 && y < 8 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 1][y + 2] == '0' && now[x + 1][y + 3] == '0'))  //J~
        {
            copy[x][y] = 'C';
            copy[x + 1][y] = 'C';
            copy[x + 1][y + 1] = 'C';
            copy[x + 1][y + 2] = 'C';
            copy[x + 1][y + 3] = 'C';
            return copy;
        }
        else if(g == 8 && y < 8 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0' && now[x - 1][y + 2] == '0' && now[x - 1][y + 3] == '0'))  //L~
        {
            copy[x][y] = 'C';
            copy[x - 1][y] = 'C';
            copy[x - 1][y + 1] = 'C';
            copy[x - 1][y + 2] = 'C';
            copy[x - 1][y + 3] = 'C';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] D(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y > 0 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y] == '0' && now[x - 2][y - 1] == '0'))  //7
        {
            copy[x][y] = 'D';
            copy[x - 1][y] = 'D';
            copy[x - 2][y] = 'D';
            copy[x - 3][y] = 'D';
            copy[x - 2][y - 1] = 'D';
            return copy;
        }
        else if(g == 2 && y < 10 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y] == '0' && now[x - 2][y + 1] == '0'))  //F
        {
            copy[x][y] = 'D';
            copy[x - 1][y] = 'D';
            copy[x - 2][y] = 'D';
            copy[x - 3][y] = 'D';
            copy[x - 2][y + 1] = 'D';
            return copy;
        }
        else if(g == 3 && y > 0 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0' && now[x + 2][y - 1] == '0'))  //J
        {
            copy[x][y] = 'D';
            copy[x + 1][y] = 'D';
            copy[x + 2][y] = 'D';
            copy[x + 3][y] = 'D';
            copy[x + 2][y - 1] = 'D';
            return copy;
        }
        else if(g == 4 && y < 10 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0' && now[x + 2][y + 1] == '0'))  //L
        {
            copy[x][y] = 'D';
            copy[x + 1][y] = 'D';
            copy[x + 2][y] = 'D';
            copy[x + 3][y] = 'D';
            copy[x + 2][y + 1] = 'D';
            return copy;
        }
        else if(g == 5 && y < 8 && x > 0 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x][y + 3] == '0' && now[x - 1][y + 2] == '0'))  //7~
        {
            copy[x][y] = 'D';
            copy[x][y + 1] = 'D';
            copy[x][y + 2] = 'D';
            copy[x][y + 3] = 'D';
            copy[x - 1][y + 2] = 'D';
            return copy;
        }
        else if(g == 6 && y < 8 && x < 4 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x][y + 3] == '0' && now[x + 1][y + 2] == '0'))  //F~
        {
            copy[x][y] = 'D';
            copy[x][y + 1] = 'D';
            copy[x][y + 2] = 'D';
            copy[x][y + 3] = 'D';
            copy[x + 1][y + 2] = 'D';
            return copy;
        }
        else if(g == 7 && y > 2 && x > 0 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x][y - 2] == '0' && now[x][y - 3] == '0' && now[x - 1][y - 2] == '0'))  //J~
        {
            copy[x][y] = 'D';
            copy[x][y - 1] = 'D';
            copy[x][y - 2] = 'D';
            copy[x][y - 3] = 'D';
            copy[x - 1][y - 2] = 'D';
            return copy;
        }
        else if(g == 8 && y > 2 && x < 4 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x][y - 2] == '0' && now[x][y - 3] == '0' && now[x + 1][y - 2] == '0'))  //L~
        {
            copy[x][y] = 'D';
            copy[x][y - 1] = 'D';
            copy[x][y - 2] = 'D';
            copy[x][y - 3] = 'D';
            copy[x + 1][y - 2] = 'D';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] E(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y > 0 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y - 1] == '0' && now[x - 2][y - 1] == '0'))  //7
        {
            copy[x][y] = 'E';
            copy[x - 1][y] = 'E';
            copy[x - 2][y] = 'E';
            copy[x - 3][y - 1] = 'E';
            copy[x - 2][y - 1] = 'E';
            return copy;
        }
        else if(g == 2 && y < 10 && x > 2 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 3][y + 1] == '0' && now[x - 2][y + 1] == '0'))  //F
        {
            copy[x][y] = 'E';
            copy[x - 1][y] = 'E';
            copy[x - 2][y] = 'E';
            copy[x - 3][y + 1] = 'E';
            copy[x - 2][y + 1] = 'E';
            return copy;
        }
        else if(g == 3 && y > 0 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y - 1] == '0' && now[x + 2][y - 1] == '0'))  //J
        {
            copy[x][y] = 'E';
            copy[x + 1][y] = 'E';
            copy[x + 2][y] = 'E';
            copy[x + 3][y - 1] = 'E';
            copy[x + 2][y - 1] = 'E';
            return copy;
        }
        else if(g == 4 && y < 10 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y + 1] == '0' && now[x + 2][y + 1] == '0'))  //L
        {
            copy[x][y] = 'E';
            copy[x + 1][y] = 'E';
            copy[x + 2][y] = 'E';
            copy[x + 3][y + 1] = 'E';
            copy[x + 2][y + 1] = 'E';
            return copy;
        }
        else if(g == 5 && y < 8 && x > 0 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x - 1][y + 3] == '0' && now[x - 1][y + 2] == '0'))  //7~
        {
            copy[x][y] = 'E';
            copy[x][y + 1] = 'E';
            copy[x][y + 2] = 'E';
            copy[x - 1][y + 3] = 'E';
            copy[x - 1][y + 2] = 'E';
            return copy;
        }
        else if(g == 6 && y < 8 && x < 4 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x + 1][y + 3] == '0' && now[x + 1][y + 2] == '0'))  //F~
        {
            copy[x][y] = 'E';
            copy[x][y + 1] = 'E';
            copy[x][y + 2] = 'E';
            copy[x + 1][y + 3] = 'E';
            copy[x + 1][y + 2] = 'E';
            return copy;
        }
        else if(g == 7 && y > 2 && x > 0 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x][y - 2] == '0' && now[x - 1][y - 3] == '0' && now[x - 1][y - 2] == '0'))  //J~
        {
            copy[x][y] = 'E';
            copy[x][y - 1] = 'E';
            copy[x][y - 2] = 'E';
            copy[x - 1][y - 3] = 'E';
            copy[x - 1][y - 2] = 'E';
            return copy;
        }
        else if(g == 8 && y > 2 && x < 4 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x][y - 2] == '0' && now[x + 1][y - 3] == '0' && now[x + 1][y - 2] == '0'))  //L~
        {
            copy[x][y] = 'E';
            copy[x][y - 1] = 'E';
            copy[x][y - 2] = 'E';
            copy[x + 1][y - 3] = 'E';
            copy[x + 1][y - 2] = 'E';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] F(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y > 0 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0'))  //7
        {
            copy[x][y] = 'F';
            copy[x - 1][y] = 'F';
            copy[x - 1][y - 1] = 'F';
            return copy;
        }
        else if(g == 2 && y < 10 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0'))  //F
        {
            copy[x][y] = 'F';
            copy[x - 1][y] = 'F';
            copy[x - 1][y + 1] = 'F';
            return copy;
        }
        else if(g == 3 && y > 0 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0'))  //J
        {
            copy[x][y] = 'F';
            copy[x + 1][y] = 'F';
            copy[x + 1][y - 1] = 'F';
            return copy;
        }
        else if(g == 4 && y < 10 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0'))  //L
        {
            copy[x][y] = 'F';
            copy[x + 1][y] = 'F';
            copy[x + 1][y + 1] = 'F';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] G(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y > 1 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y - 1] == '0' && now[x - 2][y - 2] == '0'))  //7
        {
            copy[x][y] = 'G';
            copy[x - 1][y] = 'G';
            copy[x - 2][y] = 'G';
            copy[x - 2][y - 1] = 'G';
            copy[x - 2][y - 2] = 'G';
            return copy;
        }
        else if(g == 2 && y < 9 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 2][y] == '0' && now[x - 2][y + 1] == '0' && now[x - 2][y + 2] == '0'))  //F
        {
            copy[x][y] = 'G';
            copy[x - 1][y] = 'G';
            copy[x - 2][y] = 'G';
            copy[x - 2][y + 1] = 'G';
            copy[x - 2][y + 2] = 'G';
            return copy;
        }
        else if(g == 3 && y > 1 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y - 1] == '0' && now[x + 2][y - 2] == '0'))  //J
        {
            copy[x][y] = 'G';
            copy[x + 1][y] = 'G';
            copy[x + 2][y] = 'G';
            copy[x + 2][y - 1] = 'G';
            copy[x + 2][y - 2] = 'G';
            return copy;
        }
        else if(g == 4 && y < 9 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 2][y + 1] == '0' && now[x + 2][y + 2] == '0'))  //L
        {
            copy[x][y] = 'G';
            copy[x + 1][y] = 'G';
            copy[x + 2][y] = 'G';
            copy[x + 2][y + 1] = 'G';
            copy[x + 2][y + 2] = 'G';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] H(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y > 1 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 2][y - 1] == '0' && now[x - 2][y - 2] == '0'))  //7
        {
            copy[x][y] = 'H';
            copy[x - 1][y] = 'H';
            copy[x - 1][y - 1] = 'H';
            copy[x - 2][y - 1] = 'H';
            copy[x - 2][y - 2] = 'H';
            return copy;
        }
        else if(g == 2 && y < 9 && x > 1 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y + 1] == '0' && now[x - 2][y + 1] == '0' && now[x - 2][y + 2] == '0'))  //F
        {
            copy[x][y] = 'H';
            copy[x - 1][y] = 'H';
            copy[x - 1][y + 1] = 'H';
            copy[x - 2][y + 1] = 'H';
            copy[x - 2][y + 2] = 'H';
            return copy;
        }
        else if(g == 3 && y > 1 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 2][y - 1] == '0' && now[x + 2][y - 2] == '0'))  //J
        {
            copy[x][y] = 'H';
            copy[x + 1][y] = 'H';
            copy[x + 1][y - 1] = 'H';
            copy[x + 2][y - 1] = 'H';
            copy[x + 2][y - 2] = 'H';
            return copy;
        }
        else if(g == 4 && y < 9 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 2][y + 1] == '0' && now[x + 2][y + 2] == '0'))  //L
        {
            copy[x][y] = 'H';
            copy[x + 1][y] = 'H';
            copy[x + 1][y + 1] = 'H';
            copy[x + 2][y + 1] = 'H';
            copy[x + 2][y + 2] = 'H';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] I(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y < 10 && x > 1 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x - 1][y + 1] == '0' && now[x - 2][y + 1] == '0' && now[x - 2][y] == '0'))  //3
        {
            copy[x][y] = 'I';
            copy[x][y + 1] = 'I';
            copy[x - 1][y + 1] = 'I';
            copy[x - 2][y + 1] = 'I';
            copy[x - 2][y] = 'I';
            return copy;
        }
        else if(g == 2 && y > 0 && x > 1 && (now[x][y] == '0' && now[x][y - 1] == '0' && now[x - 1][y - 1] == '0' && now[x - 2][y - 1] == '0' && now[x - 2][y] == '0'))  //C
        {
            copy[x][y] = 'I';
            copy[x][y - 1] = 'I';
            copy[x - 1][y - 1] = 'I';
            copy[x - 2][y - 1] = 'I';
            copy[x - 2][y] = 'I';
            return copy;
        }
        else if(g == 3 && y > 1 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y - 1] == '0' && now[x + 1][y - 2] == '0' && now[x][y - 2] == '0'))  //U
        {
            copy[x][y] = 'I';
            copy[x + 1][y] = 'I';
            copy[x + 1][y - 1] = 'I';
            copy[x + 1][y - 2] = 'I';
            copy[x][y - 2] = 'I';
            return copy;
        }
        else if(g == 4 && y > 1 && x > 0 && (now[x][y] == '0' && now[x - 1][y] == '0' && now[x - 1][y - 1] == '0' && now[x - 1][y - 2] == '0' && now[x][y - 2] == '0'))  //M
        {
            copy[x][y] = 'I';
            copy[x - 1][y] = 'I';
            copy[x - 1][y - 1] = 'I';
            copy[x - 1][y - 2] = 'I';
            copy[x][y - 2] = 'I';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] J(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y >= 0 && x < 2 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 2][y] == '0' && now[x + 3][y] == '0'))  //|
        {
            copy[x][y] = 'J';
            copy[x + 1][y] = 'J';
            copy[x + 2][y] = 'J';
            copy[x + 3][y] = 'J';
            return copy;
        }
        else if(g == 2 && y < 8 && x >= 0 && (now[x][y] == '0' && now[x][y + 1] == '0' && now[x][y + 2] == '0' && now[x][y + 3] == '0'))  //-
        {
            copy[x][y] = 'J';
            copy[x][y + 1] = 'J';
            copy[x][y + 2] = 'J';
            copy[x][y + 3] = 'J';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] K(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y < 10 && x < 4 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x][y + 1] == '0' && now[x + 1][y + 1] == '0'))
        {
            copy[x][y] = 'K';
            copy[x + 1][y] = 'K';
            copy[x][y + 1] = 'K';
            copy[x + 1][y + 1] = 'K';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static char[][] L(char[][] now, int x, int y, int g)
    {
        char[][] copy = new char[5][11];
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                copy[i][j] = now[i][j];
            }
        }
        if(g == 1 && y > 0 && y < 10 && x < 3 && (now[x][y] == '0' && now[x + 1][y] == '0' && now[x + 1][y + 1] == '0' && now[x + 1][y - 1] == '0' && now[x + 2][y] == '0'))
        {
            copy[x][y] = 'L';
            copy[x + 1][y] = 'L';
            copy[x + 1][y + 1] = 'L';
            copy[x + 1][y - 1] = 'L';
            copy[x + 2][y] = 'L';
            return copy;
        }
        else
        {
            copy[0][0] = '-';
            return copy;
        }
    }

    public static void dfs(char[][] data, boolean[] already, int a, char[][] now, boolean end)    //僅data和end會影響外面(&)
    {
        int k = 0;
        if(end)
            return;

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
            end = true;
            return;
        }

        for(int i = 0; i < 11 && a < 12; i++)//X座標
        {
            for(int j = 0; j < 5; j++)  //Y座標
            {
                if(Character.isLetter(now[j][i]))  //非空格
                    continue;           //跳過
                
                if(a == 10 || a == 11)  //4對稱軸：KL
                    k = 1;  //1種方向
                else if(a == 9)         //2對稱軸：J
                    k = 2;  //2種方向
                else if(a >= 5 && a <= 8)//1對稱軸：FGHI
                    k = 4;  //4種方向
                else                    //0對稱軸：ABCDE
                    k = 8;  //8種方向
                
                for(int g = 1; g <= k && !Character.isLetter(now[j][i]) ; g++) //方向
                {
                    if(a == 0) //A
                    {
                        if(A(now, j, i, g)[0][0] == '-')    //填不進去
                        {
                            continue;
                        }
                        else                                //填進去了
                        {
                            already[a] = true;            //紀錄為A在棋盤上
                            dfs(data, already, a + 1, A(now, j, i, g), end); //呼叫自己開始算下一個(a+1)
                            already[a] = false;         //退出來後：紀錄為A不在棋盤上
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
                            already[a] = true;
                            dfs(data, already, a + 1, B(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, C(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, D(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, E(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, F(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, G(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, H(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, I(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, J(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, K(now, j, i, g), end);
                            already[a] = false;
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
                            already[a] = true;
                            dfs(data, already, a + 1, L(now, j, i, g), end);
                            already[a] = false;
                        }
                    }

                    if(end)
                        return;
                }
            }
        }
        return; //回傳
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String str;
        char[][] data = new char[5][11];  //初始數據 和 最後答案
        boolean[] already = new boolean[12];  //紀錄是否在棋盤上
        int tmp;
        boolean end = false;

        for(int i = 0; i < 5; i++)  //輸入
        {
            str = sc.next();
            data[i] = str.toCharArray();
        }
        sc.close();

        for(int i = 0; i < 12; i++) //清空紀錄
        {
            already[i] = false;
        }

        for(int j = 0; j < 11; j++)     //找出棋盤上已有的拼圖
        {
            for(int k = 0; k < 5; k++)
            {
                tmp = data[k][j];
                tmp -= 65;
                if(Character.isLetter(data[k][j]) && tmp >= 0 && tmp < 12)
                    already[tmp] = true;
            }
        }

        dfs(data, already, 0, data, end);    //開始遞迴DFS求解

        System.out.print("--------------\n");          //輸出分格線

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 11; j++)
            {
                System.out.print(data[i][j]);
            }
            System.out.print("\n");
        }
        
        return;   //結束
    }
}