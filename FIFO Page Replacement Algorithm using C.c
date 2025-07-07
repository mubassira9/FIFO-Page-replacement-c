


#include<stdio.h>

int main() {
    int incomingStream[] = {5, 3, 2, 5, 4};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming\tFrame1\tFrame2\tFrame3\n");

    int temp[frames];
    for (m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    int pos = 0; // position to replace

    for (m = 0; m < pages; m++) {
        s = 0;

        for (n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s = 1; // page hit
                break;
            }
        }

        if (s == 0) { // page miss
            temp[pos] = incomingStream[m];
            pos = (pos + 1) % frames;
            pageFaults++;
        }

        printf("%d\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf("%d\t", temp[n]);
            else
                printf("-\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    getch ();
}
