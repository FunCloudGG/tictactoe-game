#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <mmsystem.h>
using namespace std;
int difficulty = 0;
int music = 0;
bool first_time = true;
bool menu_start = true;
bool coop = false;
void menu(HANDLE hOut);
CONSOLE_CURSOR_INFO ci;
char backg[9][81] = {
    {"XXXXXXXXXXXXXXXXXXXXxxxoO                           OoxxxxXXXXXXXXXXXXXXXXXXXXXX"},
    {"XXXXXXXXXXXXXXXXXXxxxxoO                             OoxxxxXXXXXXXXXXXXXXXXXXXXX"},
    {"XXXXXXXXXXXXXXXXXXxxxoO                               OoxxxxXXXXXXXXXXXXXXXXXXXX"},
    {"XXXXXXXXXXXXXXXXxxxxoO                                 OoxxxxXXXXXXXXXXXXXXXXXXX"},
    {"XXXXXXXXXXXXXXxxxxoO                                     OoxxxxXXXXXXXXXXXXXXXXX"},
    {"XXXXXXXXXXXXxxxxxoO                                       OoxxxxxXXXXXXXXXXXXXXX"},
    {"XXXXXXXXXXxxxxxxoO                                         OoxxxxxxXXXXXXXXXXXXX"},
    {"XXXXXXXXxxxxxxxoO                                           OoxxxxxxxXXXXXXXXXXX"},
    {"XXXXXxxxxxxxxxoO                                             OoxxxxxxxxxXXXXXXXX"}
};

int bot(int game[3][3], int swap) {
    srand(time(nullptr));
    int x = 0;
    int y = 0;
    int a = 1;
    if (difficulty == 1) {
        a = rand() % 1;
    }
    else if (difficulty == 0) {
        a = 0;
    }
    if (a) {
        for (int i = 0; i < 3; i++) {
            if (game[i][0] == (swap % 2) + 1 && game[i][1] == (swap % 2) + 1 && game[i][2] == 0) {
                return i * 3 + 2 + 1;
            }
            if (game[i][0] == (swap % 2) + 1 && game[i][1] == 0 && game[i][2] == (swap % 2) + 1) {
                return i * 3 + 1 + 1;
            }
            if (game[i][0] == 0 && game[i][1] == (swap % 2) + 1 && game[i][2] == (swap % 2) + 1) {
                return i * 3 + 1;
            }
            if (game[0][i] == (swap % 2) + 1 && game[1][i] == (swap % 2) + 1 && game[2][i] == 0) {
                return 2 * 3 + i + 1;
            }
            if (game[0][i] == (swap % 2) + 1 && game[1][i] == 0 && game[2][i] == (swap % 2) + 1) {
                return 1 * 3 + i + 1;
            }
            if (game[0][i] == 0 && game[1][i] == (swap % 2) + 1 && game[2][i] == (swap % 2) + 1) {
                return 0 * 3 + i + 1;
            }
        }
        if (game[0][0] == 0 && game[1][1] == (swap % 2) + 1 && game[2][2] == (swap % 2) + 1) {
            return 1;
        }
        if (game[1][1] == 0 && game[0][0] == (swap % 2) + 1 && game[2][2] == (swap % 2) + 1) {
            return 1 * 3 + 1 + 1;
        }
        if (game[2][2] == 0 && game[1][1] == (swap % 2) + 1 && game[0][0] == (swap % 2) + 1) {
            return 2 * 3 + 2 + 1;
        }
        if (game[0][2] == 0 && game[1][1] == (swap % 2) + 1 && game[2][0] == (swap % 2) + 1) {
            return 3;
        }
        if (game[1][1] == 0 && game[0][2] == (swap % 2) + 1 && game[2][0] == (swap % 2) + 1) {
            return 1 * 3 + 1 + 1;
        }
        if (game[2][0] == 0 && game[1][1] == (swap % 2) + 1 && game[0][2] == (swap % 2) + 1) {
            return 2 * 3 + 1;
        }
        for (int i = 0; i < 3; i++) {
            if (game[i][0] == swap && game[i][1] == swap && game[i][2] == 0) {
                return i * 3 + 2 + 1;
            }
            if (game[i][0] == swap && game[i][1] == 0 && game[i][2] == swap) {
                return i * 3 + 1 + 1;
            }
            if (game[i][0] == 0 && game[i][1] == swap && game[i][2] == swap) {
                return i * 3 + 1;
            }
            if (game[0][i] == swap && game[1][i] == swap && game[2][i] == 0) {
                return 2 * 3 + i + 1;
            }
            if (game[0][i] == swap && game[1][i] == 0 && game[2][i] == swap) {
                return 1 * 3 + i + 1;
            }
            if (game[0][i] == 0 && game[1][i] == swap && game[2][i] == swap) {
                return 0 * 3 + i + 1;
            }
        }
        if (game[0][0] == 0 && game[1][1] == swap && game[2][2] == swap) {
            return 1;
        }
        if (game[1][1] == 0 && game[0][0] == swap && game[2][2] == swap) {
            return 1 * 3 + 1 + 1;
        }
        if (game[2][2] == 0 && game[1][1] == swap && game[0][0] == swap) {
            return 9;
        }
        if (game[0][2] == 0 && game[1][1] == swap && game[2][0] == swap) {
            return 3;
        }
        if (game[1][1] == 0 && game[0][2] == swap && game[2][0] == swap) {
            return 1 * 3 + 1 + 1;
        }
        if (game[2][0] == 0 && game[1][1] == swap && game[0][2] == swap) {
            return 2 * 3 + 1;
        }
    }
    do {
        x = rand() % 3;
        y = rand() % 3;

    } while (game[x][y] != 0);
    return (x * 3 + y + 1);
}

