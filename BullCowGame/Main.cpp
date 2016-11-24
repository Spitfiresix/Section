#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetPlayerGuess();
bool AskToPlayAgain();
//BullCowGame
int main()
{
    do
    {
        PrintIntro();
        PlayGame();
    } while (AskToPlayAgain());
    return 0;
}

void PlayGame()
{
    constexpr int NUMBER_OF_TURNS = 9;
    for (int i = 0; i < NUMBER_OF_TURNS; i++)
    {
        string playerGuess = GetPlayerGuess();
        cout << "Your guess is " << playerGuess << " correct ?/n";
        cout << endl;
    }
    return;
}

void PrintIntro()
{
    constexpr int WORLD_LENGTH = 9;
    cout << "Welcome to Bulls and Cows, a fun word game." << endl;
    cout << "Can you guess the " << WORLD_LENGTH;
    cout << " letter isogram ?" << endl;
    return;
}

string GetPlayerGuess()
{
    cout << "Enter a guess : ";
    string Guess = "";
    getline(cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    cout << "Do you want to play again? Select Y or N";
    string Response = "";
    getline(cin, Response);
    
    return (Response[0] == 'y') || (Response[0]== 'Y');
}
