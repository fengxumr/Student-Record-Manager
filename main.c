/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Student record manager

     COMP9024 17s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"

void printHelp();
void StudentLinkedListProcessing();

void  print_statistics(studentRecordT *, int);

int main(int argc, char *argv[]) {
   if (argc == 2) {
      int i = atoi(argv[1]);

      studentRecordT *sr = malloc(sizeof(studentRecordT) * i);
      assert(sr != NULL);

      for (int j = 0; j < i; j++){
         (sr+j)->zID = readValidID();
         (sr+j)->credits = readValidCredits();
         (sr+j)->WAM = readValidWAM();
      }

      for (int k = 0; k < i; k++){
         printStudentData((sr+k)->zID, (sr+k)->credits, (sr+k)->WAM);
      }

      float total_wam = 0.0, total_weight_wam = 0.0, total_credits = 0.0;
      for (int l = 0; l < i; l++){
         total_wam += (sr+l)->WAM;
         total_weight_wam += (sr+l)->WAM * (sr+l)->credits;
         total_credits += (sr+l)->credits;
      }
      printf("Average WAM: %.3f\n", total_wam / i);
      printf("Weighted average WAM: %.3f\n", total_weight_wam / total_credits);
      
   } else {
      StudentLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void StudentLinkedListProcessing() {
   int op, ch, n;
   float wam = 0.0, w_wam = 0.0;

   List list = newLL();   // create a new linked list
   while (1) {
      printf("Enter command (a,f,g,p,q, h for Help)> ");

      do {
         ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      
      while (ch != '\n') {          // skip the rest of the line until newline is encountered
         ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
            insertLL(list, readValidID(), readValidCredits(), readValidWAM());
            break;

         case 'f':
         case 'F':
            inLL(list, readValidID());
            break;
	    
         case 'g':
         case 'G':
            getStatLL(list, &n, &wam, &w_wam);
            printf("Number of records: %d\n", n);
            printf("Average WAM: %.3f\n", wam);
            printf("Average weighted WAM: %.3f\n", w_wam);
            break;
	    
         case 'h':
         case 'H':
            printHelp();
	         break;
	    
         case 'p':
         case 'P':
            showLL(list);
	         break;

	      case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	         printf("Bye.\n");
	         return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" A - Add student record\n" );
   printf(" F - Find student record\n" );
   printf(" G - Get statistics\n" );
   printf(" H - Help\n");
   printf(" P - Print all records\n" );
   printf(" Q - Quit\n");
   printf("\n");
}

