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
extern int InitializeServer(void);
extern int ReadFromClient(int socket, char* buffer, size_t read_bytes);
extern int SendToClient(int socket, const char* message);
extern int CleanupServer(int socket);

#endif // __SERVER_H__