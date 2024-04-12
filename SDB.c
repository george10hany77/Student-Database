// I used the array approach. we could have used the linked list ,but I chose this one because
// we can access the elements much faster than the linked list :)
#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

bool SDB_IsFull (){ // checks if the array is full
    return (numberOfStudents >= MAX_STUDENTS_NUMBER);
}

uint8 SDB_GetUsedSize(){ // Gets the size of used elements in the array
    return numberOfStudents;
}

bool SDB_AddEntry(){ // to add a student in the database
    if(SDB_IsFull()){
        printf("\nThe Database is full. You can't add data !!\n");
        return 0;
    }
    // storing a student variable in the memory (dynamically allocated).
    student *newStudent = (student *) malloc(sizeof(student));

    // taking the data from the user
    printf("Enter Student's ID:");
    scanf("%u",&(newStudent->Student_ID));
    printf("Enter Student's Year:");
    scanf("%u",&(newStudent->Student_year));
    printf("Enter Student's Course1_id:");
    scanf("%u",&(newStudent->Course1_ID));
    printf("Enter Student's Course1_grade:");
    scanf("%u",&(newStudent->Course1_grade));
    printf("Enter Student's Course2_id:");
    scanf("%u",&(newStudent->Course2_ID));
    printf("Enter Student's Course2_grade:");
    scanf("%u",&(newStudent->Course2_grade));
    printf("Enter Student's Course3_id:");
    scanf("%u",&(newStudent->Course3_ID));
    printf("Enter Student's Course3_grade:");
    scanf("%u",&(newStudent->Course3_grade));

    // incrementing the total number of students
    numberOfStudents++;

    // storing the student "pointer" in the array of pointers of students.
    for (int i = 0; i < MAX_STUDENTS_NUMBER; ++i) {
        if(studentArray[i] == NULL) {
            studentArray[i] = newStudent;
            break;
        }
    }

    return 1;
}

void SDB_DeleteEntry (uint32 id){ // to delete a student from the database
    bool flag = 1;
    for (int i = 0; i < MAX_STUDENTS_NUMBER; ++i) {
        student *ptr = studentArray[i];
        if(studentArray[i] != NULL && studentArray[i]->Student_ID == id){
            free(ptr); // to free this location in memory
            ptr = NULL;
            studentArray[i] = NULL;
            numberOfStudents--; // decrementing the total number of registered students in the database
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("\n___DELETION_FAILED___\n\n");
    else
        printf("\n___DELETION_COMPLETED___\n\n");
}

bool SDB_ReadEntry (uint32 id){ // to read all the information of the student with specific ID
    for (int i = 0; i < MAX_STUDENTS_NUMBER; ++i) {
        if(studentArray[i] != NULL && studentArray[i]->Student_ID == id){
            printf("\nStudent ID:%u\n", studentArray[i]->Student_ID);
            printf("Student Year:%u\n", studentArray[i]->Student_year);
            printf("Course1 ID:%u\n", studentArray[i]->Course1_ID);
            printf("Course1_grade:%u\n", studentArray[i]->Course1_grade);
            printf("Course2_ID:%u\n", studentArray[i]->Course2_ID);
            printf("Course2_grade:%u\n", studentArray[i]->Course2_grade);
            printf("Course3_ID:%u\n", studentArray[i]->Course3_ID);
            printf("Course3_grade:%u\n\n", studentArray[i]->Course3_grade);
            return 1;
        }
    }
    printf("This student doesn't exist\n");
    return 0;
}

void SDB_GetList (){ // Prints out the list of students IDs
    printf("\nList of IDs: [");
    for (int i = 0; i < MAX_STUDENTS_NUMBER; ++i){
        if(studentArray[i] != NULL){
            printf("%u ,",studentArray[i]->Student_ID);
        }
    }
    printf("]\n\n");
}

bool SDB_IsIdExist (uint32 id){ // Checks if a specific ID exists
    for (int i = 0; i < MAX_STUDENTS_NUMBER; ++i)
        if(studentArray[i] != NULL && studentArray[i]->Student_ID == id){
            printf("\nYES, the student's ID exists\n\n");
            return 1;
        }
    printf("\nNO, the student's ID doesn't exists\n\n");
    return 0;
}

void readAllStudentsData(){ // "EXTRA FUNCTION" prints all information of all the students in the database
    bool flag = 0;
    printf("=====================================================\n");
    for (int i = 0; i < MAX_STUDENTS_NUMBER; ++i) {
        if(studentArray[i] != NULL) {
            SDB_ReadEntry(studentArray[i]->Student_ID);
            flag = 1;
            printf("=====================================================\n\n");
        }
    }
    if(!flag)
        printf("Nothing to print\n\n");
}