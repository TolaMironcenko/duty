//
// Created by Анатолий Миронченко on 29.10.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duty.h"

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