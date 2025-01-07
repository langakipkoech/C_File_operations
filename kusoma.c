#include<fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int fd = open("readme.txt", O_CREAT | O_WRONLY, 0644);
    if(fd < 0){
        perror("open");
        return 1;
    }

    //write hello world to file
    write(fd, "Hello world\n",13);
    close(fd);

    //reopen file for reading
    fd = open("readme.txt", O_RDONLY);
    char buffer[128];

    //read file contents into buffer
    int bytesRead = read(fd, buffer, sizeof(buffer)-1);
    buffer[bytesRead] = '\0'; //null terminate

    //print file contents
    printf("File contents: %s", buffer);
    close(fd);

    return 0;
    
}