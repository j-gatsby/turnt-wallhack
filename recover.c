/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>			// for I/O operations
 #include <stdint.h>		// for uint8_t
 #include <string.h>		// for memset
 
 #define BLOCK 512
 
 typedef uint8_t  BYTE;

int main(void)
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
   
    int bytes_read;
    BYTE jpegs_found = 0;
    int blocks_before_jpegs = 0;
    char title;
    
    // per gcc error message: will not compile without initializing to NULL
    FILE* new_file = NULL;
    
    // until the end of the file is reached...
    while (feof(card) == 0)	
    {
    	// clear out the buffer
    	memset(buffer, '\0', sizeof(buffer));
    	
		for (bytes_read =0;  bytes_read < BLOCK; bytes_read++)
		{
			// read card to buffer, one byte at a time
			fread(&buffer[bytes_read], sizeof(BYTE), 1, card);
			
			// check first byte for end of file
			if (bytes_read < 1)
			{
				// if the end of the file is found
				if (feof(card) != 0)
				{
					// close the file being written to
					fclose(new_file);
					
					// close the memory card being read from
					fclose(card);
					
					// exit the program successfully
					return 0;
				}
			}
		} 
		// if you have found the start of JPEG
		if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
		{
			// close any previous file being written to
			if (new_file != NULL)
			{
				fclose(new_file);
			}
			
			// sprintf and create new file to store jpg, naming it 00jpegs_found.jpg
			sprintf(&title, "%03d.jpg", jpegs_found);
			
			// open the new file
			new_file = fopen(&title, "a");
			
			// verify that new file is not NULL
			if (new_file == NULL)
    		{
    			// if it is NULL, exit the program with an error
        		printf("Could not write to file.\n");
        		return 2;
    		}

				// write from buffer to new file			
				fwrite(&buffer, sizeof(buffer), 1, new_file);
				
				// increment counter for number of jpgs found
				jpegs_found++;
		}	
		// if you have already found a jpg and are writing to a new file
		else if (jpegs_found > 0 && new_file != NULL)		
		{
			// keep writing to it
				fwrite(&buffer, sizeof(buffer), 1, new_file);
		}
			
		// if you have not yet found the start of the jpegs
		else
		{
			// just move on to the next block
			blocks_before_jpegs++;
		}
    } 
   
   // close the last file being written to
   fclose(new_file);
     
  // close memory card file and exit the program
  fclose(card); 
}
