#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct lotto_record {
    int lotto_no;
    float lotto_receipt;
    int emp_id;
    char lotto_date[10];
    char lotto_time[10];
    } lotto_record_t;

typedef struct emp_record {
    int emp_id;
    char emp_name[20];
    int emp_salary;
} emp_record_t;

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

    FILE* operator_id;
    int read_temp1[5];
    int write_temp1[] = {1};
    if (!(operator_id = fopen("operator_id.bin", "rb+"))) {
        operator_id = fopen("operator_id.bin", "wb+");
        fwrite(write_temp, sizeof(int), 1, operator_id);
    } else {
        fseek(operator_id, 0, SEEK_SET);
        fread(read_temp, sizeof(int), 1, operator_id);
        write_temp[0] = read_temp[0] + 1;
        fseek(operator_id, 0, SEEK_SET);
        fwrite(write_temp, sizeof(int), 1, operator_id);
    }
    fseek(operator_id, 0, SEEK_SET);
    fread(read_temp, sizeof(int), 1, operator_id);
    fclose(operator_id);

    FILE *fp;
    int n, Op_id, Op_salary;
    char Op_name[20];
    FILE* recordbin;
    if ((recordbin = fopen("record.bin", "rb+")) == NULL) {
        recordbin = fopen("record.bin", "wb+");
        fclose(recordbin);
    }
    recordbin = fopen("record.bin", "ab");
    char buff[10];
    time_t now = time(0);

    lotto_record_t lotto;
    lotto.lotto_no = read_temp[0];
    lotto.lotto_receipt = n * 50 * 1.1;
    lotto.emp_id = Op_id;
    strftime (buff, 100, "%Y%M%D", localtime(&now));
    strcpy(lotto.lotto_date, buff);
    strftime (buff, 100, "%H:%M:%S", localtime(&now));
    strcpy(lotto.lotto_time, buff);

    fwrite(&lotto, sizeof(lotto), 1, recordbin);
    fclose(recordbin);
    printf("歡迎光臨長庚樂透彩購買機台\n請輸入操作人員ID(0-5) : ");
    scanf("%d", &Op_id);

    if (Op_id == 0) {
        emp_record_t emp;
        fopen("operator_id.bin", "ab");
        printf("請輸入要新增操作人員ID(1-99) : ");
        scanf("%d", &Op_id);
        printf("請輸入要新增操作人員Name : ");
        scanf("%s", &Op_name[20]);
        printf("請輸入要新增操作人員Salary : ");
        scanf("%d", &Op_salary);
        printf("輸入完成");
        emp.emp_id = Op_id;
        for (int i=0; i<20; i++) {
            emp.emp_name[i] = Op_name[i];
        }
        emp.emp_salary = Op_salary;
        fwrite(&emp, sizeof(emp), 1, operator_id);
        fclose(operator_id);
    }

    printf("請問您要買幾組樂透彩(1-5) : ");
    scanf("%d", &n);
    int a[6];
    int b[70];
    int c;
    for (int i=1; i<70; i++) {
    b[i]=i;
}
    char filename[50];
    snprintf(filename, sizeof(filename), "lotto[%05d].txt",write_temp[0]);
    fp = fopen(filename,"w+");
    time_t curtime;
    time(&curtime);
    fprintf(fp,"========= lotto022 =========\n");
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
                a[i] = rand() % 69 + 1;
                for ( ; b[a[i]]==0; ) {
                    a[i] = rand() % 69 + 1;
                }
                b[a[i]]=0;
            }
            for (int i=1; i<70; i++) {
                if (b[i] == 0) {
                    if (i < 10) {
                        fprintf(fp,"0");
                    }
                    fprintf(fp,"%d ", i );
                }
            }
            c = (rand() % 10)+1;
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
    fprintf(fp,"========* Op.%.5d *========\n", Op_id);
    fprintf(fp,"========= csie@CGU =========");
     printf("已為您購買的%d組樂透組合輸出至%s\n", n, filename);
    fclose(fp);
    return 0;
}
