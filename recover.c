/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
 #include <stdint.h>
 
 #define BLOCK 512
 
 typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{
    // open memory card file
    FILE *card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Could not open card.\n");
        return 1;
    }
    
    // temporary storage
   BYTE buffer[BLOCK];
   
   // total number of blocks read off of card
    int blocks_read = 0;
    int bytes_read;
    
    // find start of JPEGs
    for (bytes_read =0;  bytes_read < BLOCK; bytes_read++)
    {
    	// read card to buffer, one byte at a time
    	fread(&buffer[bytes_read], sizeof(BYTE), 1, card);
    	
    } 
    blocks_read++;
    
    printf("Bytes read = %d\n", bytes_read);
    printf("Blocks read = %d\n", blocks_read);
    
  // close memory card file
  fclose(card);  
}
