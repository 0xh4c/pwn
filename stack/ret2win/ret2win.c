 // gcc -o ret2win ret2win.c -fno-stack-protector -no-pie -O0

#include <stdio.h>

// declare gets manually (removed from modern stdio.h)
char *gets(char *s);

void ret2win() {
    puts("flag{ret_2_win}");
}

void vuln() {
    char buf[64];
    printf("Enter Your Name: ");
    gets(buf); // vulnerable: buffer overflow
    printf("Hello %s",buf);
}

int main() {
    vuln();
    return 0;
}



