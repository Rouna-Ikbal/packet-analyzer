#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdio.h>

#include "packet.h"

void analyze_packet(unsigned char *buffer) {
  struct iphdr *ip_header;
  ip_header = (struct iphdr *)(buffer + 14);
  struct sockaddr_in src;
  struct sockaddr_in dst;

  src.sin_addr.s_addr = ip_header->saddr;
  dst.sin_addr.s_addr = ip_header->daddr;
  printf("===================");
  printf("Packet Received\n");
  printf("===================");
  printf("Source IP: %s\n", inet_ntoa(src.sin_addr));
  printf("Destination IP: %s", inet_ntoa(dst.sin_addr));
  printf("Protocol: ");
  switch (ip_header->protocol) {
  case 1:
    printf("ICMP\n");
    break;
  case 6:
    printf("TCP\n");
    break;
  case 17:
    printf("UDP\n");
    break;
  default:
    printf("OTHER (%d)", ip_header->protocol);
  }
  printf("TTL: %d\n", ip_header->ttl);
  printf("Packet Length: %d bytes", ntohs(ip_header->tot_len));
}