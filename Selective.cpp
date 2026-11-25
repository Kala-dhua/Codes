
#include <stdio.h>

int main()
{
    int n, window, i, lost, ack;

    printf("=== SELECTIVE REPEAT ARQ ===\n");

    printf("Enter total number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &window);

    i = 1;

    while (i <= n)
    {
        int end = i + window - 1;

        if (end > n)
            end = n;

        printf("\nSending frames %d to %d\n", i, end);

        printf("Enter lost frame number (0 if none): ");
        scanf("%d", &lost);

        if (lost >= i && lost <= end)
        {
            printf("\nFrame %d is lost!\n", lost);

            printf("Other frames are accepted and buffered if needed.\n");

            printf("Retransmitting only Frame %d\n", lost);

            printf("Enter 1 if Frame %d is received correctly: ", lost);
            scanf("%d", &ack);

            if (ack == 1)
            {
                printf("Frame retransmitted successfully.\n");
            }

            i = end + 1;
        }
        else
        {
            printf("All frames received successfully.\n");

            i = end + 1;
        }
    }

    printf("\nTransmission completed!\n");

    return 0;
}

