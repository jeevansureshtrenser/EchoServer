/************************************************************
* File name     : server.c
* Description   : source file for server implementation
* Author        : Jeevan Suresh
* License       : Copyright (c) 2025 Trenser 
                    All Rights Reserved
**************************************************************/

//******************************* Include Files ******************************* //
#include  <arpa/inet.h>
#include "config.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//******************************* Function Declaration ******************************* //

int InitializeServer(void);
int ReadFromClient(int socket, char* buffer, size_t read_bytes);
int SendToClient(int socket, const char* message);
int CleanupServer(int socket);

//******************************* Function Definition ******************************* //

/**********************************************************************
* Function name     : InitializeServer
* Description       : to initialize server
* Arguments         : void
* Return type       : int - socket file descriptor
*************************************************************************/
int InitializeServer(void)
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    ServerConfig* config = get_server_config();
    if(config == NULL) {
        perror("Failed to get server configuration");
        return -1;
    }
    else
    {
        /* No-op */
    }

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        return -1;
    }
    else
    {
        /* No-op */
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_port = htons(config->port);

    // Convert user string to binary form 
    if (inet_pton(AF_INET, config->ip, &address.sin_addr) <= 0) 
    { 
        perror("Invalid address");
        return -1;
    }
    else
    {
        /* No-op */
    }
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        return -1;
    }
    else
    {
        /* No-op */
    }

    // Listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        return -1;
    }
    else
    {
        printf("Server initialized with IP: %s, PORT: %d\n", config->ip, config->port);
    }
    
    printf("Waiting for connections on port %d...\n", config->port);
    // Accept a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        return -1;
    }
    printf("Connected to port %d...\n", PORT);
    return new_socket;
}

/**********************************************************************
* Function name     : ReadFromClient
* Description       : to read message from client
* Arguments         : int socket - socket file descriptor
*                   : char* buffer - buffer to store message
*                   : size_t read_bytes - number of bytes to read
* Return type       : int - 0 on success, -1 on error
*************************************************************************/
int ReadFromClient(int socket, char* buffer, size_t read_bytes)
{
    int n = read(socket, buffer, read_bytes);
    if (n <= 0) {
        return -1; // client closed connection or error
    }
    else
    {
        buffer[n] = '\0';
        printf("Message from client: %s\n", buffer);
    }
    return 0; // success
}

/**********************************************************************
* Function name     : SendToClient
* Description       : to send message to client
* Arguments         : int socket - socket file descriptor
*                   : const char* message - message to send
* Return type       : int - 0 on success, -1 on error
*************************************************************************/
int SendToClient(int socket, const char* message)
{
    if(send(socket, message, strlen(message), 0) < 0) {
        return -1; // error
    }
    else
    {
        printf("Echo message sent\n");
    }
    return 0; // success
}
/**********************************************************************
* Function name     : CleanupServer
* Description       : to cleanup server
* Arguments         : int socket - socket file descriptor
* Return type       : int - 0 on success, -1 on error
*************************************************************************/
int CleanupServer(int socket)
{
    if(close(socket) < 0) {
        return -1; // error
    }
    else
    {
        /* No-op */
    }
    return 0; // success
}
