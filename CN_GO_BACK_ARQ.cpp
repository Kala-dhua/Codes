
#include <stdio.h>

int main()
{
    int n, window, i, lost;

    printf("=== GO-BACK-N ARQ ===\n");

    printf("Enter total number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &window);

    printf("\nStarting transmission...\n");

    i = 1;

    while (i <= n)
    {
        int end = i + window - 1;

        if (end > n)
            end = n;

        printf("\nSending frames %d to %d\n", i, end);

        printf("Enter frame number lost (0 if none): ");
        scanf("%d", &lost);

        if (lost >= i && lost <= end)
        {
            printf("\nFrame %d lost!\n", lost);

            printf("Receiver discards subsequent out-of-order frames.\n");

            printf("Go back and retransmit from Frame %d\n", lost);

            i = lost;
        }
        else
        {
            printf("All frames acknowledged successfully.\n");

            i = end + 1;
        }
    }

    printf("\nTransmission completed successfully!\n");

    return 0;
}

