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

int main()
{
    bool intro;

    intro = displayIntro();

    cout << endl << intro << endl;
}