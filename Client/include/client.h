/************************************************************
* File name     : config.h
* Description   : header file for configuration
* Author        : Jeevan Suresh
* License       : Copyright (c) 2025 Trenser 
                    All Rights Reserved
**************************************************************/

#ifndef __SERVER_H__
#define __SERVER_H__
/******************************Function declaration******************************/
extern int InitializeClient(void);
extern int ReadFromServer(int socket, char* buffer, size_t read_bytes);
extern int SendToServer(int socket, const char* message, size_t message_length);
extern int CleanupClient(int socket);

#endif // __SERVER_H__