
//Hello !!
//This is my semester project which required us to make a hangman game in the terminal
//without any usage of the string library for processing strings.

#include <iostream>
#include <string.h>
#include <vector>
#include <random>
using namespace std;

// returns length of word selected by the computer.
int length(char *str)
{
    int i = 0;
    while (true)
    {
        if (*(str + i) == '\0')
        {
            return i;
        }
        i++;
    }
}

// copies characters of word selected by computer to an input char[]
char *stc(char *s, string d)
{
    for (int i = 0; d[i] != '\0'; i++)
    {
        s[i] = d[i];
    }

    return s;
}

// function to select a random word from a string vector
string selectWord()
{
    std::vector<std::string> words = {"china", "pakistan", "india", "usa", "karachi", "lahore"};

    // Create a random number generator
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, words.size() - 1);

    // Generate a random index
    int index = dis(gen);
    return words[index];
}

// checks if player has made a wrong choice
bool wrongChoice(char *s, char wr)
{
    for (int i = 0; i < length(s); i++)
    {
        if (s[i] == wr)
        {
            return false;
        }
    }
    return true;
}

// checks if characters entered by the user make
// up the word selected by the computer or not
bool isEqual(char *c, char *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (c[i] != p[i])
        {
            return false;
        }
    }
    return true;
}

// checks if player has chosen a correct character and if the
// character is correct its place at the index of the player choice array
void correctChoice(char *s, char cor, char *pc)
{
    int len = length(s);

    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (s[i] == cor)
        {
            pc[i] = cor;
        }
    }
}

// void wordDisplay(char *pc)
// {
// }

// alots '_' to every index at array
void makePC(char *s)
{
    for (int i = 0; i < 100; i++)
    {
        s[i] = '_';
    }
}

// displays array of character which the player has entered correctly
void displayPC(char *s, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << s[i];
    }
}

// prints hangman (corresponding to user enteres mistakes)
void Hangman(const int mistakes)
{
    if (mistakes == 11)
    {
        cout << '\t' << "(`.`)" << endl
             << '\t' << " /|\\" << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 10)
    {
        cout << '\t' << "(` `)" << endl
             << '\t' << " /|\\" << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 9)
    {
        cout << '\t' << "(  `)" << endl
             << '\t' << " /|\\" << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 8)
    {
        cout << '\t' << "(   )" << endl
             << '\t' << " /|\\" << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 7)
    {
        cout << '\t' << "(    " << endl
             << '\t' << " /|\\" << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 6)
    {
        cout << '\t' << "     " << endl
             << '\t' << " /|\\" << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 5)
    {
        cout << '\t' << "     " << endl
             << '\t' << "  |\\" << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 4)
    {
        cout << '\t' << "     " << endl
             << '\t' << "   \\" << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 3)
    {
        cout << '\t' << "     " << endl
             << '\t' << "    " << endl
             << '\t' << "  | " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 2)
    {
        cout << '\t' << "     " << endl
             << '\t' << "    " << endl
             << '\t' << "    " << endl
             << '\t' << " / \\" << endl;
    }
    else if (mistakes == 1)
    {
        cout << '\t' << "     " << endl
             << '\t' << "    " << endl
             << '\t' << "    " << endl
             << '\t' << "   \\" << endl;
    }
    else if (mistakes == 0)
    {
        cout << '\t' << "     " << endl
             << '\t' << "    " << endl
             << '\t' << "    " << endl
             << '\t' << "    " << endl;
    }
}

// main game loop
void gameLoop()
{

    char choice[100];
    char playerChoices[100];
    makePC(playerChoices);
    stc(choice, selectWord());
    int mistakes = 0;
    int len = length(choice);

    while (true)
    {
        if (isEqual(choice, playerChoices, len))
        {
            system("cls"); // edit later
            cout << "You won";
            break;
        }

        cout << choice << " mistakes: " << mistakes << " ";
        displayPC(playerChoices, len);

        cout << "\n\n\n";

        Hangman(mistakes);

        cout << "\n\n\n\nEnter a letter in word: ";
        char ch;
        cin >> ch;

        if (wrongChoice(choice, ch))
        {
            mistakes++;
            if (mistakes > 11)
            {
                system("cls");
                cout << "You lost";
                break;
            }
        }

        correctChoice(choice, ch, playerChoices);

        system("cls");
    }
}

int main()
{
    gameLoop();
    cout << endl;
    system("pause");
    return 0;
}