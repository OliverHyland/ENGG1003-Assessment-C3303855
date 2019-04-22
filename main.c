#include <stdio.h>

int main ()
{
    char encryptionText[] = "the lazy fox jumped over the log";                                               //hard-coded array of text, a string
    char encryptionKey = 3;                                                             //declare and initialise a key for encyrption
    int arrayCounter, encryptionElement;                                                //declare a variable to increment and point to elements in the array, and a variable to assign elements to, in order to add the key
    for (arrayCounter = 0; encryptionText[arrayCounter] != '\0'; arrayCounter++)        //from the start of the string, continue so long as the string has not reached its end, incrementing after each loop
    {
        encryptionElement = encryptionText[arrayCounter];                               //an element in the encryptionText string is given by the (arrayCounter)th position
        if (encryptionElement >= 'a' && encryptionElement <= 'z')                       //when the element is between a and z, -32 to capitalise the letter according to the ASCII table
            encryptionElement = encryptionElement - 32;
        if (encryptionElement >= 'A' && encryptionElement <= 'Z')                       //for A to Z, add the key to each element in the array
        {
            encryptionElement = encryptionElement + encryptionKey;
            if (encryptionElement > 'Z')                                                //when the element is over Z, let it be that minus the length of the alphabet in order to loop around
            encryptionElement = encryptionElement - 26;                                 
        }
        encryptionText[arrayCounter] = encryptionElement;                               //assign the new element with the added key back to the (arrayCounter)th position in the encyrptionText array. Loop then starts again, incrementing the position in the array and applying the same process, adding the key to the next element and re-assigning it
    }
    printf("%s", encryptionText);                                                       //print the string after each element has had the key added to it
}



        
