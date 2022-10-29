#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_duty_sum();

int add_duty_sum(float sum);

int del_duty_sum(float sum);

void print_transactions();

int main(int argc, char *argv[]) {
    system("clear");
    if (argc < 2) {
        printf("Use %s [some command] or -h to show list of commands\n", argv[0]);
        exit(0);
    }
    if (!strcmp(argv[1], "sum")) {
        print_duty_sum();
    }
    if (!strcmp(argv[1], "add") || !strcmp(argv[1], "+")) {
        if (argc < 3) {
            printf("Use %s %s [sum]", argv[0], argv[1]);
            exit(0);
        } else {
            add_duty_sum(atof(argv[2]));
        }
    }
    if (!strcmp(argv[1], "del") || !strcmp(argv[1], "-")) {
        if (argc < 3) {
            printf("Use %s %s [sum]", argv[0], argv[1]);
            exit(0);
        } else {
            del_duty_sum(atof(argv[2]));
        }
    }
    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help")) {
        printf("1) sum - sum of duty\n2) add - add duty\n3) del - del duty\n4) -h or -help - help\n");
    }
    if (!strcmp(argv[1], "transactions")) {
        print_transactions();
    }
    return 0;
}

void print_duty_sum() {
    FILE *sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkoffsum", "r");
    float sum;
    fscanf(sumfile, "%f", &sum);
    fclose(sumfile);
    printf("Sum of duty: -%.2f\n", sum);
}

int add_duty_sum(float sum) {
    FILE *sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkoffsum", "r");
    FILE *transactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkofftransactions", "a+w");

    char *tofile = "Transaction: ";
    fputs(tofile, transactionsfile);
    fputs("-", transactionsfile);
    fprintf(transactionsfile, "%.2f", sum);
    fputs("\n", transactionsfile);

    float newsum;
    fscanf(sumfile, "%f", &newsum);
    fclose(sumfile);
    sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkoffsum", "w");
    newsum += sum;
    fprintf(sumfile, "%.2f", newsum);
    printf("Sum of duty: -%.2f\n", newsum);

    fclose(sumfile);
    fclose(transactionsfile);
    return 0;
}

int del_duty_sum(float sum) {
    FILE *sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkoffsum", "r");
    FILE *transactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkofftransactions", "a+w");

    char *tofile = "Transaction: ";
    fputs(tofile, transactionsfile);
    fputs("+", transactionsfile);
    fprintf(transactionsfile, "%.2f", sum);
    fputs("\n", transactionsfile);

    float newsum;
    fscanf(sumfile, "%f", &newsum);
    fclose(sumfile);
    sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkoffsum", "w");
    newsum -= sum;
    fprintf(sumfile, "%.2f", newsum);
    printf("Sum of duty: -%.2f\n", newsum);

    fclose(sumfile);
    fclose(transactionsfile);
    return 0;
}

void print_transactions() {
    FILE *transactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkofftransactions", "r");
    char trans[50];
    memset(&trans, '\0', 50);

    while (fgets(trans, sizeof(trans), transactionsfile) != NULL) {
        printf("%s", trans);
    }
    fclose(transactionsfile);
}