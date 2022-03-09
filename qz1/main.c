#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	FILE* counterbin;
    int read_temp[5];
    int write_temp[] = {1};
    if (!(counterbin = fopen("counter.bin", "rb+"))) {
        counterbin = fopen("counter.bin", "wb+");
        fwrite(write_temp, sizeof(int), 1, counterbin);
    } else {
        fseek(counterbin, 0, SEEK_SET);
        fread(read_temp, sizeof(int), 1, counterbin);
        write_temp[0] = read_temp[0] + 1;
        fseek(counterbin, 0, SEEK_SET);
        fwrite(write_temp, sizeof(int), 1, counterbin);
    }
    fseek(counterbin, 0, SEEK_SET);
    fread(read_temp, sizeof(int), 1, counterbin);
    fclose(counterbin);
    FILE *fp;
    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩 : ");
    scanf("%d", &n);
    char filename[50];
    snprintf(filename, sizeof(filename), "lotto[%05d].txt",write_temp[0]);
    fp = fopen(filename,"w+");
    int a[6];
    int b[70];
    int c;
    for (int i=1; i<70; i++) {
        b[i]=i;
    }
    time_t curtime;
    time(&curtime);
    fprintf(fp,"======== lotto022 ==========\n");
	fprintf(fp, "========+ No.%.5d +========\n", read_temp[0]);
    fprintf(fp, "= ");
    srand(time(NULL));
	for (int g = 0; g <= 23; g++) {
	    fprintf(fp, "%c", ctime(&curtime)[g]);
	}
	fprintf(fp, " =\n");
    for (int x=1; x<=5; x++) {
        if (x <= n) {
            fprintf(fp,"[%d]:", x);
            for (int i=0; i<6; i++) {
                a[i] = rand() % 70;
                for ( ; b[a[i]]==0; ) {
                    a[i] = rand() % 70;
                }
                b[a[i]]=0;
            }
            for (int i=1; i<=70; i++) {
                if (b[i] == 0) {
                    if (i < 10) {
                        fprintf(fp,"0");
                    }
                    fprintf(fp,"%d ", i );
                }
            }
            c=(rand() % 10)+1;
            if (c<10) {
                fprintf(fp,"0");
            }
            fprintf(fp,"%d ",c);
        } else {
            fprintf(fp,"[%d]: -- -- -- -- -- -- --", x);
        }
        fprintf(fp,"\n");
        for (int i=1; i<70; i++) {
            b[i]=i;
        }
    }
    fprintf(fp,"======== csie@CGU ==========");
	printf("已為您購買的%d組樂透組合輸出至%s\n", n, filename);
    fclose(fp);
    return 0;
}
