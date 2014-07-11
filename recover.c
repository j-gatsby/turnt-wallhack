/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
 
 #define JPEG_SIG0 0xff 0xd8 0xff 0xe0*
 #define JPEG_SIG1 0xff 0xd8 0xff 0xe1*
 
 typedef uint8_t  BYTE;
 typedef{uint8_t*512} BLOCK;

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
   
   // total number of blocks read off of card
    int blocks_read = 0;
    
    // read card to buffer, one block at a time
    fread(&buffer, sizeof(BYTE), BLOCK, card);
    
    
}
