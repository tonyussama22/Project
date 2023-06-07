#include "SDB.h"

student students[MAX_STUDENTS];
uint32 num_students = 0;

student s1;
student s2;
student s3;

// int main()
//{
// student s1 = {1, 1, 101, 90, 102, 80, 103, 85};
// students[num_students] = s1;
// num_students++;
// student s2 = {2, 2, 101, 85, 102, 90, 103, 95};
// students[num_students] = s2;
// num_students++;
// student s3 = {3, 1, 101, 80, 102, 75, 103, 70};
// students[num_students] = s3;
// num_students++;
// int n = SDB_GetUsedSize();
// printf("%d\n", n);
//  SDB_AddEntry();
// SDB_DeletEntry(1);
// SDB_ReadEntry(1);
// n = SDB_GetUsedSize();
// printf("%d\n", n);
//}
bool SDB_IsFull()
{
    if (num_students >= MAX_STUDENTS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

uint8 SDB_GetUsedSize()
{
    return num_students;
}

bool SDB_AddEntry()
{
    student new;
    printf("Enter your ID: ");
    scanf("%d", &new.Student_ID);
    printf("Enter your Year: ");
    scanf("%d", &new.Student_year);
    printf("Enter your Course 1 ID: ");
    scanf("%d", &new.Course1_ID);
    printf("Enter your Course 1 grade: ");
    scanf("%d", &new.Course1_grade);
    printf("Enter your Course 2 ID: ");
    scanf("%d", &new.Course2_ID);
    printf("Enter your Course 2 grade: ");
    scanf("%d", &new.Course2_grade);
    printf("Enter your Course 3 ID: ");
    scanf("%d", &new.Course3_ID);
    printf("Enter your Course 3 grade: ");
    scanf("%d", &new.Course3_grade);

    if (SDB_IsFull())
    {
        printf("Cannot add more students. Maximum student limit reached.\n");
        return false;
    }
    else
    {
        students[num_students] = new;
        num_students++;
        return true;
    }
}

void SDB_DeletEntry(uint32 id)
{
    uint32 t = 0;
    for (uint32 i = 0; i < num_students; i++)
    {
        if (students[i].Student_ID == id)
        {
            students[i] = students[num_students - 1];
            num_students--;
            t = 1;
            printf("Student removed successfully.\n");
            break;
        }
        if (t == 0)
        {
            printf("ID Number not in Database\n");
        }
    }
}
bool SDB_ReadEntry(uint32 id)
{
    uint32 i;
    for (i = 0; i < num_students; i++)
    {
        if (students[i].Student_ID == id)
        {
            printf("Student ID: %d\n", students[i].Student_ID);
            printf("Student Year: %d\n", students[i].Student_year);
            printf("Student Course 1 Grade: %d\n", students[i].Course1_grade);
            printf("Student Course 2 Grade: %d\n", students[i].Course2_grade);
            printf("Student Course 3 Grade: %d\n", students[i].Course3_grade);
            break;
        }
    }
    if (i == num_students)
    {
        printf("ID not in Database\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
void SDB_GetList(uint8 *count, uint32 *list)
{
    *count = num_students;
    for (uint32 i = 0; i < num_students; i++)
    {
        list[i] = students[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id)
{

    for (uint32 i = 0; i < num_students; i++)
    {
        if (students[i].Student_ID == id)
        {
            return 1;
        }
    }
    return 0;
}
