// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>

#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/

int readValidID(void) {
   int id;
   printf("Enter student ID: ");
   while (1){
      id = readInt();
      if (id >= 1000000 && id <= 9999999)
         return id;
      else
         printf("Not valid. Enter a valid value: ");
   }
}

int readValidCredits(void) {
   int cr;
   printf("Enter credit points: ");
   while (1){
      cr = readFloat();
      if (cr >= 2 && cr <= 400)
         return cr;
      else
         printf("Not valid. Enter a valid value: ");
   }
}

float readValidWAM(void) {
   float wam;
   printf("Enter WAM: ");
   while (1){
      wam = readFloat();
      if (wam >= 50.0 && wam <= 100.0)
         return wam;
      else
         printf("Not valid. Enter a valid value: ");
   }
}

void printStudentData(int zID, int credits, float WAM) {
   printf("------------------------\n");
   printf("Student zID: z%d\n", zID);
   printf("Credits: %d\n", credits);
   printf("Level of performance: ");
   if (WAM >= 85)
      printf("HD\n");
   else if (WAM >= 75)
      printf("DN\n");
   else if (WAM >= 65)
      printf("CR\n");
   else if (WAM >= 50)
      printf("PS\n");
   printf("------------------------\n");
   return;
}
