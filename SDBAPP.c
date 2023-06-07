#include "SDB.h"
#include <stdio.h>


void SDB_APP()
{
    while (1)
    {
        int choice = 0;
        printf("\n");
        printf("To add entry, enter 1\n");
        printf("To get used size in database, enter 2\n");
        printf("To read student data, enter 3\n");
        printf("To get the list of all student IDs, enter 4\n");
        printf("To check is ID is existed, enter 5\n");
        printf("To delete student data, enter 6\n");
        printf("To check is database is full, enter 7\n");
        printf("To exit enter 0\n");
        scanf("%d", &choice);
        SDB_action(choice);
    }
}

void SDB_action(uint8 choice)
{
    uint8 count;
    uint32 list[MAX_STUDENTS];
    int id1 = 0;

    switch (choice)
    {
    case 1:
        SDB_AddEntry();
        break;

    case 2:
        SDB_GetUsedSize();
        break;
    case 3:
        printf("Please Enter ID Number to read");
        scanf("%d", &id1);
        SDB_ReadEntry(id1);
        break;

    case 4:
        SDB_GetList(&count, list);
        break;

    case 5:
        printf("Please Enter ID Number to check if existed");
        scanf("%d", &id1);
        SDB_IsIdExist(id1);
        break;

    case 6:
        printf("Please Enter ID Number to delete");
        scanf("%d", &id1);
        SDB_DeletEntry(id1);
        break;

    case 7:
        SDB_IsFull();
        break;

    case 0:
        break;

    default:
        printf("Invalid choice. Please enter a number from 0-7.\n");
        break;
    }
}
