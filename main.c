#include<stdio.h>
#include<string.h>

#define MAX_BOOKS 100
#define MAX_USERS 100
#define APASSWORD "admin@*"

struct user{
    char name[30];
    int numBooks;
    int books[MAX_BOOKS];
}u;

struct user users[MAX_USERS];
int nofusers = 0;

void addBook(int userIndex, int bookId) {
    if (userIndex < 0 || userIndex >= nofusers) {
        printf("Invalid user index.\n");
        return;
    }
    if (users[userIndex].numBooks >= MAX_BOOKS) {
        printf("Maximum number of books reached for this user.\n");
        return;
    }
    users[userIndex].books[users[userIndex].numBooks++] = bookId;
    printf("Book added successfully.\n");
}

void adminSection(){
    char pw[9];
    printf("Enter the password : ");

    scanf("%s", pw);
    if( strcmp(pw, APASSWORD) != 0){
        printf("Invalid Password !\n");
    }
    
    if(nofusers == 0){
        printf("No users registered\n");
    } else {
        printf(" User details : \n");
        for(int i = 0; i< nofusers; i++) {
            printf("Index : %d, Name: %s \n", i, users[i].name);
        }
    }
}

void userSection(){
    int y,z;
    printf("1. New User\n");
    printf("2. Old User\n");
    printf("Enter your choice : ");
    scanf("%d", &y);
    switch(y){

        case 1:
        if (nofusers >= MAX_USERS) {
                printf("Maximum number of users reached.\n");
        } 
        printf("Enter your name : ");
        scanf("%s", users[nofusers].name);
        users[nofusers].numBooks = 0;
        printf("You have been registered with index %d.Remember this index for future use of your user portal\n", nofusers);
        nofusers ++;
        printf("Please enter the book ID if you've taken. Kindly press zero otherwise");
        scanf("%d", &z);
        if(z == 0){
            return;
        } else {
            addBook(nofusers,z);
        }

        case 2: {
            int index;
            printf("Enter your index: ");
            scanf("%d", &index);
            if (index < 0 || index >= nofusers) {
                printf("Invalid index.\n");
                return;
            }
            printf("Books taken by %s:\n", users[index].name);
            if (users[index].numBooks == 0) {
                printf("No books taken.\n");
            } else {
                printf("Book IDs: ");
                for (int i = 0; i < users[index].numBooks; i++) {
                    printf("%d ", users[index].books[i]);
                }
                printf("\n");
                printf("Please enter the book ID if you've taken. Kindly press zero otherwise");
                scanf("%d", &z);
                if(z == 0){
                    return;
                } else {
                    addBook(index,z);
                }
              }
              break;
           }
           default:
           printf("Invalid choice.\n");
       }
    }

int main(){
    int choice;
    while(1){
    printf(" Library Management System \n");
    printf(" 1.Admin \n");
    printf(" 2.User \n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
        adminSection();

        case 2:
        userSection();

        default :
        printf(" Invalid choice \n");

    }
  }
}