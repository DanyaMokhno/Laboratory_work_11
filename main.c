#include <stdio.h>
#include <stdlib.h>

typedef union IPv4
{
    unsigned short address[4];
    unsigned short class: 8;
} IPv4;

void get_ip(IPv4 *ip)
{
    printf("input ip address\n");
    scanf("%hd.%hd.%hd.%hd", &(ip->address[0]), &(ip->address[1]), &(ip->address[2]), &(ip->address[3]));
}

void short_to_bin(unsigned short b)
{
    int i;
    for (i = 7; i >= 0; i--) printf("%d", (b >> i) & (0x1));
}

void change_class_of_ip(IPv4 *ip)
{
//    printf("-----------------------------\n");
//    short_to_bin(ip->class);
//    putchar('\n');
    ip->class = ip->class ^ (1 << 7);
    if ((ip->class & ((1 << 6)))) ip->class = ip->class & (~(1 << 6));
//    printf("%d\n", ip->class);
//    short_to_bin(ip->class);
//    putchar('\n');
//    printf("-----------------------------\n");
}

void show_ip(IPv4 *ip)
{
    int i;
    printf("%hd.%hd.%hd.%hd\n", ip->address[0], ip->address[1], ip->address[2], ip->address[3]);
    for (i = 0; i < 4; i++)
    {
        short_to_bin(ip->address[i]);
        putchar('.');
    }
    putchar(8);
    putchar('\n');
}

int main()
{
    IPv4 *ip;

    ip = malloc(sizeof(IPv4));
    get_ip(ip);
    show_ip(ip);
    change_class_of_ip(ip);
    show_ip(ip);
    free(ip);

    return 0;
}
/*
Class A:

10.0.0.1
10.20.30.40
10.100.100.100
123.45.67.89

Class B:

172.16.0.1
172.17.20.50
172.31.255.254
*/