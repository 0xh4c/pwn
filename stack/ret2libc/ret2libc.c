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
