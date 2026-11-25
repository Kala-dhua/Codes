#include <stdio.h>  
  
int main()  
{  
    int n, i;     
int ack;  
  
    printf("Enter the number of frames: ");     
scanf("%d", &n);  
  
    for (i = 1; i <= n; i++)  
    {  
        printf("\nSender: Sending Frame %d\n", i);  
  
        printf("Receiver: Frame %d received\n", i);  
  
        printf("Was ACK received for Frame %d? (1=Yes, 0=No): ", i);         
scanf("%d", &ack);  
  
        while (ack == 0)  
        {  
            printf("ACK lost! Retransmitting Frame %d\n", i);  
  
            printf("Receiver: Frame %d received again\n", i);  
  
            printf("Was ACK received now? (1=Yes, 0=No): ");             
scanf("%d", &ack);  
        }  
  
        printf("Sender: ACK received for Frame %d\n", i);  
    }  
  
    printf("\nAll frames transmitted successfully.\n");  
  
    return 0;  
}  

