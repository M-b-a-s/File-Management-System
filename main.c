// libraries
#include <stdio.h>
#include <stdlib.h>

// function to create file
void createFile(){
    FILE *file;
    char fileName[50];

    printf("Enter the file name: ");
    scanf("%s", fileName);

    file = fopen(fileName, "w");

    if(file == NULL) {
        printf("\033[1;31mError creating file!!\033[0m");
        exit(1);
    }

    fclose(file);
    printf("File created successfully");
}

// function to read a file
void readFile(){
    FILE *file;
    char fileName[50], ch;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if(file == NULL){
        printf("Error Creating File!!");
        exit(1);
    }

    printf("File content:\n");
    while((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);
}

// function to write to a file
void writeFile() {
    FILE *file;
    char fileName[50], content[100];

    printf("Enter the file name: ");
    scanf("%s",  fileName);

    file = fopen(fileName, "a");

    if(file == NULL){
        printf("Error Creating File");
        exit(1);
    }

    printf("Enter the content to write:\n");
    scanf("%[^\n]", content);

    fprintf(file, "%s", content);
    fclose(file);
    printf("Content written successfully\n");

}

// function to delete file
void deleteFile() {
    int status;
    char fileName[50];

    printf("Enter the file name: ");
    scanf("%s", fileName);

    status = remove(fileName);

    if(status == 0) {
        printf("File deleted succesfully");
    } else {
        printf("Error deleting file!!");
        exit(1);
    }
}


int main() {
    int choice;

    while(1) {
        printf("========== File Management System =========\n");
        printf("1.Create file\n");
        printf("2.Read a file\n");
        printf("3.Write to a file\n");
        printf("4.Delete a file\n");
        printf("5.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                writeFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}