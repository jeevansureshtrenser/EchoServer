/************************************************************
* File name     : config.h
* Description   : header file for configuration
* Author        : Jeevan Suresh
* License       : Copyright (c) 2025 Trenser 
                    All Rights Reserved
**************************************************************/

#ifndef __CONFIG_H__
#define __CONFIG_H__ 

//******************************* Include Files ******************************* 
#include <arpa/inet.h>  

/******************************Macro Definitions******************************/
// Configuration header for Echo Server and Client
#define PORT 3000
#define SERVER_IP "0.0.0.0"
#define SUCCESS 0

/******************************Global Variable declaration******************************/
typedef struct {
    char* ip;
    int port;
} ServerConfig;
static const ServerConfig default_config = {
    SERVER_IP,
    PORT
};

/******************************Function declaration******************************/
extern ServerConfig* get_server_config();

#endif // __CONFIG_H__