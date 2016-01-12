# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main(void) {


    printf("Disproving.\n");

    sleep(1);

    int res;
    int self = getpid();
    int count = 0;

    while (1) {

        res = fork();

        if (res < 0) {
            fprintf(stderr, "Fork error\n");
            fprintf(stderr, "Total number of forked() processes: %d\n", count);
            exit(1);
        }

        if (res == 0)
            return 0;

        count += 1;

        if (res < self)
            printf("\033[91m[%d] > [%d]\033[0m\n", self, res);
        else
            printf("\033[92m[%d] < [%d]\033[0m\n", self, res);

        usleep(1000);
    }

    return 0;

}
