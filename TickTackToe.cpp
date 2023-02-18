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

    if(choice != char(88) && choice != char(79) && choice != char(120) && choice != char(111))
    {
        cout << "Invalid Input!" << endl;
        goto repeat;
    }

    return choice;
}

int getSize()
{
    int size;

    cout << "What should be the size of the grid?" << endl;
    cout << "Enter a single integer (e.g : 3 = 3x3) : ";
    cin >> size;

    return size;
}

char** setGridSize(int size)
{
    char** grid = new char*[size];

    for(int r = 0 ; r < size ; r++)
    {
        grid[r] = new char[size];

        for(int c = 0 ; c < size ; c++)
        {
            grid[r][c] = ' ';
        }
    }

    return grid;
}


void gameStart(char** grid, int s, char c)
{
    int r = 0, col = 0; 
    char input; 
    
    while (true) {
        
        for(int i = 0 ; i < s ; i++)
        {
            for(int j  = 0 ; j < s ; j++)
            {
                if (i == r && j == col) {
                    cout << "[" << grid[i][j] << "]";
                } else {
                    cout << " " << grid[i][j] << " ";
                }
                if(j != s-1)
                {
                    cout << "|";
                }
            }
            cout << endl;
            if(s-1 != i)
            {
                cout << string(s*4-1, '-');
            }
            cout << endl;
        }
        
        cin >> input;
        if (input == 'w' && r > 0) 
        {
            r--;
        } 
        else if (input == 's' && r < s-1) 
        {
            r++;
        } 
        else if (input == 'a' && col > 0) 
        {
            col--;
        } 
        else if (input == 'd' && col < s-1) 
        {
            col++;
        } 
        else 
        {
            continue;
        }
    }
}



int main()
{
    bool intro;
    char character;
    int s;

    intro = displayIntro();

    if(intro == false)
    {
        cout << "\nBye Bye Loser ;p" << endl;
        return 0;
    }

    character = chooseChar();
    s = getSize();

    char** grid;

    grid = setGridSize(s); 

    gameStart(grid, s, character);
}