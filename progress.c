#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];

    //open source file for reading
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd < 0){
        perror(" Error opening source file! ");
        return 1;
    }

    //open or create destination file for 
    int dest_fd = open(destination_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (dest_fd < 0 ){
        perror(" Error opening destination file\n ");
        close(source_fd);
        return 1;
        }

    //get the size of the source file
    struct stat file_stat;
    if (stat(source_file, &file_stat) < 0){
        perror("Error getting source file size\n ");
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    off_t total_size = file_stat.st_size;

    //initialize variables for file copying
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    off_t copied_size = 0;

    //display copying
    printf("Copying....\n");

    while((bytes_read = read(source_fd, buffer,sizeof(buffer)))>0){
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_read < 0){
            perror("Error writing to destination file\n ");
            close(source_fd);
            close(dest_fd);
            return 1;
        }

        //update copied size and display progress
        copied_size += bytes_written;
        int progress = (int)((copied_size * 100)/total_size);
        printf("\rProgress: %d%%", progress);
        fflush(stdout);
    } 

    if (bytes_read < 0){
        perror(" Error reading from source file");
    }

    printf("\n Copy completed .\n");

    close(source_fd);
    close(dest_fd);

    return 0;


}