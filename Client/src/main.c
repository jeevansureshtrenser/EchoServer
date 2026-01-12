#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "config.h"
#include "client.h"

int main() 
{
    int sock = 0;
    char* buffer = (char*)malloc(1024 * sizeof(char));
    int sock = initializeClient();
    if (sock < 0) {
        perror("Failed to initialize client");
        exit(EXIT_FAILURE);
    }   
    else
    {
        /* No-op */
    }

    // Send message
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) 
        { 
            if(SendToServer(sock, buffer, strlen(buffer)) == 0)
            {
                // Read echo message
                memset(buffer, 0, sizeof(buffer));
                if(ReadFromServer(sock, buffer, sizeof(buffer)) == 0)
                {
                    printf("Echo from server: %s", buffer);
                }
                else
                {
                    printf("Failed to read from server.\n");
                    break;
                }
            } 
            else 
            {
                printf("Failed to send to server.\n");
                break;
            }
        }
    }
    close(sock);
    free(buffer);
    return 0;
}
