#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    // Something like this, may be?

    FILE *stream;
    unsigned char *contents;
    long fileSize = 0;
    long i = 0;

    // Open the stream. Note "b" to avoid DOS/UNIX new line conversion.
    // stream = fopen(argv[1], "rb");
    stream = fopen(argv[1], "rb");

    // Seek to the end of the file to determine the file size
    fseek(stream, 0L, SEEK_END);
    fileSize = ftell(stream);
    fseek(stream, 0L, SEEK_SET);

    // Allocate enough memory (add 1 for the \0, since fread won't add it)
    contents = malloc(fileSize + 1);

    // Read the file
    size_t size = fread(contents, 1, fileSize, stream);
    // contents[size] = 0;  // Add terminating zero.



    long j = 0;


    for (i = 0; i < size;)
    {
        //printf("%d   ",i);
        printf("   ");
        for (j = 0; j < 25; j++)
        {
            printf("%d", contents[i + j]);
            if ((i == 0 && j == 23) || j == 24)
            {
                printf("\n");
                //getchar();
                i += j + 1;
                break;
            }
        }
    }

    // Close the file
    fclose(stream);
    free(contents);
}

//Writebin
// int main(int argc, char *argv[])
// {
//     // Something like this, may be?

//     FILE *stream;
//     unsigned char *contents;
//     unsigned char *contents8bit;
//     long fileSize = 0;
//     long i = 0;

//     // Open the stream. Note "b" to avoid DOS/UNIX new line conversion.
//     // stream = fopen(argv[1], "rb");
//     stream = fopen(argv[1], "rb");

//     // Seek to the end of the file to determine the file size
//     fseek(stream, 0L, SEEK_END);
//     fileSize = ftell(stream);
//     fseek(stream, 0L, SEEK_SET);

//     // Allocate enough memory (add 1 for the \0, since fread won't add it)
//     contents = malloc(fileSize + 1);
//     contents8bit = malloc(fileSize + 1);

//     // Read the file
//     size_t size = fread(contents, 1, fileSize, stream);
//     // contents[size] = 0;  // Add terminating zero.

//     memset(contents8bit, 0, size);

//     // Print it again for debugging
//     printf("In: %d%d%d%d %d%d%d%d\n", contents[0], contents[1], contents[2], contents[3], contents[4], contents[5], contents[6], contents[7]);

//     printf("Out: %02X\n", contents[i] | (contents[i + 1] << 1) |
//                               (contents[i + 2] << 2) | (contents[i + 3] << 3) |
//                               (contents[i + 4] << 4) | (contents[i + 5] << 5) |
//                               (contents[i + 6] << 6) | (contents[i + 7] << 7));

//     long j = 0;

//     for (i = 0; i < size; i += 8) {
//         contents8bit[j] = contents[i] | (contents[i + 1] << 1) |
//                           (contents[i + 2] << 2) | (contents[i + 3] << 3) |
//                           (contents[i + 4] << 4) | (contents[i + 5] << 5) |
//                           (contents[i + 6] << 6) | (contents[i + 7] << 7);
//         j++;
//     }
//     j--;
    
//     FILE *write_ptr;

//     write_ptr = fopen(argv[2], "wb"); // w for write, b for binary
//     fwrite(contents8bit, ((size / 8) - (size / 8 % 16)), 1,
//            write_ptr); // write 10 bytes from our buffer

//     fclose(write_ptr);
//     // Close the file
//     fclose(stream);
//     free(contents);
// }


//Old
// int main() {
//     unsigned char buffer[24];
//     FILE *ptr;

//     ptr = fopen("../data1.dat", "rb");  // r for read, b for binary

//     fread(buffer, sizeof(buffer), 1, ptr);  // read 10 bytes to our buffer
//     for (int i = 0; i < sizeof(buffer); i++)
//         printf("%u", buffer[i]);  // prints a series of bytes

//     printf("\n");

//     FILE *write_ptr;

//     write_ptr = fopen("test.bin", "wb");  // w for write, b for binary

//     fwrite(buffer, sizeof(buffer), 1,
//            write_ptr);  // write 10 bytes from our buffer

//     fclose(ptr);
//     return 0;
// }