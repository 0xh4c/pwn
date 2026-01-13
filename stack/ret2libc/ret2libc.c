#include <stdio.h>
#include <string.h>

void vulnerable_function() {
    char buffer[64];
    printf("Enter some text: ");
    gets(buffer); 
    printf("You entered: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    vulnerable_function();
    return 0;
}
//gcc -fno-stack-protector -z noexecstack -Wno-error=implicit-function-declaration -o ret2libc ret2libc.c
