#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Arrays containing the characters and their Morse code representations
char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', ' ' };

string morse[] =
        {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
         "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
         "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----",
         "..---", "...--", "....-", ".....", "...--", "....-", ".....", "-....", "--...", "---..", "----.", " ", " " };

// Function prototypes
string from_text_to_morse(string text);
string from_morse_to_text(string morse1);

int main()

{
    string choice;
    // Main loop to handle user choices
    while (true)
    {


        cout << "PLEASE ENTER YOUR CHOICE : \n 1) cipher \n 2) decipher \n 3) exit ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left by cin

        if (choice == "1") {
            // If choice is 1, get text from user and convert it to Morse code
            string text;
            cout << "Please enter your text : \n";
            getline(cin, text);
            from_text_to_morse(text);
        }
        else if (choice == "2")
        {

            // If choice is 2, get Morse code from user and convert it to text
            string morse1;
            cout << "Please enter your morse :\n";
            getline(cin, morse1);
            from_morse_to_text(morse1);
        }
        else if (choice == "3")
        {
            // If choice is 3, exit the program
            break;
        }
        else
        {
            // If choice is invalid, prompt user to enter a valid choice, and end the program
            cout << "Please enter a valid choice from (1 / 2 / 3)\n";
            continue;
        }
    }
    return 0;
}

// Function to convert text to Morse code
string from_text_to_morse(string text)
{
    string con;
    // Loop through each character in the input text
    for (char x : text)
    {
        // Check if the character is a letter, number, or space
        for (int i = 0; i < 38; i++)
        {
            if (chars[i] == tolower(x))
            {
                // If the character matches, add its Morse code representation to the result string
                con += morse[i] + " ";
                break;
            }
        }
        // Add three spaces after every word
        if (x == ' ') {
            con += "";
        }
    }

    // Print the ciphered text
    cout << "Your ciphered text: \n" << con << endl;
    return con;
}

// Function to convert Morse code to text
string from_morse_to_text(string morse1)
{
    string the_text = "";
    string decipher = "";
    // Loop through each character in the Morse code input
    for (char str : morse1)
    {
        // If the character is a space, decode the Morse sequence and add the corresponding character to the result string
        if (str == ' ') {
            if (decipher == "")
            {
                // If the decipher string is empty, add a space to the result string
                the_text += " ";
            } else
            {
                // Loop through the Morse code array to find the corresponding character
                for (int i = 0; i < 38; i++)
                {
                    if (decipher == morse[i])
                    {
                        the_text += chars[i];
                        break;
                    }
                }
                decipher = ""; // Reset decipher for the next Morse code sequence
            }
        } else
        {
            // If the character is not a space, accumulate Morse code sequence
            decipher += str;
        }
    }
    // Check if there's remaining Morse code at the end
    if (!decipher.empty())
    {
        for (int i = 0; i < 38; i++)
        {
            if (decipher == morse[i])
            {
                the_text += chars[i];
                break;
            }
        }
    }
    // Print the deciphered text
    cout << "Your text: " << the_text << endl;
    return the_text;
}




