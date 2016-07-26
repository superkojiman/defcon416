/* gcc -fno-stack-protector -o pwn10 pwn10.c */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void win() {
    char buf[100];
    int fd = 0; 
    fd = open("flag", O_RDONLY);
    memset(buf, 0, 100); 
    read(fd, buf, 200); 
    close(fd);
    puts(buf);
}

int main(int argc, char *argv[]) {
    char buf[100];

    puts("Hello Defcon 416!");
    puts("Reply: "); 

    if (open("flag", O_RDONLY) < 0) {
        puts("No flag file found!");
    } else {
        memset(buf, 0, 100); 
        read(0, buf, 200); 
    }
    puts("What's the flag?");
    return 0; 
}
