/* Copyright By Min Byoung Chan. All Rights Reserved*/
/* implementaion Data Structure (Double Linked List)*/
/**/


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* prev;
	struct node* next;
}Node;


Node* head=NULL;
Node* tail=NULL;
Node* Cur=NULL;

void insert(int input){
	if(head==NULL){
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = input;
		temp->next = NULL;
		temp->prev = NULL;
		
		head = temp;
		tail =temp;		
	}
	else{
		
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = input;
		temp->next = NULL;
		temp->prev = NULL;
		
		 
		tail->next = temp;
		temp->prev = tail;		
		tail =temp;	

	
	}
}
void insertMiddle(int input,int loc){
	Node* temp =(Node*)malloc(sizeof(Node));
	temp->data = input;
	temp->next = NULL;
	temp->prev = NULL;
	
	Cur =head;
	while(Cur->next!=NULL){
		if(Cur->data ==loc){
			Cur->next->prev = temp;
			temp->next = Cur->next;
			Cur->next = temp;
			temp->prev = Cur;
			break;
		}
		Cur = Cur->next;
	}
	if(tail->data == loc){
		insert(input);
		
	}
	
}
void count(){
	int count=0;
	Cur=head;
	while(Cur->next!=NULL){
		count++;
		Cur = Cur->next;
	}
	count++;
	printf("����� ������ %3d",count);
}


int search(int input){
	Cur= head;
	while(Cur->next!=NULL){
		if(Cur->data == input){
			printf("ã���� �ϴ� �� %2d�� ã�ҽ��ϴ�.",Cur->data);
			return 0;
		}
		Cur = Cur->next;
	}
	if(tail->data ==input){
			printf("ã���� �ϴ� �� %2d�� ã�ҽ��ϴ�.",tail->data);
	
	}
	else{
		puts("�츮�� ã���� �ϴ� ���� ���׿�.");
	}
	
}
void deleteAll(){
	Cur = head;
	while(Cur->next!=NULL){
		head = Cur->next;
		free(Cur);
		Cur = Cur->next;
	}
	free;
	
}
void print(){
	Cur = head;
	while(Cur->next!=NULL){
		printf("%2d",Cur->data);
		Cur = Cur->next;
		
	}
printf("%2d",Cur->data);
	puts("");
}
int main(){
	
	/*below test code*/
	insert(3);

	insert(5);
	insert(9);
	print();

puts("======================================================");
deleteAll();
print();
	
	
	free(head);
	free(tail);
	free(Cur);


}
