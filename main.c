#include <stdio.h>

int main ()
{
    char encryptionText[] = "apples";                                                   //hard-coded array of text, a string
    char encryptionKey = 3;                                                             //declare and initialise a key for encyrption
    int arrayCounter, encryptionElement;                                                //declare a variable to increment and point to elements in the array, and a variable to assign elements to, in order to add the key
    for (arrayCounter = 0; encryptionText[arrayCounter] != '\0'; arrayCounter++)        //from the start of the string, continue so long as the string has not reached its end, incrementing after each loop
    {
        encryptionElement = encryptionText[arrayCounter];                               //an element in the encryptionText string is given by the (arrayCounter)th position
        if (encryptionElement >= 'A' && encryptionElement <= 'Z')                       //for capital letters, + 32 to make them lower case
            encryptionElement = encryptionElement + 32;                          
        if (encryptionElement >= 'a' && encryptionElement <= 'z')                       //read for all letters between a to z
        {
            encryptionElement = encryptionElement + encryptionKey;                      //let each element be assigned to the value of that element plus the key
            if (encryptionElement > 'z')                                                //when an element has an ASCII value outside a to z, subtract the value of z to allow it to loop around to a again (maybe)
            encryptionElement = encryptionElement - 'z'; 
        }
        encryptionText[arrayCounter] = encryptionElement;                               //assign the new element with the added key back to the (arrayCounter)th position in the encyrptionText array. Loop then starts again, incrementing the position in the array and applying the same process, adding the key to the next element and re-assigning it
    }
    printf("%s", encryptionText);                                                       //print the string after each element has had the key added to it
}



        