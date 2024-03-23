#include "splashkit.h"
#include <vector>
using std::vector;
using namespace std;
#define SIZE 50


string arrayPoint[16][16];
bool check = false;
void draw_chess_board()
{
    fill_rectangle(COLOR_BLACK, 0, 600, 0, 800);
    fill_rectangle(COLOR_BLACK, 600, 800, 0, 800);
    draw_text("GO GAME", COLOR_ORANGE, "courbd.ttf", 100, 100, 40);
    draw_text("PRESS SPACE BUTTON TO REPLAY", COLOR_ORANGE, "courbd.ttf", 25, 70, 650);
    load_bitmap("image", "image.png");
    draw_bitmap("image", 150, 170);
    for (int i = 0; i <= 800; i = i + SIZE)
    {
        draw_line(COLOR_SEA_GREEN, 600, i, 1400, i);
    }

    for (int i = 600; i <= 1400; i = i + SIZE)
    {
        draw_line(COLOR_SEA_GREEN, i, 0, i, 800);
    }
}

int a;
string turn = "X";

void draw_chess()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (arrayPoint[i][j] == "X")
            {
                draw_line(COLOR_RED, 600 + (i + 1) * SIZE - 8 - SIZE / 2, (j + 1) * SIZE + 8 - SIZE / 2, 600 + (i + 1) * SIZE + 8 - SIZE / 2, (j + 1) * SIZE - 8 - SIZE / 2);
                draw_line(COLOR_RED, 600 + (i + 1) * SIZE + 8 - SIZE / 2, (j + 1) * SIZE + 8 - SIZE / 2, 600 + (i + 1) * SIZE - 8 - SIZE / 2, (j + 1) * SIZE - 8 - SIZE / 2);
            }
            if (arrayPoint[i][j] == "O")
            {
                draw_circle(COLOR_BLUE, 600 + (i + 1) * SIZE - SIZE / 2, (j + 1) * SIZE - SIZE / 2, 10);
            }
        }
    }
}

void handle_input()
{
    if (mouse_clicked(LEFT_BUTTON) and mouse_position().x >= 600)
    {
        int x, y;
        x = (mouse_position().x - 600) / SIZE;
        y = mouse_position().y / SIZE;

        if (arrayPoint[x][y] != "X" and arrayPoint[x][y] != "O")
        {
            arrayPoint[x][y] = turn;
            if (turn == "X")
            {
                fill_rectangle(COLOR_BLACK, 100, 500, 500, 400);
                draw_text("> TURN: BLUE", COLOR_BLUE, "courbd.ttf", 25, 100, 500);
                turn = "O";
            }
            else
            {
                fill_rectangle(COLOR_BLACK, 100, 500, 500, 400);
                draw_text("> TURN: RED", COLOR_RED, "courbd.ttf", 25, 100, 500);
                turn = "X";
            }
        }
    }
}

