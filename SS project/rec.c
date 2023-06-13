#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp1;
    int i, j, hexaddr, start_hexaddr;
    char line[50], addr[10];

    fp1 = fopen("C:\\Users\\dell\\OneDrive\\Documents\\input.txt", "r");
    if (fp1 == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    printf("Enter the actual starting address: ");
    if (scanf("%x", &start_hexaddr) != 1) {
        printf("Invalid starting address.\n");
        fclose(fp1);
        return 1;
    }

    do {
        fscanf(fp1, "%s", line);
        if (line[0] == 'T') {
            for (i = 1, j = 0; i < 7 && j < 10; i++, j++)
                addr[j] = line[i];
            addr[j] = '\0';

            hexaddr = strtoul(addr, NULL, 16);

            i = 9;
            while (line[i] != '\0') {
                printf("%x \t%c%c\n", hexaddr + start_hexaddr, line[i], line[i + 1]);
                hexaddr++;
                i += 2;
            }
        }
    } while (!feof(fp1));

    fclose(fp1);
    return 0;
}
