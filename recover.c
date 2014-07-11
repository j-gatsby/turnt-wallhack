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
    int jpegs_found = 0;
    
    do
    {
		for (bytes_read =0;  bytes_read < BLOCK; bytes_read++)
		{
			// read card to buffer, one byte at a time
			fread(&buffer[bytes_read], sizeof(BYTE), 1, card);
		} 
		blocks_read++;
		
		printf("Bytes read = %d\n", bytes_read);
		printf("Blocks read = %d\n", blocks_read);
		
		// find start of JPEG
		if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || 0xe1))
		{
			// close any previous file being written to
			// sprintf and create new file to store jpg
			// increment jpegs_found
		}
		else if (// you are writing to a jpg file)
		{
			// keep writing to it
		}
		else
		{
			// just move on to the next block
		}
    }// until the end of the file is reached
    
  // close memory card file
  fclose(card);  
}
