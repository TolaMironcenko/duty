//
// Created by Анатолий Миронченко on 29.10.2022.
//

#include <stdio.h>
#include <string.h>

void print_duty_sum() {
    FILE *sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/sum", "r");
    float sum;
    fscanf(sumfile,"%f",&sum);
    fclose(sumfile);
    printf("Sum of duty: -%.2f\n", sum);
}

int add_duty_sum(float sum) {
    FILE *sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/sum", "r");
    FILE *transactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/transactions", "a+w");

    char *tofile = "Transaction: ";
    fputs(tofile, transactionsfile);
    fputs("-", transactionsfile);
    fprintf(transactionsfile, "%.2f", sum);
    fputs("\n", transactionsfile);

    float newsum;
    fscanf(sumfile,"%f", &newsum);
    fclose(sumfile);
    sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/sum", "w");
    newsum += sum;
    fprintf(sumfile, "%.2f", newsum);
    printf("Sum of duty: -%.2f\n", newsum);

    fclose(sumfile);
    fclose(transactionsfile);
    return 0;
}

int del_duty_sum(float sum) {
    FILE *sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/sum", "r");
    FILE *transactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/transactions", "a+w");

    char *tofile = "Transaction: ";
    fputs(tofile, transactionsfile);
    fputs("+", transactionsfile);
    fprintf(transactionsfile, "%.2f", sum);
    fputs("\n", transactionsfile);

    float newsum;
    fscanf(sumfile,"%f", &newsum);
    fclose(sumfile);
    sumfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/sum", "w");
    newsum -= sum;
    fprintf(sumfile, "%.2f", newsum);
    printf("Sum of duty: -%.2f\n", newsum);

    fclose(sumfile);
    fclose(transactionsfile);
    return 0;
}

void print_transactions() {
    FILE *transactionsfile = fopen("/Users/anatolijmironcenko/Documents/c/duty/transactions", "r");
    char trans[50];
    memset(&trans, '\0', 50);

    while (fgets(trans, sizeof(trans), transactionsfile) != NULL) {
        printf("%s", trans);
    }
    fclose(transactionsfile);
}