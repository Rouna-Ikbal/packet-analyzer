#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#include <linux/if_ether.h>

#include "packet.h"

int main() {
  int sockfd;
  int count = 0;
  unsigned char buffer[65536];

  printf("Starting Packet Analyser...\n");

  sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

  if (sockfd < 0) {
    perror("socket");
    return 1;
  }
  printf("Waiting for packets...\n");
  // to capture 10 packets
  while (count < 10) {
    size_t packet_size;
    packet_size = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);

    if (packet_size < 0) {
      perror("recvfrom");
      continue;
    }
    analyze_packet(buffer);
    count++;
  }
  close(sockfd);
  return 0;
}