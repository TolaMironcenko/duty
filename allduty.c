#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_all_duty_sum(); 
void print_all_transactions();
void print_all_info();

int main(int argc, char *argv[]) {

	system("clear");
    if (argc < 2) {
        printf("Use %s [some command] or -h to show list of commands\n", argv[0]);
        exit(0);
    }

    if (!strcmp(argv[1], "sum")) {
        print_all_duty_sum();
    }

    if (!strcmp(argv[1], "transactions")) {
        print_all_transactions();
    }

    if (!strcmp(argv[1], "inf") || !strcmp(argv[1], "-i") || !strcmp(argv[1], "info") || !strcmp(argv[1], "i")) {
        print_all_info();
    }

	return 0;
}

void print_all_duty_sum() {
	FILE *sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/sum", "r");
	FILE *sumtinkofffile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkoffsum", "r");
    float sum;
    float tinkoffsum;
    fscanf(sumfile,"%f",&sum);
    fscanf(sumtinkofffile, "%f", &tinkoffsum);
    fclose(sumtinkofffile);
    fclose(sumfile);
    float allsum = sum + tinkoffsum;
    printf("Sum of duty: -%.2f\n", allsum);
}

void print_all_transactions() {
    FILE *transactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/transactions", "r");
    FILE *tinkofftransactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkofftransactions", "r");

    char trans[50];
    memset(&trans, '\0', 50);

    printf("MOM:\n");
    while (fgets(trans, sizeof(trans), transactionsfile) != NULL) {
        printf("%s", trans);
    }
    memset(&trans, '\0', 50);

    printf("\nTINKOF:\n");
    while (fgets(trans, sizeof(trans), tinkofftransactionsfile) != NULL) {
        printf("%s", trans);
    }
    fclose(transactionsfile);
    fclose(tinkofftransactionsfile);
}

void print_all_info() {
    FILE *transactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/transactions", "r");
    FILE *tinkofftransactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkofftransactions", "r");
    FILE *sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/sum", "r");
    FILE *sumtinkofffile = fopen("/Users/anatolijmironcenko/Documents/c/duty/tinkoffsum", "r");
    char trans[50];
    memset(&trans, '\0', 50);
    float sum, tinkoffsum;
    fscanf(sumfile,"%f",&sum);
    fscanf(sumtinkofffile, "%f", &tinkoffsum);

    printf("MOMEDUTY: -%.2f\n", sum);
    printf("MOM:\n");
    while (fgets(trans, sizeof(trans), transactionsfile) != NULL) {
        printf("%s", trans);
    }
    memset(&trans, '\0', 50);

    printf("\nTINKOFFDUTY: -%.2f\n", tinkoffsum);
    printf("TINKOF:\n");
    while (fgets(trans, sizeof(trans), tinkofftransactionsfile) != NULL) {
        printf("%s", trans);
    }
    fclose(transactionsfile);
    fclose(tinkofftransactionsfile);
    fclose(sumfile);
    fclose(sumtinkofffile);
}