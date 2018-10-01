#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
   studentRecordT data;
   struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;
   int len;
} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: consuming constant time
List newLL() {
   List new = malloc(sizeof(ListRep));
   assert(new != NULL);
   new->head = NULL;
   new->len = 0;
   return new;
}


// Time complexity: O(n)
// Explanation: linear time, depends on how many nodes in the link list
void dropLL(List listp) {
   NodeT *p = listp->head;
   while (p != NULL){
      NodeT *temp = p->next;
      free(p);
      p = temp;
   }
   return;
}

// Time complexity: O(n)
// Explanation: take linear time in the worst case that each of the record will be compared
void inLL(List listp, int zid) {
   NodeT *p = listp->head;

   while (p != NULL){
      if (p->data.zID == zid){
         printStudentData(p->data.zID, p->data.credits, p->data.WAM);
         return;
      }
      p = p->next;
   }
   printf("No record found.\n");
   return;
}

// Time complexity: O(n)
// Explanation: take linear time in the worst case that each of the record will be compared
void insertLL(List listp, int zid, int cr, float wam) {
   NodeT *p = listp->head;
   NodeT *new_node = malloc(sizeof(NodeT));
   assert(new_node != NULL);
   new_node->data.zID = zid;
   new_node->data.credits = cr;
   new_node->data.WAM = wam;

   if (!listp->len){
      listp->head = new_node;
      listp->len++;
      new_node->next = NULL;
   }
   else{
      while (1){
         if (p->data.zID > zid){
            NodeT *temp = listp->head;
            listp->head = new_node;
            new_node->next = temp;
            listp->len++;
            break;
         } else if (p->data.zID < zid && p->next == NULL){
            p->next = new_node;
            new_node->next = NULL;
            listp->len++;
            break;
         } else if (p->data.zID < zid && p->next->data.zID > zid){
            NodeT *temp = p->next;
            p->next = new_node;
            new_node->next = temp;
            listp->len++;
            break;
         } else if (p->data.zID == zid){
            p->data.credits = cr;
            p->data.WAM = wam;
            free(new_node);
            printf("Student record updated.\n");
            return;
         } else{
            p = p->next;
         }
      }
   }
   printf("Student record added.\n");
   return;
}

// Time complexity: O(n)
// Explanation: take linear time since all records need to be checked
void getStatLL(List listp, int *n, float *wam, float *w_wam) {
   float total_wam = 0.0, total_weight_wam = 0.0, total_credits = 0.0;
   NodeT *p = listp->head;

   while (p != NULL){
      total_wam += p->data.WAM;
      total_weight_wam += p->data.WAM * p->data.credits;
      total_credits += p->data.credits;
      p = p->next;
   }
   *n = listp->len;
   *wam = total_wam / listp->len;
   *w_wam = total_weight_wam / total_credits;
   return;
}

// Time complexity: O(n)
// Explanation: take linear time since all records need to be shown
void showLL(List listp) {
   NodeT *p = listp->head;
   while (p != NULL){
      printStudentData(p->data.zID, p->data.credits, p->data.WAM);
      p = p->next;
   }
   return;
}


