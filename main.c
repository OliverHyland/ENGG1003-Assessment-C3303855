#include <stdio.h>

/* Functions:
    A: Rotation Cipher Encryption. Successfully encrypts a message by rotating each letter a number of positions and capitalises them if not given as such. Reads and writes to file, prints to stdout also. The key is hard-coded as it was not prescribed to be written by stdin or file i/o. 
    B: Rotation Cipher Decryption. Successfully decrypts a message by rotating each letter a number of positions and capitalises them if not given as such. Reads and writes to file, prints to stdout also. The key is hard-coded the same as function A as it was not prescribed to be written by stdin or file i/o.
    C: Substitution Cipher Encryption. Successfully encrypts a message by matching each occurrence of a letter in the message text to plain text, assigning its value then to the cipher text in the same position as the plain text. Process awkwardly applies switch-case rather than array. Reads and writes to file, prints to stdout also. 
    D: Substitution Cipher Decryption. Somehwat successfully decrypts a message by matching letter occurrences according to arrays. Capitalises streams once before use, rather than multiple times as in other functions. Spaces are lost when decrypted however, and attempts to print to stdout altered the result. Program therfore reads and writes to file, however does not print to stdout also. */

int main()
{
    /* Running stdin manually                                                               //steps to run stdin manually using the terminal in order to select the program below
    Enter in terminal: cd /projects/ENGG1003-Assessment-C3303855/
    Enter in terminal: ls
    Enter in terminal: ./a.out                                                              //You can shortcut to just typing this in the terminal to begin
    Enter in terminal: (input)                                                              //Lastly enter your input */
    
    printf("Please enter A, B, C, or D to select program \n");                              //print prompts to tell the user what stdin is required to select which program
    printf("A: Rotation Cipher Encryption \n");
    printf("B: Rotation Cipher Decryption \n");
    printf("C: Subtitution Cipher Encryption \n");
    printf("D: Substitution Cipher Decryption \n");
    char selectionLetter;                                                                   //declare a variable which will store the user's standard input
    scanf("%c", &selectionLetter);                                                          //scan the user's standard input to the declare variable in the format char, because it is a letter character input
    if (selectionLetter != 'A' && selectionLetter != 'a' && selectionLetter != 'B' && selectionLetter != 'b' && selectionLetter != 'C' && selectionLetter != 'c' && selectionLetter != 'D' && selectionLetter != 'd')
        printf("No correct input selected currently \n");
    if (selectionLetter == 'A' || selectionLetter == 'a')                                   //if the user selects option A, run the following program
    {
        //Rotation Cipher Encryption -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        /* Description: The contents of the message file are read into a string. This string is then read element by element, assigning that element to a variable, capitalising the letter
                        by adding 32 according to the ASCII table, and then adding the encryption key. At the end of each loop this variable is re-assigned to its element in the array. The
                        element's position is then incremented and the process is repeated for all elements. At the end the string is printed to stdout and written to file. */
        printf("You have selected Rotation Cipher Encryption. Enter text to encrypt in encryptionFile. Encrypted text will be written to decryptionFile \n");
        char encryptionKey = 3;                                                             //declare and initalise a key which will be the number of positions the characters are rotated in the encryption
        int arrayCounter = 0;                                                               //declare and initialise a variable which will be used to view each element in an array
        FILE *openReadingFile;                                                              //declare a pointer to file
        openReadingFile = fopen("encryptionFile", "r");                                     //initialise the pointer to file as containing the open file "encryptionFile", suitable for reading from
        FILE *openWritingFile;                                                              //declare a pointer to file
        openWritingFile = fopen("decryptionFile", "w");                                     //initialise the pointer to file as containing the open file "decryptionFile", suitable for writing to
        char encryptionCharacter, encryptionString[100];                                    //declare a variable which will be assigned to the array's elements in the loop, and declare the array which the file pointer's contents will be read to
        fread(encryptionString, 2, 100, openReadingFile);                                   //read the contents of the file pointer openReadingFile, which is the open file encryptionFile, to the array encryptionString
        for (arrayCounter = 0; encryptionString[arrayCounter] != '\0'; arrayCounter++)      //loop the following, one element in the array at a time, while it is not true that we are at the end of the array, i.e. run while the array has not ended
        {
            encryptionCharacter = encryptionString[arrayCounter];                           //assign the element in the array as it occurs to this variable
            if (encryptionCharacter >= 'a' && encryptionCharacter <= 'z')                   //if it is lower case
                encryptionCharacter = encryptionCharacter - 32;                             //add 32 which makes it the sample character but capitalised, according to the ASCII dec values for letters
            if (encryptionCharacter >= 'A' && encryptionCharacter <= 'Z')                   //if the variable containing the first element of the array is now a capital letter from A to Z
            {
                encryptionCharacter = encryptionCharacter + encryptionKey;                  //assign the value of that variable to itself plus the key. i.e. encrypt the letter with the key by adding the key to it, which moves it through the alphabet the number of positions indicated by the encryptionkey
                if (encryptionCharacter > 'Z')                                              //if the letter when encrypted is greater than Z
                    encryptionCharacter = encryptionCharacter - 26;                         //-26 so that it loops around in the alphabet when encrypted
                if (encryptionCharacter < 'A')                                              //in the case of a negative key, if the letter when encrypted is less than A
                    encryptionCharacter = encryptionCharacter + 26;                         //+26 so that it loops around in the alphabet when encrypted
            }
            encryptionString[arrayCounter] = encryptionCharacter;                           //re-assign the value of the used variable to the element in the array
        }
        fprintf(openWritingFile, "%s", encryptionString);                                   //after each element in the array is read and encrypted, print the array's string to openWritingFile, which points to the text file "decryptionFile"
        printf("%s", encryptionString);                                                     //printing to standard output in addition to writing to file
    }
    if (selectionLetter == 'B' || selectionLetter == 'b')                                   //if the user selects option B, run the following program
    {
        //Rotation Cipher Decryption -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        /* Description: The contents of the encrypted file are read into a string. This string is then read element by element again, assigning that element to a variable, capitalising the letter
                        (although this is technically unnecessary as it is capitlised previously, however it accounts for circumstances in which someone gives an encrypted text directly rather
                        than encrypting it through the above program). The encryption key is then subtracted from each character. At the end of each loop this variable is re-assigned to its element
                        in the array. The element's position is then incremented and the process is repeated for all elemenets. At the end the string is printed to stdout and written to file */
        printf("You have selected Rotation Cipher Decryption. The text encrypted by the rotation cipher encryption, written to decryptionFile, will be decrypted and written to decryptionOutputFile \n");
        char decryptionKey = 3;                                                                     //declare and initalise a key which will be the number of positions the characters are rotated in the decryption. This must be the same key as used in the encryption
        int arrayCounterTwo = 0;                                                                    //declare and initialise a variable which will be used to view each element in an array
        FILE *openReadingFileTwo;                                                                   //declare a pointer to file
        openReadingFileTwo = fopen("decryptionFile", "r");                                          //initialise the pointer to file as containing the open file "decryptionFile", suitable for reading from
        FILE *openWritingFileTwo;                                                                   //declare a pointer to file
        openWritingFileTwo = fopen("decryptionOutputFile", "w");                                    //initialise the pointer to file as containing the open file "decryptionOutputFile", suitable for writing to
        char decryptionCharacter, decryptionString[100];                                            //declare a variable which will be assigned to the array's elements in the loop, and declare the array which the file pointer's contents will be read to
        fread(decryptionString, 2, 100, openReadingFileTwo);                                        //read the contents of the file pointer openReadingFileTwo, which is the open file decryptionFile, to the array decryptionString
        for (arrayCounterTwo = 0; decryptionString[arrayCounterTwo] != '\0'; arrayCounterTwo++)     //loop the following, one element in the array at a time, while it is not true that we are at the end of the array, i.e. run while the array has not ended
        {
            decryptionCharacter = decryptionString[arrayCounterTwo];                                //assign the element in the array as it occurs to this variable
            if (decryptionCharacter >= 'a' && decryptionCharacter <= 'z')                           //if it is lower case
                decryptionCharacter = decryptionCharacter - 32;                                     //add 32 which makes it the sample character but capitalised, according to the ASCII dec values for letters
            if (decryptionCharacter >= 'A' && decryptionCharacter <= 'Z')                           //if the variable containing the first element of the array is now a capital letter from A to Z
            {
                decryptionCharacter = decryptionCharacter - decryptionKey;                          //assign the value of that variable to itself minus the key. i.e. decrypt the letter with the key by substracting the key from it, which moves it through the alphabet the number of positions indicated by the decryptionkey
                if (decryptionCharacter > 'Z')                                                      //if the letter when decrypted is greater than Z
                    decryptionCharacter = decryptionCharacter - 26;                                 //-26 so that it loops around in the alphabet when decrypted
                if (decryptionCharacter < 'A')                                                      //in the case of a negative key, if the letter when decrypted is less than A
                    decryptionCharacter = decryptionCharacter + 26;                                 //+26 so that it loops around in the alphabet when decrypted
            }
            decryptionString[arrayCounterTwo] = decryptionCharacter;                                //re-assign the value of the used variable to the element in the array
        }
        fprintf(openWritingFileTwo, "%s", decryptionString);                                        //after each element in the array is read and encrypted, print the array's string to openWritingFile, which points to the text file "decryptionFile"
        printf("%s", decryptionString);                                                             //printing to standard output in addition to writing to file
    }
    if (selectionLetter == 'C' || selectionLetter == 'c')                                           //if the user selects option C, run the following program
    {
        //Substitution Cipher Encryption -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        /* Description: The message and the cipher text are read from file to strings. Each element in the message is read one by one and capitalised. The program then searches for instances
                        where a letter in the message equals a letter in plain text. When this occurs, the letter in the cipher text which holds the same position as the position of the plain
                        text letter is assigned to the variable which has been allowed to equal an element in the message array.  This is capitalised again, and the variable assigns the 
                        cipher letter to the element in the array. The process is then repeated for every letter. This method is functional as it assumes the cipher text is given and the position
                        of a letter in cipher text corresponds to its substitute in plain text. Results are printed to stdout and written to file */
        printf("You have selected Substitution Cipher Encryption. Enter text to encrypt in encryptionFileTwo. Encrypted text will be written to decryptionFileTwo \n");
        FILE *openReadingFileThree;                                                                 //declare a pointer to file                                            
        openReadingFileThree = fopen("cipherTextFile", "r");                                        //initialise the pointer to file as containing the open file "cipherTextFile", suitable for reading from
        FILE *openReadingFileFour;                                                                  //declare a pointer to file
        openReadingFileFour = fopen("encryptionFileTwo", "r");                                      //initialise the pointer to file as containing the open file "encryptionFileTwo", suitable for reading from
        FILE *openWritingFileThree;                                                                 //declare a pointer to file
        openWritingFileThree = fopen("decryptionFileTwo", "w");                                     //initialise the pointer to file as containing the open file "decryptionFileTwo", suitable for writing to
        char cipherString[25], messageString[100], encryptionCharacterTwo;                          //declare arrays to contain the message, the ciphertext, and a variable for the element in the message array to be assigned to later
        int arrayCounterSix = 0;                                                                    //declare and initialise a variable which will be used to view each element in an array                                                             
        fread(cipherString, 2, 26, openReadingFileThree);                                           //read the contents of the file pointer openReadingFileThree, which is the open file cipherTextFile, to the array cipherString
        fread(messageString, 2, 100, openReadingFileFour);                                          //read the contents of the file pointer openReadingFileFour, which is the open file encryptionFileTwo, to the array messageString
        for (arrayCounterSix = 0; messageString[arrayCounterSix] != '\0'; arrayCounterSix++)        //loop the following, one element in the array at a time, while it is not true that we are at the end of the array, i.e. run while the array has not ended
        {
            encryptionCharacterTwo = messageString[arrayCounterSix];                                //assign the element in the array as it occurs to this variable
            if (encryptionCharacterTwo >= 'a' && encryptionCharacterTwo <= 'z')                     //if the element is lower case
                encryptionCharacterTwo = encryptionCharacterTwo - 32;                               //add 32 which makes it the sample character but capitalised, according to the ASCII dec values for letters 
            switch (encryptionCharacterTwo)                                                         //when the element is equal to a given letter, assign it to the ciphertext which occurs at the same position in the alphabet. This works because the plain text and cipher text alphabets align with each other, i.e. if a letter is 'c' in the message, its encrypted letter will also be position 3 in the cipher text alphabet
            {
                case 'A': encryptionCharacterTwo = cipherString[0]; break;
                case 'B': encryptionCharacterTwo = cipherString[1]; break;
                case 'C': encryptionCharacterTwo = cipherString[2]; break;
                case 'D': encryptionCharacterTwo = cipherString[3]; break;
                case 'E': encryptionCharacterTwo = cipherString[4]; break;
                case 'F': encryptionCharacterTwo = cipherString[5]; break;
                case 'G': encryptionCharacterTwo = cipherString[6]; break;
                case 'H': encryptionCharacterTwo = cipherString[7]; break;
                case 'I': encryptionCharacterTwo = cipherString[8]; break;
                case 'J': encryptionCharacterTwo = cipherString[9]; break;
                case 'K': encryptionCharacterTwo = cipherString[10]; break;
                case 'L': encryptionCharacterTwo = cipherString[11]; break;
                case 'M': encryptionCharacterTwo = cipherString[12]; break;
                case 'N': encryptionCharacterTwo = cipherString[13]; break;
                case 'O': encryptionCharacterTwo = cipherString[14]; break;
                case 'P': encryptionCharacterTwo = cipherString[15]; break;
                case 'Q': encryptionCharacterTwo = cipherString[16]; break;
                case 'R': encryptionCharacterTwo = cipherString[17]; break;
                case 'S': encryptionCharacterTwo = cipherString[18]; break;
                case 'T': encryptionCharacterTwo = cipherString[19]; break;
                case 'U': encryptionCharacterTwo = cipherString[20]; break;
                case 'V': encryptionCharacterTwo = cipherString[21]; break;
                case 'W': encryptionCharacterTwo = cipherString[22]; break;
                case 'X': encryptionCharacterTwo = cipherString[23]; break;
                case 'Y': encryptionCharacterTwo = cipherString[24]; break;
                case 'Z': encryptionCharacterTwo = cipherString[25]; break;
            }
            if (encryptionCharacterTwo >= 'a' && encryptionCharacterTwo <= 'z')                     //if the element is lower case (which in this case it will be because it is being assigned to the ciphertext which is given as lower case. In the following function you will see that the cipher and plain texts are capitalised instead of using this process multiple times).  
                encryptionCharacterTwo = encryptionCharacterTwo - 32;                               //add 32 which makes it the sample character but capitalised, according to the ASCII dec values for letters 
            messageString[arrayCounterSix] = encryptionCharacterTwo;                                //re-assign the value of the used variable to the element in the array
        }
        fprintf(openWritingFileThree, "%s", messageString);                                         //after each element in the array is read and encrypted, print the array's string to openWritingFileThree, which points to the text file "decryptionFileTwo"
        printf("%s", messageString);                                                                //printing to standard output in addition to writing to file
    }
    if (selectionLetter == 'D' || selectionLetter == 'd')                                           //if the user selects option D, run the following program.
    {
        //Substitution Cipher Decryption -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        /* Description: cipher text, plain text, and the encrypted message are read from file to strings. The cipher text and plain text strings are then read element by element and capitalised
                        before running the substitution program. Reading until the null character at the end of the array for the encrypted message string, the element in the array is given a variable. When
                        this variable, which is the current letter of the encrypted message, is not equal to a letter in the cipher text, it increments until it is the case. When it is the case
                        the plain text letter in the same position as that cipher text letter is then printed to file. Stdout was not achieve for this program */
        printf("You have selected the Substitution Cipher Decryption. The text encrypted by the substitution cipher encryption, written to decryptionFileTwo, will be decrypted and written to decryptionOutputFileTwo \n");
        char messageStringTwo[100], plainString[25], cipherStringTwo[25], encryptionCharacterThree, encryptionCharacterFour, encryptionCharacterFive;      //declare arrays for the encrypted message, the plain text alphabet, the cipher text alphabet, and variables that their elements will later be assigned to 
        int arrayCounterThree = 0, arrayCounterFour = 0, arrayCounterFive = 0, n = 0;                                                                       //declare and initialise variables used to view each element in the arrays, and a variable used to check for the same position in plain text and cipher text
        FILE *openReadingFileFive;                                                                          //declare a pointer to file                                       
        openReadingFileFive = fopen("decryptionFileTwo", "r");                                              //opening encrypted message file from last function. Initialise the pointer to file as containing the open file "decryptionFileTwo", suitable for reading from
        FILE *openReadingFileSix;                                                                           //declare a pointer to file
        openReadingFileSix = fopen("plainTextFile", "r");                                                   //Initialise the pointer to file as containing the open file "plainTextFile", suitable for reading from
        FILE *openReadingFileSeven;                                                                         //declare a pointer to file
        openReadingFileSeven = fopen("cipherTextFile", "r");                                                //Initialise the pointer to file as containing the open file "cipherTextFile", suitable for reading from
        FILE *openWritingFileFour;                                                                          //declare a pointer to file
        openWritingFileFour = fopen("decryptionOutputFileTwo", "w");                                       //Initialise the pointer to fiel as containing the open file "decryptionOutputFileTwo", suitable for writing to
        fread(cipherStringTwo, 2, 25, openReadingFileSeven);                                                //ciphertext file read into a string
        fread(messageStringTwo, 2, 100, openReadingFileFive);                                               //encrypted message file read into a string
        fread(plainString, 2, 25, openReadingFileSix);                                                      //plaintext file read into a string
        for (arrayCounterFour = 0; cipherStringTwo[arrayCounterFour] != '\0'; arrayCounterFour++)           //loop the following, one element in the array at a time, while it is not true that we are at the end of the array, i.e. run while the array has not ended
        {
            encryptionCharacterFour = cipherStringTwo[arrayCounterFour];                                    //assign the element in the array to the variable
            encryptionCharacterFour = encryptionCharacterFour - 32;                                         //-32 to make each letter capitalised
            cipherStringTwo[arrayCounterFour] = encryptionCharacterFour;                                    //reassign the variable's new value to the element in the array, which then increments and repeats for all letters 
        }
        // printf("%s \n", cipherStringTwo);                                                                //optional line to print ciphertext to check capitalisation
        for (arrayCounterFive = 0; plainString[arrayCounterFive] != '\0'; arrayCounterFive++)               //loop the following, one element in the array at a time, while it is not true that we are at the end of the array, i.e. run while the array has not ended
        {
            encryptionCharacterFive = plainString[arrayCounterFive];                                        //assign the element in the array to the variable
            encryptionCharacterFive = encryptionCharacterFive - 32;                                         //-32 to make each letter capitalised
            plainString[arrayCounterFive] = encryptionCharacterFive;                                        //reassign the variable's new value to the element in the array, which then increments and repeats for all letters
        }
        // printf("%s \n", plainString);                                                                    //optional line to print the plaintext to check capitalisation
        for (arrayCounterThree = 0; messageStringTwo[arrayCounterThree] != '\0'; arrayCounterThree++)       //loop the following, one element in the array at a time, while it is not true that we are at the end of the array, i.e. run while the array has not ended
        {
            encryptionCharacterThree = messageStringTwo[arrayCounterThree];                                 //assign the element in the array to the variable
            for (n = 0; cipherStringTwo[n] != '\0'; n++)                                                    //loop the following, one element in the array at a time, while it is not true that we are at the end of the array, i.e. run while the array has not ended
            {
                if (encryptionCharacterThree == cipherStringTwo[n])                                         //when the element in the cipher string is equal to the element in the message
                    fprintf(openWritingFileFour, "%c", plainString[n]);                                     //print to file, character by character, the plain text letter which occurs in the same position as the position at which the cipher text is equal to the encrypted text                                     
            }
        }  
    }
}