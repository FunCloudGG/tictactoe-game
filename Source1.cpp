#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;


// Переменные с ботом 
int bot(int game[3][3]) {
    srand(time_t(NULL));
    int x;
    int y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (game[x][y] != 0);
    return(x * 3 + y + 1);
}

int main() {

    //Получение системного номера консоли
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //Работа курсора на поле 
    CONSOLE_CURSOR_INFO ci;
    ci.dwSize = 100;
    ci.bVisible = true;
    SetConsoleCursorInfo(hOut, &ci);

    //Координаты пермещения поля игры
    COORD start = { 33 , 5 };
    COORD move[3][3] =
    {
    {
        {35,7},{39,7},{43,7}
    },
    {
        {35,11},{39,11},{43,11}
    },
    {
        {35,15},{39,15},{43,15}
    }
    };

    // Создание поля игры
    SetConsoleCursorPosition(hOut, start);
    int pole[13][13] = { 0 }, igra[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (i == 0 && j == 0) pole[i][j] = 201;
            else if (i == 0 && j == 12) pole[i][j] = 187;
            else if (i == 12 && j == 0) pole[i][j] = 200;
            else if (i == 12 && j == 12) pole[i][j] = 188;
            else if (i == 0 && j % 4 == 0) pole[i][j] = 203;
            else if (i % 4 == 0 && j % 4 != 0) pole[i][j] = 205;
            else if (i == 12 && j % 4 == 0) pole[i][j] = 202;
            else if (j == 0 && i % 4 == 0) pole[i][j] = 204;
            else if (j % 4 == 0 && i % 4 != 0) pole[i][j] = 186;
            else if (j == 12 && i % 4 == 0) pole[i][j] = 185;
            else if (i % 4 == 0 && j % 4 == 0) pole[i][j] = 206;
            else pole[i][j] = 255;
            std::cout << (char)pole[i][j];
        }
        start.Y++;
        SetConsoleCursorPosition(hOut, start);

    }

    //
    // HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { 35, 11 };
    int curX = 0, curY = 0;
    //int x = _getch();
    SetConsoleCursorPosition(hOut, move[curX][curY]);
    int countOfSteps = 0;
    //boolean go = true;
    int bot_access = 0;
    int bot_access_choice = 0;
    //int x = _getch();
    int g = 0, turn = 0, n = 0;
    int hod = 0;
    while (1)
    {
        if (bot_access == 1) {
            cout << char(79);
            bot_access = 0;
        }

        int x = _getch();
        // Передвижение по полю
        switch (x)
        {
            // Перемещение курсора вверх 
        case 72:
            if (curX > 0 && curX <= 2) {
                if (curY >= 0 && curY <= 2) {
                    curX--;
                }
            }
            break;
            // Переменные курсора вниз 
        case 80:
            if (curX >= 0 && curX < 2) {
                if (curY >= 0 && curY <= 2) {
                    curX++;
                }
            }
            break;
            // Перемещение курсора влево 
        case 75:
            if (curY > 0 && curY <= 2) {
                if (curX >= 0 && curX <= 2) {
                    curY--;
                }
            }
            break;
            // Перемещение курсора вправо
        case 77:
            if (curY >= 0 && curY < 2) {
                if (curX >= 0 && curX <= 2) {
                    curY++;
                }
            }
            break;
        case 32://button Space!
           
            
            if (hod == 0) {
                cout << 'X';
                SetConsoleCursorPosition(hOut, move[curX][curY]);
                igra[curX][curY] = 1;
                hod++;
                bot_access_choice = 1
            }
        };

        if (bot_access_choice == 1)
        {
            int bot_choice = bot(igra);
            int bot_x = (bot_choice - 1) / 3;
            int bot_x = (bot_choice - 1) % 3;
            igra[bot_x][bot_y] = 2;
            c = { move[bot_x][bot_y] };
            bot_access = 1;
            bot_access_choice = 0;
            for (int i = 0; i < 3; i++)
            {
                if ((igra[0][i] == 2 && igra[1][i] == 2),
                    (igra[1][i] == 2 && igra[2][i] == 2),
                    (igra[0][i] == 2 && igra[2][i] == 2)) {
                    for (int j; j < 3; j++)
                    {
                        if (igra[j][i] == 0)
                        {
                            cout << "O";
                            igra[j][i] = 2;
                            SetConsoleCursorPosition(hOut, move[j][i]);

                        }
                    }
                }
            for (int i = 0; i < 3; i++)
            {
                for (int j; j < 3; j++){
                    if ((igra[i][0] == 2 && igra[i][1] == 2),
                        (igra[i][1] == 2 && igra[i][2] == 2),
                        (igra[i][0] == 2 && igra[i][2] == 2)) {


                        if (igra[i][j] == 0)
                        {
                            cout << "O";
                            igra[i][j] = 2;
                            SetConsoleCursorPosition(hOut, move[i][j]);

                        }


                    }
            }
            hod--;

        }
           
        }
        SetConsoleCursorPosition(hOut, move[curX][curY]);
        //SetConsoleCursorPosition(h, c);
    }
}