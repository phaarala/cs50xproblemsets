#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototype functions
string encipher(string plaintext, string key);
string get_plaintext(string plaintext);
bool validate_key(string key);

// Get key from user with command-line argument
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Utility: ./substitution KEY\n");
        return 1;
    }

    // Get user input for plaintext if key is valid
    string plaintext = NULL;
    if (validate_key(argv[1]) == 0)
    {
        plaintext = get_string("Plaintext: ");
    }
    else
    {
        return 1;
    }

    // Encipher and print to user
    string ciphertext = encipher(plaintext, argv[1]);
    printf("ciphertext: %s\n", ciphertext);
}

// Validate key (strlen == 26; no non-alphabetic chars; check for repeated chars, return 1 if error)
bool validate_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("Please create a key of 26 unique alphabetical characters.\n");
        return 1;
    }

    bool repeat_letters[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Please only provide alphabetical characters for your key.\n");
            return 1;
        }

        int index = tolower(key[i]) - 'a';
        if (repeat_letters[index] == true)
        {
            printf("Your key should return 26 unique characters\n");
            return 1;
        }
        repeat_letters[index] = true;
    }
    return 0;
}

// Encipher (for each alph char, determine what it maps to; preserve the case and leave
// non-alphabetic chars as is)
string encipher(string plaintext, string key)
{
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(plaintext[i]) != 0)
        {
            if (isupper(plaintext[i]) != 0)
            {
                plaintext[i] = toupper(key[tolower(plaintext[i]) - 'a']);
            }

            else
            {
                plaintext[i] = tolower(key[tolower(plaintext[i]) - 'a']);
            }
        }
    }
    return plaintext;
}
