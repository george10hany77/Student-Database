#ifndef AMIT_PROJECT_SDB_H
#define AMIT_PROJECT_SDB_H
#include "STD.h"
#include <stdbool.h>

#define MAX_STUDENTS_NUMBER 10

typedef struct SimpleDb {
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
}student;

static uint8 numberOfStudents = 0;
static student* studentArray[MAX_STUDENTS_NUMBER];

bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeleteEntry (uint32 id);
bool SDB_ReadEntry (uint32 id);

void SDB_GetList ();

bool SDB_IsIdExist (uint32 id);

void SDB_APP ();

void SDB_ACTION(uint8 choice);

void readAllStudentsData();
#endif //AMIT_PROJECT_SDB_H
