#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(unsigned char *user_data, const struct pcap_pkthdr *pkthdr, const unsigned char *packet) {
    printf("Packet captured with length: %d\n", pkthdr->len);
    // Add packet analysis logic here
}

int main() {

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the network interface for packet sniffing
    handle = pcap_open_live("your_network_interface", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", "your_network_interface", errbuf);
        return 2;
    }

    // Start packet sniffing loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the handle when done
    pcap_close(handle);
    printf("Successful\n");

    return 0;
}
