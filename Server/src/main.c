/************************************************************
* File name     : main.c
* Description   : source file for server main function
* Author        : Jeevan Suresh
* License       : Copyright (c) 2025 Trenser
                    All Rights Reserved
**************************************************************/

//******************************* Include Files ******************************* //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "config.h"
#include "server.h"

//******************************* Function Definition ******************************* //

int main()
{
    char buffer[1024] = {0};
    int new_socket;
    // Initialize server
    new_socket = InitializeServer();
    if (new_socket < 0) {
        perror("Failed to initialize server");
        exit(EXIT_FAILURE);
    }
    // Echo loop
    while(1)
    {

        if(ReadFromClient(new_socket,buffer, sizeof(buffer)) != SUCCESS) {
            printf("Client disconnected.\n");
            break;
        }
        if(SendToClient(new_socket,buffer) != SUCCESS) {
            printf("Failed to send message to client.\n");
            break;
        }
        
    }
    CleanupServer(new_socket);
    return 0;
}