void musica(HANDLE hOut) {
    system("cls");
    COORD start = { 0,0 };
    SetConsoleCursorPosition(hOut, start);
    for (int i = 0; i < 8; i++) {
        cout << backg[i];
        start.Y++;
    }
    for (int i = 0; i < 9; i++) {
        cout << backg[8];
        start.Y++;
    }
    for (int i = 7; i > -1; i--) {
        cout << backg[i];
        start.Y++;
    }
    SetConsoleCursorPosition(hOut, { 35,8 });
    cout << "select music:";
    SetConsoleCursorPosition(hOut, { 37,10 });
    cout << "ot vinta";
    SetConsoleCursorPosition(hOut, { 36,12 });
    cout << "astral step";
    SetConsoleCursorPosition(hOut, { 36,14 });
    cout << "megalovania";
    SetConsoleCursorPosition(hOut, { 36,16 });
    cout << "faradsessel";
    SetConsoleCursorPosition(hOut, { 36,10 });
    COORD move[4] = { {36,10},{35,12},{35,14},{35,16} };
    int x = 224;
    int curX = 0;
    bool g = true;
    while (g) {
        x = _getch();
        switch (x)
        {
        case 72:
            if (curX > 0)
            {
                curX--;
                SetConsoleCursorPosition(hOut, move[curX]);
            }
            break;
        case 80:
            if (curX < 3)
            {
                curX++;
                SetConsoleCursorPosition(hOut, move[curX]);
            }
            break;
        case 32:
        case 13:
            music = curX;
            g = false;
            first_time = true;
            menu(hOut);
            break;
        }
    }
    system("cls");
}

void dif(HANDLE hOut) {
    system("cls");
    COORD start = { 0,0 };
    SetConsoleCursorPosition(hOut, start);
    for (int i = 0; i < 8; i++) {
        cout << backg[i];
        start.Y++;
    }
    for (int i = 0; i < 9; i++) {
        cout << backg[8];
        start.Y++;
    }
    for (int i = 7; i > -1; i--) {
        cout << backg[i];
        start.Y++;
    }
    SetConsoleCursorPosition(hOut, { 32,8 });
    cout << "select difficulty:";
    SetConsoleCursorPosition(hOut, { 39,10 });
    cout << "easy";
    SetConsoleCursorPosition(hOut, { 38,12 });
    cout << "normal";
    SetConsoleCursorPosition(hOut, { 39,14 });
    cout << "hard";
    SetConsoleCursorPosition(hOut, { 39,16 });
    cout << "back";
    SetConsoleCursorPosition(hOut, { 38,10 });
    COORD move[4] = { {38,10},{37,12},{38,14},{38,16} };
    int x = 224;
    int curX = 0;
    bool g = true;
    while (g) {
        x = _getch();
        switch (x)
        {
        case 72:
            if (curX > 0)
            {
                curX--;
                SetConsoleCursorPosition(hOut, move[curX]);
            }
            break;
        case 80:
            if (curX < 3)
            {
                curX++;
                SetConsoleCursorPosition(hOut, move[curX]);
            }
            break;
        case 32:
        case 13:
            if (curX == 3) {
                g = false;
                menu(hOut);
                break;
            }
            else {
                coop = false;
                g = false;
                difficulty = curX;
                break;
            }
        }
    }
    system("cls");
}

