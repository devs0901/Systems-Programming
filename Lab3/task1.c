/*

Task 1

Write a C program to do the following.
1. Open and read the “Input.txt” file into C. You can choose the method in which to
read the file.
2. Change every instance of “a” to “b”. In the phrase “Systems Programming”, the
output should be “Systems Programming”.
3. After having changed all instances of “a” to “b”, write to file “Heaven.txt” the
changes.
4. Comment your code and make sure the code handles error conditions.

Note: 	In order to completely know if the code works, everything in Heaven.txt file was deleted 
and the C file was compiled and executed. The updated Heaven.txt file is attached below.

*/

#include <stdio.h> 
#include <stdlib.h>
int main()
{

        FILE *in_file = fopen ("Input.txt","r");
        //parameter r for 'open for reading'

        FILE *out_file = fopen ("Heaven.txt","w");
        //parameter w for 'open for writing’

        char c; //initialize a value of c

        //check if the file exist
        if (in_file == NULL || out_file == NULL){
                printf ("No such file");
                exit (-1); //stdlib.h was used for this
        }


        while ((c = getc(in_file)) != EOF) //EOF indicates end of file
                // ?: ternary operator was used
		fputc (c== 'a' ? 'b': c, out_file);

		//let the user know that the program is finished
                printf("Finished writing to file \n");

                fclose(in_file); //close the Input.txt file
                fclose(out_file); //close the Heaven.txt file
                return 0;
}
