#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <ifaddrs.h>
#include <stdlib.h>
#include <time.h>
#include "/usr/include/netinet/ether.h"
#include "/usr/include/netinet/ip.h"
#include "/usr/include/netinet/tcp.h"
#include "/usr/include/netinet/udp.h"
#include "/usr/include/arpa/inet.h"
#include "/usr/include/linux/if_ether.h"
#include "/usr/include/linux/icmp.h"
#include "/usr/include/pcap/bpf.h"
#include <pcap/pcap.h>
#include <time.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <pthread.h>
#define FILE_NAME_MAX 1024
#define IP_LIST_SIZE 16777216
#define size_of_IP 20
#define MIN_IP_LEN 7
#define ROW 100
#define COL 100
#define OCT 256
#define PROTO_ICMP 1
#define BUFFER_SIZE 65536

#define SYN 	1
#define NUL 	2
#define FIN	3
#define XMAS 	4
#define ACK 	5
#define UDP 	6
#define ALL	7

typedef struct ps_args_t {
	char filename[FILE_NAME_MAX];
	int total_ip_count;
	int total_port_count;
} ps_args_t;

typedef struct DNS_HEADER
{
    unsigned short id; // identification number
 
    unsigned char rd :1; // recursion desired
    unsigned char tc :1; // truncated message
    unsigned char aa :1; // authoritive answer
    unsigned char opcode :4; // purpose of message
    unsigned char qr :1; // query/response flag
 
    unsigned char rcode :4; // response code
    unsigned char cd :1; // checking disabled
    unsigned char ad :1; // authenticated data
    unsigned char z :1; // its z! reserved
    unsigned char ra :1; // recursion available
 
    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
} DNS_HEADER;

struct QUESTION
{
    unsigned short qtype;
    unsigned short qclass;
};
typedef struct
{
    unsigned char *name;
    struct QUESTION *ques;
} QUERY;

typedef struct job_queue {
	char q_ip[32];
	int q_port;
	int q_scan;
	char q_result[32];
}	job_queue;

typedef struct result_table {
	char r_ip[32];
	char r_service[50];
	int r_port;
	char r_version[30];
	char r_syn[32];
	char r_fin[32];
	char r_null[32];
	char r_xmas[32];
	char r_ack[32];
	char r_udp[32];
	char r_conclusion[32];
}	result_table;

struct pseudo_header
{
    u_int32_t source_address;
    u_int32_t dest_address;
    u_int8_t placeholder;
    u_int8_t protocol;
    u_int16_t tcp_length;
};

void dummy_func(int temp);
void print_help();
unsigned int ** parse_args(int argc, char** argv, ps_args_t* object, unsigned char ** ip_list, unsigned int ** port_list);
int read_ip_from_file(int ip_count, char * filename, unsigned char ** ip_list);
int parse_prefix(int ip_count, char * prefix, unsigned char ** ip_list);
unsigned int ** parse_ports(char * port_string, unsigned int** port_list, ps_args_t* object);
unsigned short csum_new(unsigned short *ptr,int nbytes);
int get_nic_addr(char * source_ip);
void * my_function (void * arg);
void changeHostFormat(unsigned char* dns,unsigned char* host);
void ServiceVersion(int port, char * d_ip, char * version);
void populateConclusionTable(int result_count, int port_count);
