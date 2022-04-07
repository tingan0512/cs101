#include <stdio.h>

void rec_dec (char* arr) {
    if(*(arr) != 0) {
        printf("%c,", arr[0]);
        rec_dec(++arr);
    }
    return;
}

void Tower_of_Hanoi(int n, char from, char to, char aux){
    if (n == 1) {
        FILE* fp = fopen("hanoi.txt", "a+");
        fprintf(fp,"Move disk 1 from rod %c to rod %c\n", from, to);
        fclose(fp);
        return;
    }
    Tower_of_Hanoi(n-1, from, aux, to);
    FILE* fp = fopen("hanoi.txt", "a+");
    fprintf(fp, "Move disk %d from rod %c to rod %c\n", n, from, to);
    fclose(fp);
    Tower_of_Hanoi(n-1, aux, to, from);
    return;
}

void hanoi_tower (int amount) {
    FILE* fp;
    if ((fp = fopen("hanoi.txt", "r+")) == NULL) {
        fp = fopen("hanoi.txt", "w+");
        fclose(fp);
        
        Tower_of_Hanoi(amount, 'A', 'C', 'B');
        fp = fopen("hanoi.txt", "a+");
        fprintf(fp,"\n\n\n\n\n\n\n");
        fclose(fp);
    } else {
        Tower_of_Hanoi(amount, 'A', 'C', 'B');
        fp = fopen("hanoi.txt", "a+");
        fprintf(fp, "\n==================\n");
        fclose(fp);
    }
    return;
}

void multiplication (int i, int j) {
    printf("%d*%d=%d\t", i, j, i*j);
    if (j < 9) {
        multiplication(i, j+1);
        return;
    } else {
        if (i < 9) {
            printf("\n");
            multiplication(i+1, j-8);
            return;
        }
    }
    return;
}

int main () {
    char input[] = "1234567890";
    rec_dec(input);
    printf("\nfunction#1------------\n");
    hanoi_tower(16);
    printf("\nfunction#2------------\n");
    multiplication(1, 1);
    printf("\nfunction#3------------\n");
    return 0;
}