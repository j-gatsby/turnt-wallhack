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
    char title = 0;
    int blocks_before_jpegs = 0;
    
    do
    {
		for (bytes_read =0;  bytes_read < BLOCK; bytes_read++)
		{
			// read card to buffer, one byte at a time
			fread(&buffer[bytes_read], sizeof(BYTE), 1, card);
		} 
		blocks_read++;
		
		// just for debugging
		printf("Bytes read = %d\n", bytes_read);
		printf("Blocks read = %d\n", blocks_read);
		
		// you have found the start of JPEG
		if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || 0xe1))
		{
			// close any previous file being written to
			if (title != 0)
			{
				fclose(title);
			}
			
			// sprintf and create new file to store jpg, naming it 00jpegs_found.jpg
			sprintf(title, "%02d.jpg", jpegs_found);
			
			// open new file
			FILE* card = fopen(title, "a");
			
			// verify that new file is not NULL
			if (title == NULL)
    		{
        		printf("Could not write to file.\n");
        		return 2;
    		}
			
			// write from buffer to new file
			fwrite(&buffer, sizeof(BYTE), BLOCK, title);
			
			// increment jpegs_found
			jpegs_found++;
		}
		
		// you have found a jpg and are writing to a new file
		else if (jpegs_found > 0)		
		{
			// keep writing to it
			fwrite(&buffer, sizeof(BYTE), BLOCK, title);
		}
		
		// you have not yet found the start of the jpegs
		else
		{
			// just move on to the next block
			blocks_before_jpegs++;
		}
    }// until the end of the file is reached
     while (feof == 0);
     
   // close the last file being written to
   fclose(title);
     
  // close memory card file
  fclose(card);  
}
