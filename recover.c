/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
 
 #define BLOCK 512
 
 typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{
    // open memory card file
    FILE *card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", card);
        return 1;
    }
    
    // temporary storage
   BYTE buffer;
    
    // read card to buffer, one block at a time
    fread(&buffer, sizeof(BYTE), BLOCK, card);
    
    
}