void menu(HANDLE hOut) {
    if (first_time) {
        if (music == 0) {
            PlaySoundA(("ot_vinta.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
        else if (music == 1) {
            PlaySoundA(("AstralStep.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
        else if (music == 2) {
            PlaySoundA(("megalovania.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
        else if (music == 3) {
            PlaySoundA(("faradsessel.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
    }
    first_time = false;
    menu_start = true;
    system("cls");
    COORD start = { 0,0 };
    SetConsoleCursorPosition(hOut, start);
    for (int i = 0; i < 8; i++) {
        cout << backg[i];
        start.Y++;
    }
    for (int i = 0; i < 9; i++) {
        cout << backg[8];
        start.Y++;
    }
    for (int i = 7; i > -1; i--) {
        cout << backg[i];
        start.Y++;
    }
    SetConsoleCursorPosition(hOut, { 35,9 });
    cout << "single play";
    SetConsoleCursorPosition(hOut, { 36,11 });
    cout << "2 player";
    SetConsoleCursorPosition(hOut, { 37,13 });
    cout << "music";
    SetConsoleCursorPosition(hOut, { 38,15 });
    cout << "exit";
    SetConsoleCursorPosition(hOut, { 34,9 });
    COORD move[4] = { {34,9},{35,11},{36,13},{37,15} };
    int x = 224;
    int curX = 0;
    bool g = true;
    while (g) {
        x = _getch();
        switch (x)
        {
        case 72:
            if (curX > 0)
            {
                curX--;
                SetConsoleCursorPosition(hOut, move[curX]);
            }
            break;
        case 80:
            if (curX < 3)
            {
                curX++;
                SetConsoleCursorPosition(hOut, move[curX]);
            }
            break;
        case 32:
        case 13:
            if (curX == 0) {
                dif(hOut);
                g = false;
                break;
            }
            if (curX == 1) {
                coop = true;
                g = false;
                break;
            }
            if (curX == 2) {
                musica(hOut);
                g = false;
                break;
            }
            if (curX == 3) {
                system("cls");
                exit(3);
            }
        }
    }
    system("cls");
}
int main() {

    int field[13][13] = { 0 };
    COORD move[4][3] =
    {
        {{35,7},{39,7},{43,7}},
        {{35,11},{39,11},{43,11}},
        {{35,15},{39,15},{43,15}},
        {{33,21},{33,21},{33,21}}
    };
    // zxCursor -->
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ci;
    ci.dwSize = 100;
    ci.bVisible = true;
    SetConsoleCursorInfo(hOut, &ci);
    //zxCursor <--
    int swap = 0;
    int x_win = 0;
    int o_win = 0;
    int draw = 0;
    menu(hOut);
    while (true) {
        menu_start = false;
        int game[3][3] = { { 0,0,0 }, {0,0,0 }, {0,0,0 } };
        COORD start = { 33,5 };
        SetConsoleCursorPosition(hOut, start);
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                if (i == 0 && j == 0) field[i][j] = 201; // Ã
                else if (i == 0 && j == 12) field[i][j] = 187; // Ã <--
                else if (i == 12 && j == 0) field[i][j] = 200; // L
                else if (i == 12 && j == 12) field[i][j] = 188; // L <--
                else if (i == 0 && j % 4 == 0) field[i][j] = 203; // '|'
                else if (i % 4 == 0 && j % 4 != 0) field[i][j] = 205;// -
                else if (i == 12 && j % 4 == 0) field[i][j] = 202; // _|_
                else if (j == 0 && i % 4 == 0) field[i][j] = 204; // |-
                else if (j % 4 == 0 && i % 4 != 0) field[i][j] = 186;// |
                else if (j == 12 && i % 4 == 0) field[i][j] = 185; // -|
                else if (i % 4 == 0 && j % 4 == 0) field[i][j] = 206; // -|-
                else field[i][j] = 255;
                cout << (char)field[i][j];
            }
            start.Y++;
            SetConsoleCursorPosition(hOut, start);
        }
        cout << " X: " << x_win << "  O: " << o_win;
        start.Y++;
        SetConsoleCursorPosition(hOut, start);
        cout << " draws: " << draw;
        SetConsoleCursorPosition(hOut, { 34,21 });
        cout << "go to menu";
        int x = 224;
        int curX = 1;
        int curY = 1;
        swap %= 2;
        swap += 1;
        SetConsoleCursorPosition(hOut, move[curX][curY]);
        int steps = 0;
        int win = 0;
        while (true) {
            x = _getch();
            switch (x)
            {
            case 72://up
                if (curX > 0)
                {
                    curX--;
                    SetConsoleCursorPosition(hOut, move[curX][curY]);
                }
                break;
            case 80://down
                if (curX < 3)
                {
                    curX++;
                    SetConsoleCursorPosition(hOut, move[curX][curY]);
                }
                break;
            case 75://left
                if (curY > 0)
                {
                    curY--;
                    SetConsoleCursorPosition(hOut, move[curX][curY]);
                }
                break;
            case 77://right
                if (curY < 2)
                {
                    curY++;
                    SetConsoleCursorPosition(hOut, move[curX][curY]);
                }
                break;
            case 32:
            case 13:
                if (game[curX][curY] == 0 && curX != 3) {
                    if (coop) {
                        game[curX][curY] = (steps % 2 + 1);
                        if ((steps % 2 + 1) == swap) {
                            cout << char(149);
                        }

                        else if ((steps % 2 + 1) != swap) {
                            cout << char(79);
                        }
                        SetConsoleCursorPosition(hOut, move[curX][curY]);
                        steps += 1;
                        break;
                    }
                    else if (!coop) {
                        if ((swap == 2 && steps != 0) || swap == 1) {
                            game[curX][curY] = (swap);
                            cout << char(149);
                            SetConsoleCursorPosition(hOut, move[curX][curY]);
                            steps += 1;
                            if (steps > 4) {
                                if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != 0) { /* \ */
                                    win = game[0][0];
                                    break;
                                }
                                if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && game[0][0] != 0) { // --- 1
                                    win = game[0][0];
                                    break;
                                }
                                if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && game[0][0] != 0) { // | 1
                                    win = game[0][0];
                                    break;
                                }
                                if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && game[0][1] != 0) { // --- 2
                                    win = game[0][1];
                                    break;
                                }
                                if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && game[1][0] != 0) { // | 2
                                    win = game[1][0];
                                    break;
                                }
                                if (game[2][0] == game[1][1] && game[1][1] == game[0][2] && game[2][0] != 0) { // /
                                    win = game[2][0];
                                    break;
                                }
                                if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && game[2][0] != 0) {
                                    win = game[2][0];
                                    break;
                                }
                                if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && game[0][2] != 0) {
                                    win = game[0][2];
                                    break;
                                }
                                if (steps == 9) {
                                    break;
                                }
                            }
                        }
                        if (steps != 9) {
                            int botX = (bot(game, swap) - 1) / 3;
                            int botY = (bot(game, swap) - 1) % 3;
                            game[botX][botY] = (swap % 2 + 1);
                            SetConsoleCursorPosition(hOut, move[botX][botY]);
                            cout << char(79);
                            SetConsoleCursorPosition(hOut, move[curX][curY]);
                            steps += 1;
                        }
                    }
                }
                else if (curX == 3) {
                    menu(hOut);
                    swap = 0;
                    x_win = 0;
                    o_win = 0;
                    draw = -1;
                    break;
                }
            }
            if (menu_start) {
                break;
            }

            if (steps > 4) {
                if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != 0) { /* \ */
                    win = game[0][0];
                    break;
                }
                if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && game[0][0] != 0) { // --- 1
                    win = game[0][0];
                    break;
                }
                if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && game[0][0] != 0) { // | 1
                    win = game[0][0];
                    break;
                }
                if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && game[0][1] != 0) { // --- 2
                    win = game[0][1];
                    break;
                }
                if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && game[1][0] != 0) { // | 2
                    win = game[1][0];
                    break;
                }
                if (game[2][0] == game[1][1] && game[1][1] == game[0][2] && game[2][0] != 0) { // /
                    win = game[2][0];
                    break;
                }
                if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && game[2][0] != 0) {
                    win = game[2][0];
                    break;
                }
                if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && game[0][2] != 0) {
                    win = game[0][2];
                    break;
                }
                if (steps == 9) {
                    break;
                }
            }
        }
        SetConsoleCursorPosition(hOut, { 36,20 });
        if (win == 0) {
            cout << "draw";
            draw += 1;
        }
        else if (win == swap) {
            cout << "X wins";
            x_win += 1;
        }
        else if (win != swap) {
            cout << "O wins";
            o_win += 1;
        }
        cout << endl;
        SetConsoleCursorPosition(hOut, { 0,0 });
        system("cls");
        steps = 0;
    }
}