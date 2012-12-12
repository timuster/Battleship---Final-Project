#include "functions.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

QString player1;
QString player2;
QString player1Grid[10][10]; //where player1's ships will be placed
QString player1HitGrid[10][10]; //where player1's hits will be marked
QString player2Grid[10][10]; //where player2's or computers ships will be placed
QString player2HitGrid[10][10]; //where player2's or computers hits will be marked

int main()
{
    bool playAgain = true;
    while (playAgain) {
        initializeGrid(player1Grid);
        initializeGrid(player1HitGrid);
        initializeGrid(player2Grid);
        initializeGrid(player2HitGrid);

        int playerOrComputer = initialPromptGameSelection();

        if (playerOrComputer == 1) {
            promptPlayAgainstComputer();
            setupComputer(player2Grid);
            playComputer();
        }
        else {
            promptPlayAgainstPerson();
            playFriend();
        }

        cout << "Do you want to play again? y/n" << endl;
        QString playAgainChoice;
        while (playAgainChoice[0] != 'y' && playAgainChoice[0] != 'n')
            cin >> playAgainChoice;
        if (playAgainChoice[0] == 'n')
            playAgain = false;
    }
    return 0;
}
