#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// function declerations
bool isValidNumber(string number);
int countExactMatches(string secret, string guess);
int countMisplacedMatches(string secret, string guess);

int main(int argc, char *argv[])
{

    srand(time(NULL));
    string secret;
    int numDigit = 0;

    if (string(argv[1]) == "-r" && argc == 3)
    {
        numDigit = atoi(argv[2]); // taking entered digit number to integer.
        if (numDigit > 9 || numDigit <= 0)
        { // checking entered digit number is valid. If it is not printing E0 error code.
            cout << "E0" << endl;
            return 1;
        }

        int high = 1;
        for (int i = 0; i < numDigit - 1; i++)
            high *= 10; // determining the number of digit of the secret number.

        int low = high / 10;
        int num = rand() % (high - low) + low; // generating random secret number.

        secret = to_string(num); // integer to string.

        while (!isValidNumber(secret))
        {
            num = rand() % (high - low) + low; // generating random secret number.
            secret = to_string(num);           // integer to string.
        }
    }
    else if (string(argv[1]) == "-u" && argc == 3)
    {
        secret = argv[2];
        numDigit = secret.length();
        if (!isValidNumber(secret))
        {
            cout << "E0" << endl; // checking input has same numbers. If it is printing E0 error code.(Ex: 1231 --> E0  1234 --> Valid)
            return 1;
        }
    }

    int turn = 0;
    for (;;)
    { // our infinite loop
        string guess;
        cin >> guess;
        if (!isValidNumber(guess))
        { // checking entered number is valid. If it is not valid printing E0 error code.
            cout << "E0" << endl;
            continue;
        }
        else if (guess.length() > numDigit || numDigit > guess.length())
        { // checking entered number longer or shorter then entered digit number. If it is longer or shorter then entered digit number printing E1 error code.
            cout << "E1" << endl;
            return 0;
        }
        for (int i = 0; i < guess.length(); i++)
        {
            if (isdigit(guess[i]) == false)
            { // checking input is integer. If it is not then printing E2 error code.
                cout << "E2" << endl;
                return 0;
            }
        }
        turn++;                                                      // incrementing turn number every turn.
        int exactMatches = countExactMatches(secret, guess);         // first counter
        int misplacedMatches = countMisplacedMatches(secret, guess); // second counter
        cout << exactMatches << " " << misplacedMatches << endl;
        if (secret.length() == exactMatches)
        { // if user found the number then printing
            cout << "FOUND! " << turn << endl;
            break;
        }
        else if (turn > 100)
        {
            cout << "FAILED!" << endl;
        }
    }
    return 0;
}

bool isValidNumber(string number)
{ // checking entered number is valid
    if (number[0] == '0')
    {
        return false;
    }
    for (int i = 0; i < number.length(); i++)
    {
        for (int j = i + 1; j < number.length(); j++)
        {
            if (number[i] == number[j])
                return false;
        }
    }
    return true;
}

int countExactMatches(string secret, string guess)
{ // first counter
    int count = 0;
    for (int i = 0; i < secret.length(); i++)
    {
        if (secret[i] == guess[i]) // if guess and our secret number matches incrementing counter
            count++;
    }
    return count;
}

int countMisplacedMatches(string secret, string guess)
{ // second counter
    int count = 0;
    for (int i = 0; i < secret.length(); i++)
    {
        for (int j = 0; j < guess.length(); j++)
        {
            if (secret[i] == guess[i] && i != j)
                count++;
        }
    }
    return count;
}
