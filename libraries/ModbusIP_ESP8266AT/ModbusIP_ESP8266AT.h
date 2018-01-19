/*
    ModbusIP_ESP8266AT.h - Header for Modbus IP ESP8266 AT Library
    Copyright (C) 2015 André Sarmento Barbosa
*/
#include <Arduino.h>
#include <Modbus.h>
#include <ESP8266.h>

#ifndef MODBUSIP_ESP8266AT_H
#define MODBUSIP_ESP8266AT_H

#define MODBUSIP_PORT     502 ///< TCP/IP port of MODBUS service
#define MODBUSIP_MAXFRAME 200 ///< Maximum length of frame
#define MODBUSIP_TIMEOUT  10  ///< timeout of TCP Server by second

/**
 * @class ModbusIP_ESP8266AT
 * @brief Modbus over TCP/IP network Class for Wi-Fi ESP8266 AT controller
 */
class ModbusIP : public Modbus {
#ifndef __DOXYGEN__
    private:
        byte _MBAP[7];
        ESP8266* _wifi;
    bool prev_conn;
#endif

    public:
        /**
         * @brief Default constructor
         */
        ModbusIP();
        /**
         * @brief Connect a ModbusIP object to a network
         * @param wifi ESP8266 NIC object
         * @param ssid SSID of AP to join in
         * @param password Password of AP to join in
         */
        void config(ESP8266 &wifi, String ssid, String password);
        /**
         * @brief Task that performs all operations on MODBUS
         * 
         * Call once inside loop(), all magic here !
         */
        void task();
};

#endif //MODBUSIP_ESP8266AT_H

