#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
    Reset();
}


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    constexpr int32 CURRENT_TRY = 1;
    const FString HIDDEN_WORD = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyCurrentTry = CURRENT_TRY;
    MyHiddenWord = HIDDEN_WORD;
    return;
}

int32 FBullCowGame::GetMaxTries() const
{
    return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
    return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{

    return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (false)//if the guess isnt an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (false) 
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Length;
    }
    else 
    {
        return EGuessStatus::OK;
    }
}

bool FBullCowGame::IsIsogram()
{
    return false;
}
//recieves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 HiddenWordLength = MyHiddenWord.length();
    for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
    {
        //compare letters against the hidden word
        for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
        {
            if (Guess[GChar] == MyHiddenWord[MHWChar])
            {
                if (MHWChar == GChar) {
                    //If they are in the same place
                    BullCowCount.Bulls++;
                }
                else
                {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    return BullCowCount;
}
