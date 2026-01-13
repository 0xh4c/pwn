// gcc -o ret2shellcode ret2shellcode.c -fno-stack-protector -no-pie -z execstack -O0

#include <stdio.h>

// declare gets manually (since modern libc removed it)
char *gets(char *s);

void vuln() {
    char buf[256];
    printf("Address is Everything: %p\n", (void*)buf); // print buffer address
    printf("Input: ");
    gets(buf); // unsafe, intentional
}

int main() {
    vuln();
    return 0;
}
