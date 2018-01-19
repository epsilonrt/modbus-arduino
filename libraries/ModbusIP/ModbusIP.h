/*
    ModbusIP.h - Header for Modbus IP Library
    Copyright (C) 2015 André Sarmento Barbosa
*/
#include <Arduino.h>
#include <Modbus.h>
#include <SPI.h>
#include <Ethernet.h>

#ifndef MODBUSIP_H
#define MODBUSIP_H

#define MODBUSIP_PORT     502 ///< TCP/IP port of MODBUS service
#define MODBUSIP_MAXFRAME 200 ///< Maximum length of frame

//#define TCP_KEEP_ALIVE

/**
 * @class ModbusIP
 * @brief Modbus over TCP/IP network Class for Arduino Ethernet shield
 */
class ModbusIP : public Modbus {
#ifndef __DOXYGEN__
    private:
        EthernetServer _server;
        byte _MBAP[7];
#endif
    public:
        /**
         * @brief Default constructor
         */
        ModbusIP();
        /**
         * @brief Connect a ModbusIP object to a network
         * @param mac the MAC (Media access control) address for the device 
         * (array of 6 bytes). this is the Ethernet hardware address of your shield. 
         * Newer Arduino Ethernet Shields include a sticker with the device's 
         * MAC address. For older shields, choose your own. 
         */
        void config(uint8_t *mac);
        /**
         * @brief Connect a ModbusIP object to a network
         * @param mac the MAC (Media access control) address for the device 
         * (array of 6 bytes). this is the Ethernet hardware address of your shield. 
         * Newer Arduino Ethernet Shields include a sticker with the device's 
         * MAC address. For older shields, choose your own. 
         * @param ip the IP address of the device (array of 4 bytes) 
         */
        void config(uint8_t *mac, IPAddress ip);
        /**
         * @brief Connect a ModbusIP object to a network
         * @param mac the MAC (Media access control) address for the device 
         * (array of 6 bytes). this is the Ethernet hardware address of your shield. 
         * Newer Arduino Ethernet Shields include a sticker with the device's 
         * MAC address. For older shields, choose your own. 
         * @param ip the IP address of the device (array of 4 bytes) 
         * @param dns the IP address of the DNS server (array of 4 bytes). 
         * optional: defaults to the device IP address with the last octet set to 1 
         */
        void config(uint8_t *mac, IPAddress ip, IPAddress dns);
        /**
         * @brief Connect a ModbusIP object to a network
         * @param mac the MAC (Media access control) address for the device 
         * (array of 6 bytes). this is the Ethernet hardware address of your shield. 
         * Newer Arduino Ethernet Shields include a sticker with the device's 
         * MAC address. For older shields, choose your own. 
         * @param ip the IP address of the device (array of 4 bytes) 
         * @param dns the IP address of the DNS server (array of 4 bytes). 
         * optional: defaults to the device IP address with the last octet set to 1 
         * @param gateway the IP address of the network gateway (array of 4 bytes). 
         * optional: defaults to the device IP address with the last octet set to 1 
         */
        void config(uint8_t *mac, IPAddress ip, IPAddress dns, IPAddress gateway);
        /**
         * @brief Connect a ModbusIP object to a network
         * @param mac the MAC (Media access control) address for the device 
         * (array of 6 bytes). this is the Ethernet hardware address of your shield. 
         * Newer Arduino Ethernet Shields include a sticker with the device's 
         * MAC address. For older shields, choose your own. 
         * @param ip the IP address of the device (array of 4 bytes) 
         * @param dns the IP address of the DNS server (array of 4 bytes). 
         * optional: defaults to the device IP address with the last octet set to 1 
         * @param gateway the IP address of the network gateway (array of 4 bytes). 
         * optional: defaults to the device IP address with the last octet set to 1 
         * @param subnet the subnet mask of the network (array of 4 bytes). optional: defaults to 255.255.255.0 
         */
        void config(uint8_t *mac, IPAddress ip, IPAddress dns, IPAddress gateway, IPAddress subnet);
        /**
         * @brief Task that performs all operations on MODBUS
         * 
         * Call once inside loop(), all magic here !
         */
        void task();
};

#endif //MODBUSIP_H

