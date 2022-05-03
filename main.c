#include <stdio.h>
#include <dirent.h>
#include <string.h>

char programme_name[50];
char password[50];

void registerCommand(){
    printf("Enter the name of the programme: ");
    scanf("%s", &programme_name);

    FILE *fp;
    char buff[255];

    DIR *dir;
    struct dirent *entry;
    int files = 0;

    dir = opendir(".");

    FILE *file;    
    while((entry=readdir(dir))){
        files++;
        

        if(file = fopen(programme_name, "r"))
        {
            printf("File already exists.\n");
            break;
        } 
        else
        {
            fp = fopen(programme_name, "w+");
    
            printf("Enter your password: ");
            scanf("%s", &password);
            fprintf(fp, password);
            fclose(fp);
            break;
        }
    }
    
    closedir(dir);
}

void delete_entry(){
   printf("Enter the name of the programme: ");
    scanf("%s", &programme_name);

    FILE *fp;
    char buff[255];

    DIR *dir;
    struct dirent *entry;
    int files = 0;

    dir = opendir(".");

    FILE *file;    
    while((entry=readdir(dir))){
        files++;
        

        if(file = fopen(programme_name, "r"))
        {
            remove(programme_name);
            printf("Entry deleted.\n");
            break;
        } 
        else
        {
            printf("File doesn't exist.\n");
            break;
        }
    }
    
    closedir(dir);
    
}

void open_entry(){
    printf("Enter the name of the programme: ");
    scanf("%s", &programme_name);

    FILE *fp;
    char buff[255];

    DIR *dir;
    struct dirent *entry;
    int files = 0;

    dir = opendir(".");

    FILE *file;    
    while((entry=readdir(dir))){
        files++;
        

        if(file = fopen(programme_name, "r"))
        {
            fgets(buff, 255, file);
            printf("The password is: %s\n", buff);           
            break;
        } 
        else
        {
            printf("File doesn't exist.\n");   
            break;
        }
    }
    
    closedir(dir);
}


int main(int argc, char **argv){
    
    if(argc == 1){
        printf("Not enought arguments.\n");
        printf("register, delete, open\n");
    }

    char option[9];

    size_t option_length = sizeof(option);

    strncpy(option, argv[1], option_length);

    if((strcmp(option, "register")) == 0)
    {
        registerCommand();
    }
    else if(strcmp(option, "delete") == 0)
    {
        delete_entry();
    }
    else if(strcmp(option, "open") == 0)
    {
        open_entry();
    }
    else
    {   
        printf("Invalid option.\n");
    }

    return 0;
}
