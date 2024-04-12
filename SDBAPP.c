#include <stdio.h>
#include "SDB.h"

void SDB_ACTION(uint8 choice){ // depending on the user's choice this function will add, delete,
    // gets the number of registered students, prints specific student's information, prints the list of IDs,
    //checks if a specific ID exists ,and checks if the database is full.
    switch (choice) {
        case 1:
            SDB_AddEntry();
            break;
        case 2:
            printf("\nUsed Size is:%hhu\n\n",SDB_GetUsedSize());
            break;
        case 3:
        {
            uint32 id;
            printf("Enter the student's ID to get data:");
            scanf("%u", &id);
            SDB_ReadEntry(id);
        }
            break;
        case 4:
            SDB_GetList();
            break;
        case 5:
        {
            uint32 id;
            printf("Enter ID to see if exists:");
            scanf("%u",&id);
            SDB_IsIdExist(id);
        }
            break;
        case 6:
        {
            uint32 id;
            printf("Enter ID to delete:");
            scanf("%u",&id);
            SDB_DeleteEntry(id);
        }
            break;
        case 7:
            if(SDB_IsFull()){
                printf("\nThe database is full\n\n");
            } else{
                printf("\nThe database is not full\n\n");
            }
            break;
        default:
            readAllStudentsData();
            break;
    }
}

void SDB_APP (){ // Infinite loop function to ask the user about the desired decision
    while (1) {
        uint8 choice;
        printf("\nTo add entry, enter 1\n"
               "To get used size in database, enter 2\n"
               "To read student data, enter 3\n"
               "To get the list of all student IDs, enter 4\n"
               "To check is ID is existed, enter 5\n"
               "To delete student data, enter 6\n"
               "To check is database is full, enter 7\n"
               "To exit enter 0\n"
               "To to print the whole database, type any other number\n----> ");
        scanf("%hhu", &choice);
        if(choice == 0) return;
        SDB_ACTION(choice);
    }
}
