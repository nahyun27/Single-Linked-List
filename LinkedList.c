#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
  int data;
  struct NODE *next;
}Node;

typedef struct LINKEDLIST{
  Node *head, *tail;
  int length;
}LinkedList;

LinkedList *linkedList;

void intialized(){
  linkedList = (LinkedList *)malloc(sizeof(LinkedList));
  linkedList->head = NULL;
  linkedList->tail = NULL;
  linkedList->length = 0;
}

void addNode(int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if(linkedList->head == NULL && linkedList->tail == NULL){
    linkedList->head = newNode;
    linkedList->tail = newNode;
  }
  else {
    linkedList->tail->next = newNode;
    linkedList->tail = newNode;
  }

  ++linkedList->length;
}

void addNodeFirst(int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if(linkedList->head == NULL && linkedList->tail == NULL){
    linkedList->head = newNode;
    linkedList->tail = newNode;
  }
  else {
    Node *copyHead = linkedList->head;
    linkedList->head = newNode;
    linkedList->head->next = copyHead;
  }
  ++linkedList->length;
}

void showAllNodes(){
  Node *copyHead = linkedList->head;

  while(copyHead != NULL){
    printf("%d\n", copyHead->data);
    copyHead = copyHead->next;
  }
}

void deleteNode(int key){

  if(linkedList->length == 0) return;
  else if(linkedList->length == 1){
    free(linkedList->head);
    linkedList->head = NULL;
    linkedList->tail = NULL;
  }
  else if(linkedList->length >= 2){
    Node *copyHead = linkedList->head->next, *prevNode = linkedList->head;
    int now = 0;

    if(prevNode->data == key){
      linkedList->head = prevNode->next;
      free(prevNode);
      return;
    }else{
      while(copyHead != NULL){
        if(copyHead->data == key){
          break;
        }
        else {
          ++now;
          copyHead = copyHead->next;
          prevNode = prevNode->next;
        }
      }
    }

    if(copyHead == NULL){
      printf("찾는 key값이 리스트 안에 존재하지 않습니다");
    }
    else {
      if(now == linkedList->length - 1){ //마지막 노드 삭제
        prevNode->next = NULL;
        linkedList->tail = prevNode;
        free(copyHead);
      }
      else { //중간 노드 삭제
        prevNode->next = copyHead->next;
        free(copyHead);
      }
    }

  }
  else {
    printf("연결리스트의 구조가 이상합니다.");
  }
  
}

int main(void){
  intialized();

  int i;
  for(i=0;i<100;++i){
    addNode(i);
  }

  addNodeFirst(-1);
  deleteNode(-1);
  deleteNode(99);
  deleteNode(50);
  showAllNodes();
}
