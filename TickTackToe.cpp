#include<iostream>

using namespace std;

bool displayIntro()
{
    char choice;

    cout << "-=+=TICK TACK TOE=+=-\n" << endl;
    cout << "Press ENTER to PLAY!" << endl;
    cout << string(9, ' ') << "OR" << endl;
    cout << "Enter Q to quit if \nyou're a loser ;p" << endl;
    choice = getchar();

    if(choice == '\n')
    {
        return true;
    }
    else if(choice == 'Q' || choice == 'q')
    {
        return false;
    }
    return 0;
}


char chooseChar()
{
    char choice;
    repeat:
    cout << "(Player 1)" << endl;
    cout << "\'X\'  OR  \'O\'? : ";
    choice = getchar();

    if(choice != 'X' || choice != 'O' || choice != 'x' || choice != 'o')
    {
        cout << "Invalid Input!" << endl;
        goto repeat;
    }

    return choice;
}

void chooseGridSize()
{
    int size;

    cout << "What should be the size of the grid?" << endl;
    cout << "Enter a single integer (e.g : 3 = 3x3) : ";
    cin >> size;

    char grid[size][size];

    for(int r = 0 ; r < size ; r++)
    {
        for(int c = 0 ; c < size ; c++)
        {
            
        }
    }
}


int main()
{
    bool intro;
    char character;

    intro = displayIntro();

    if(intro == false)
    {
        cout << "\nBye Bye Loser ;p" << endl;
        return 0;
    }

    character = chooseChar();
}