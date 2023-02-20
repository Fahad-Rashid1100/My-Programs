#include<iostream>
#include<fstream>

using namespace std;

int playerX = 0;
int playerO = 0;

char winner;
bool draw = false;

bool displayIntro()
{
    again2:
    char choice;
    
    cout << "-=+=TICK TACK TOE=+=-\n" << endl;
    cout << "Press ENTER to PLAY!" << endl;
    cout << string(9, ' ') << "OR" << endl;
    cout << "Enter Q or any key to quit if \nyou're a loser ;p" << endl;
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
    system("clear");
    cout << "(Player 1)" << endl;
    cout << "\'X\'  OR  \'O\'? (Capital Letter Only) : ";
    cin >> choice;

    if(choice != 'X'  && choice != 'O')
    {
        cout << "Invalid Input!" << endl;
        goto repeat;
    }

    return choice;
}

int getSize()
{
    int size;
    
    system("clear");

    again:
    
    cout << "What should be the size of the grid? (Min Input : 3)" << endl;
    cout << "Enter a single integer (e.g : 3 = 3x3) : ";
    cin >> size;

    if(size < 3)
    {
        cout << "The grid size can't be smaller than 3!" << endl;
        goto again;
    }

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

    for(int i = 1 ; i <= size ; i++)
    {
        grid[size - i][size - 1] = '\0';
    }

    for(int i = 1 ; i <= size ; i++)
    {
        grid[size - 1][size - i] = '\0';
    }

    grid[size - 1][size - 1] = '\n';

    return grid;
}


bool checkResult(char** grid, int size)
{
    int r = 0, c = 0, cnt = 0;

    
    for(int i = 0 ; i < size ; i++)
    {
        if(grid[r+i][c+i] == grid[r][c])
        {
            cnt++;
        }
    }
    if(cnt == size)
    {
        return true;
    }

    cnt = 0;  
    for(int i = 0 ; i < size ; i++)
    {
        cnt = 0;
        for(int j = 0 ; j < size ; j++)
        {
            if(grid[i][j] == grid[r][c])
            {
                cnt++;
            }
        }
        r++;
        if(cnt == size)
        {
            return true;
        }
    }

    r = 0;
    c = 0;
    cnt = 0;
    for(int i = size-1 ; i >= 0 ; i--)
    {
        if(grid[r][i] == grid[size-1][c])
        {
            cnt++;
        }
        r++;
    }
    if(cnt == size)
    {
        return true;
    }

    r = 0;
    c = 0;
    cnt = 0;
    for(int j = 0 ; j < size ; j++)
    {
        cnt = 0;
        for(int i = 0 ; i < size ; i++)
        {
            if(grid[i][j] == grid[r][c])
            {
                cnt++;
            }
        }
        c++;
        if(cnt == size)
        {
            return true;
        }
    }

     
    return false;
}

bool gameStart(char** grid, int s, char c)
{
    int r = 0, col = 0, moves = 0; 
    char input; 
    bool res;
    
    
    while (draw != true) 
    {

        cout << "\nUse WASD Keys to move the pointer!" << endl;
        cout << "NOTE : The Character between [] shows what character will be placed" << endl;
        cout << "It doesn't show what is already placed." << endl;
        
        for(int i = 0 ; i < s ; i++)
        {
            for(int j  = 0 ; j < s ; j++)
            {
                if (i == r && j == col) 
                {
                    cout << "[" << c << "]";
                } 
                else 
                {
                    cout << " " << grid[i][j] << " ";
                }
                if(i != s-1)
                {
                    if(j != s-1)
                    {   
                        cout << "|";
                    }
                }
                else
                {
                    if(j != s-1)
                    {   
                        if(i == r && j == col || grid[i][j] != '\0')
                        cout << "|";
                        else
                        cout << " |";
                    }
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
            system("clear");
        } 
        else if (input == 's' && r < s-1) 
        {
            r++;
            system("clear");
        } 
        else if (input == 'a' && col > 0) 
        {
            col--;
            system("clear");
        } 
        else if (input == 'd' && col < s-1) 
        {
            col++;
            system("clear");
        } 
        else if (input == 'p' && (grid[r][col] != 'X' && grid[r][col] != 'O')) 
        {
            system("clear");

            cout << "\a";

            moves++;

            cout << "\'" << c << "\' Placed. Move the Pointer to reveal the placed Character!" << endl;

            grid[r][col] = c;

            if(moves == s*s)
            {
                draw = true;
            }

            res = checkResult(grid, s);

            if(res == true && grid[r][col] != ' ')
            {
                winner = c;
                return true;
            }
            

            if(c == 'x' || c == 'X')
            {
                c = 'O';
            }
            else
            {
                c = 'X';
            }
        } 
        else 
        {
            system("clear");
            continue;
        }
        
    }

    return false;
}


bool playAgain()
{
    again:
    int choice;

    cout << "1- New Game\n2- Show Results" << endl;
    cin >> choice;

    if(choice == 1)
    {
        return true;
    }
    else if(choice == 2)
    {
        return false;
    }
    else
    {
        cout << "Invalid Input!" << endl;
        goto again;
    }
}

void showResults()
{
    system("clear");

    ofstream file;

    cout << "Player X Score : " << playerX << endl;
    cout << "Player O Score : " << playerO << endl;

    file.open("Scores.txt");

    file << "Player X Score : " << playerX << endl << "Player O Score : " << playerO;

    file.close();
}

int main()
{
    newgame:
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

    bool result = gameStart(grid, s, character);

    if(result == true)
    {
        for(int r = 0 ; r < s ; r++)
        {
            for(int c  = 0 ; c < s ; c++)
            {
                cout << " " << grid[r][c];
                if(c != s-1)
                {
                    cout << " |";
                }   
            }
            cout << endl;

            if(s-1 != r)
            {
                cout << string(s*4-1, '-');
            }
            cout << endl;
        }

        if(winner == 'X')
        {
            playerX += 100;
            playerO -= 30;
        }
        else
        {
            playerO += 100;
            playerX -= 30;
        }
        if(playerX < 0)
        {
            playerX = 0;
        }

        if(playerO < 0)
        {
            playerO = 0;
        }

        cout << "\n \'" << winner << "\' is the Winner!" << endl;

        if(playAgain() == true)
        {
            goto newgame;
        }
        else
        {
            showResults();
        }
    }
    else if(draw == true)
    {
        for(int r = 0 ; r < s ; r++)
        {
            for(int c  = 0 ; c < s ; c++)
            {
                cout << " " << grid[r][c];
                if(c != s-1)
                {
                    cout << " |";
                }   
            }
            cout << endl;

            if(s-1 != r)
            {
                cout << string(s*4-1, '-');
            }
            cout << endl;
        }

        playerO += 50;
        playerX += 50;

        cout << "OH WOW! It's a DRAW!" << endl;

        if(playAgain() == true)
        {
            draw = false;
            goto newgame;
        }
        else
        {
            showResults();
        }
    }
}