void check_win()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if ((
                 arrayPoint[i][j] == "X" and
                 arrayPoint[i][j + 1] == "X" and
                 arrayPoint[i][j + 2] == "X" and
                 arrayPoint[i][j + 3] == "X" and
                 arrayPoint[i][j + 4] == "X") or
                (arrayPoint[i][j] == "O" and
                 arrayPoint[i][j + 1] == "O" and
                 arrayPoint[i][j + 2] == "O" and
                 arrayPoint[i][j + 3] == "O" and
                 arrayPoint[i][j + 4] == "O"))
            {
                check = true;
            }

            else if ((
                     arrayPoint[i][j] == "X" and
                     arrayPoint[i + 1][j] == "X" and
                     arrayPoint[i + 2][j] == "X" and
                     arrayPoint[i + 3][j] == "X" and
                     arrayPoint[i + 4][j] == "X") or
                    (arrayPoint[i][j] == "O" and
                     arrayPoint[i + 1][j] == "O" and
                     arrayPoint[i + 2][j] == "O" and
                     arrayPoint[i + 3][j] == "O" and
                     arrayPoint[i + 4][j] == "O"))
            {
                check = true;
            }

            else if ((
                     arrayPoint[i][j] == "X" and
                     arrayPoint[i + 1][j + 1] == "X" and
                     arrayPoint[i + 2][j + 2] == "X" and
                     arrayPoint[i + 3][j + 3] == "X" and
                     arrayPoint[i + 4][j + 4] == "X") or
                    (arrayPoint[i][j] == "O" and
                     arrayPoint[i + 1][j + 1] == "O" and
                     arrayPoint[i + 2][j + 2] == "O" and
                     arrayPoint[i + 3][j + 3] == "O" and
                     arrayPoint[i + 4][j + 4] == "O"))
            {
                check = true;
            }

            else if ((
                     arrayPoint[i][j] == "X" and
                     arrayPoint[i + 1][j - 1] == "X" and
                     arrayPoint[i + 2][j - 2] == "X" and
                     arrayPoint[i + 3][j - 3] == "X" and
                     arrayPoint[i + 4][j - 4] == "X") or
                    (arrayPoint[i][j] == "O" and
                     arrayPoint[i + 1][j - 1] == "O" and
                     arrayPoint[i + 2][j - 2] == "O" and
                     arrayPoint[i + 3][j - 3] == "O" and
                     arrayPoint[i + 4][j - 4] == "O"))
            {
                check = true;
            }

            else if ((
                 arrayPoint[i][j] == "X" and
                 arrayPoint[i][j + 1] == "X" and
                 arrayPoint[i][j + 2] == "X" and
                 arrayPoint[i][j + 3] == "X" and
                (arrayPoint[i][j + 4] != "O" and arrayPoint[i][j - 1] != "O")) or
                (arrayPoint[i][j] == "O" and
                 arrayPoint[i][j + 1] == "O" and
                 arrayPoint[i][j + 2] == "O" and
                 arrayPoint[i][j + 3] == "O" and
                (arrayPoint[i][j + 4] != "X" and arrayPoint[i][j - 1] != "X"))
                )
            {
                check = true;
            }

            else if ((
                     arrayPoint[i][j] == "X" and
                     arrayPoint[i + 1][j] == "X" and
                     arrayPoint[i + 2][j] == "X" and
                     arrayPoint[i + 3][j] == "X" and
                    (arrayPoint[i + 4][j] != "O" and arrayPoint[i - 1][j] != "O")) or
                    (arrayPoint[i][j] == "O" and
                     arrayPoint[i + 1][j] == "O" and
                     arrayPoint[i + 2][j] == "O" and
                     arrayPoint[i + 3][j] == "O" and
                    (arrayPoint[i + 4][j] != "X" and arrayPoint[i - 1][j] != "X"))
                    )
            {
                check = true;
            }

            else if ((
                     arrayPoint[i][j] == "X" and
                     arrayPoint[i + 1][j + 1] == "X" and
                     arrayPoint[i + 2][j + 2] == "X" and
                     arrayPoint[i + 3][j + 3] == "X" and
                    (arrayPoint[i + 4][j + 4] != "O" and arrayPoint[i - 1][j - 1] != "O")) or
                    (arrayPoint[i][j] == "O" and
                     arrayPoint[i + 1][j + 1] == "O" and
                     arrayPoint[i + 2][j + 2] == "O" and
                     arrayPoint[i + 3][j + 3] == "O" and
                    (arrayPoint[i + 4][j + 4] != "X" and arrayPoint[i - 1][j - 1] != "O"))
                    )
            {
                check = true;
            }

            else if ((
                     arrayPoint[i][j] == "X" and
                     arrayPoint[i + 1][j - 1] == "X" and
                     arrayPoint[i + 2][j - 2] == "X" and
                     arrayPoint[i + 3][j - 3] == "X" and
                    (arrayPoint[i + 4][j - 4] != "O" and arrayPoint[i - 1][j + 1] != "O")) or
                    (arrayPoint[i][j] == "O" and
                     arrayPoint[i + 1][j - 1] == "O" and
                     arrayPoint[i + 2][j - 2] == "O" and
                     arrayPoint[i + 3][j - 3] == "O" and
                    (arrayPoint[i + 4][j - 4] != "X" and arrayPoint[i - 1][j + 1] != "O"))
                    )
            {
                check = true;
            }
        }
    }

    if (check == true)
    {
        if (turn == "X")
        {
            fill_rectangle(COLOR_BLACK, 70, 500, 500, 100);
            draw_text("CONGRATULATIONS!!! THE BLUE WON", COLOR_BLUE, "courbd.ttf", 25, 70, 500);
        }
        else if (turn == "O")
        {
            fill_rectangle(COLOR_BLACK, 70, 500, 500, 100);
            draw_text("CONGRATULATIONS!!! THE RED WON", COLOR_RED, "courbd.ttf", 25, 70, 500);
        }
    }
}

void replay()
{
    if (key_down(SPACE_KEY))
    {
        clear_screen(COLOR_BLACK);
        check = false;
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                arrayPoint[i][j] = "";
            }
        }
        turn = "X";
    }
}
int main()
{
    a = 1;
    open_window("Go Game", 1400, 800);
    clear_screen(COLOR_BLACK);
    while (not quit_requested())
    {
        process_events();

        draw_chess_board();
        if (check == false)
        {
            handle_input();
        }
        draw_chess();
        check_win();
        replay();
        refresh_screen(60);
    }

    return 0;
}
