# packet-analyzer

## Overview

A packet capture and analysis utility developed in C using Linux Raw Sockets. The tool captures network packets and extracts important networking information from IPv4 packets.

## Features

- Raw Packet Capture
- IPv4 Header Parsing
- Source IP Extraction
- Destination IP Extraction
- Protocol Detection
- Packet Length Analysis
- TTL Inspection

## Technologies Used

- C Programming
- Linux Networking
- Raw Sockets
- TCP/IP
- IPv4
- GCC

## Build

chmod +x build.sh

./build.sh

## Run

sudo ./build/packet_analyzer

## Sample Output

====================================
PACKET RECEIVED
====================================

Source IP      : 192.168.1.10
Destination IP : 8.8.8.8
Protocol       : TCP
TTL            : 64
Packet Length  : 52 bytes

## Networking Concepts Covered

- Ethernet Frame
- IPv4 Header
- TCP
- UDP
- ICMP
- Raw Sockets
- Network Byte Order

## Skills Demonstrated

- Linux Networking
- Packet Processing
- Protocol Analysis
- System Programming
- Socket Programming
