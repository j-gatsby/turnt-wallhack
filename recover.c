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
    FILE *file = fopen("card.raw", "r");
    
}
