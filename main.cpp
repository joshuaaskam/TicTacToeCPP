#include <iostream>
using namespace std;
//using a char array to represent the square that will be played on
char grid[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Check square to see if game won (1), tied (0), or still playing (-1)
int checkWin()
{
    // checks if there are any horizontal matches
    for(int i = 1; i <= 7; i += 3)
    {
        if(grid[i] == grid[i+1] && grid[i+1] == grid[i+2])
            return 1;
    }
    // checks if there are any vertical matches
    for(int i = 1; i <=3; i++)
    {
        if(grid[i] == grid[i+3]  &&  grid[i + 3] == grid[i+6])
            return 1;
    }
    // check for diagonal matches
    if(grid[1] == grid[5] && grid[5] == grid[9])
        return 1;
    else if(grid[3] == grid[5] && grid [5] == grid[7])
        return 1;
    // check if still playing
    for(int i = 1; i <10; i ++)
        if(grid[i] == ('0' + i))
            return -1;
    // game tied
    return 0;
}

// Draw the board
void board()
{
    system("clear");
    cout <<"\n\n\tTic Tac Toe Game\n\n";
    cout << "Player 1(X) - Player 2(O)\n\n\n";

    //drawing of the board
    cout << "     |     |     " << endl;
    cout << "  " << grid[1] << "  |  " << grid[2] << "  |  " << grid[3] << " " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << grid[4] << "  |  " << grid[5] << "  |  " << grid[6] << " " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << grid[7] << "  |  " << grid[8] << "  |  " << grid[9] << " " << endl;
    cout << "     |     |     " << endl;
}

int main()
{
    int player = 1, i, choice;
    char mark;

    do
    {
        board();
        //If player 1, then 1 % 2 == 1 == true, then assigns 1. If player 2, then 2 % 2 == 0 == false, then assigns 2.
        player = (player % 2) ? 1:2;

        cout << "Player " << player << ", enter the number: ";
        cin >> choice;

        mark = (player == 1) ? 'X':'O';

        if(grid[choice] != 'O' && grid[choice] != 'X')
            grid[choice] = mark;
        else
        {
            cout << "INVALID MOVE!";
            player--;
            cin.ignore();
            cin.get();
        }

        i = checkWin();
        player++;
    } while(i == -1);
    board();
    if(i == 1)
        cout << "\aCONGRATULATIONS! PLAYER " << --player << " WINS!";
    else
        cout << "\aGAME DRAW!";
    cin.ignore();
    cin.get();
    return 0;
}
