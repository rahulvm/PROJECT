/*******************************************************************************
* @file   : pgm1_linkedlist.c
* @Author : Rahul V M (rahul.vm@vvdntech.in)
* @brief  : Write a program to implement Student database program using
*            Single linked list. The database should be permanent
*            (i.e. use file to save).
*            Database should have members like roll_no, age, sex, name, address
*            There should be options to add, delete, modify, search, sort,
*            print reverse the linked list.
* @Copyright: (c) 2017 , VVDN Technologies Pvt. Ltd.
*             Permission is hereby granted to everyone in VVDN Technologies
*             to use the Software without restriction, including without
*             limitation the rights to use, copy, modify, merge, publish,
*             distribute, distribute with modifications.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

/*Node Structre Definition*/
typedef struct node {
	char name[60];
	int	rollno;
	int age;
	char gender[7];
	char address[200];
	struct node *next;
}node_t;

/*****************************************************************************
 *@function : print_list()
 *@input    : Head Pointer
 *@return   : No return
 *@brief    : The function prints the entire data from head pointer to last.
*****************************************************************************/
void print_list(node_t *current)
{
	if (current == NULL ) {
		printf("empty list\n");
	}
	while (current != NULL) {
		printf("Name:%s",current->name);
		printf("Rollno:%d\n",current->rollno);
		printf("Age:%d\n",current->age);
		printf("Gender:%s\n",current->gender);
		printf("Address:%s\n",current->address);
		current = current->next;
	}
}

/****************************************************************************
 *@function : traverse()
 *@input    : Head Pointer
 *@return   : Integer value
 *@brief    : The function returns the number of nodes.
****************************************************************************/
int traverse(node_t *head)
{
	int i = 0;

	while (head->next != NULL) {
		i++;
		head = head->next;
	}
	return i;
}

/****************************************************************************
 *@function : createnode()
 *@input    : void
 *@return   : new node address
 *@brief    : The function creates new nodes with user inputs,return address
 *            if the user input is validated, else return zero.
****************************************************************************/
node_t *createnode()
{
	node_t *new_node;
	new_node = (node_t *)malloc(sizeof(node_t));
	printf("\nEnter the name:");
	getchar();
	fgets(new_node->name,60,stdin);
	printf("\nEnter the roll number:");
	if (!(scanf("%d",&(new_node->rollno)))) {
		return FAILURE;
	}
	printf("\nEnter the age:");
	if (!(scanf("%d",&(new_node->age)))) {
		return FAILURE;
	}
	printf("\nEnter gender M for male & F for female:");
	scanf("%s",(new_node->gender));
	printf("\nEnter the address:");
	getchar();
	fgets(new_node->address,200,stdin);
	new_node->next = NULL;
	return new_node;
}

/****************************************************************************
 *@function : push_end()
 *@input    : Head Pointer
 *@return   : SUCCESS/FAILURE
 *@brief    : The function adds the new created node to the end of head.
*****************************************************************************/
int push_end(node_t *head)
{
	node_t *current = head;
	if (current == NULL) {
		printf("Invalid data input\n");
		return FAILURE;
	}
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = createnode();
	return SUCCESS;
}

/****************************************************************************
 *@function : push_begin
 *@input    : Head Pointer Address
 *@return   : SUCCESS/FAILURE
 *@brief    : The function adds the new node to the begin of head.
****************************************************************************/
int push_begin(node_t **head)
{
	node_t *new_node;

	new_node = createnode();
	if (new_node == 0) {
		printf("Invalid data input\n");
		return FAILURE;
	}
	if (*head == NULL) {
		(*head) = new_node;
	} else {
		new_node->next = *head;
		(*head) = new_node;
	}
	return SUCCESS;
}

/****************************************************************************
 *@function : Search()
 *@input    : Head Pointer
 *@return   : No return
 *@brief    : The function prints the data if match obtained with database
 *            else print not found.Input data is read within the function.
****************************************************************************/
void Search(node_t *head)
{
    node_t *new;
    int count = 0;
    char data[50];

	new = head;
    printf("enter name to search\n");
	getchar();
    fgets(data,20,stdin);
	while (new != NULL) {
		if (!(strcmp(data,new->name))) {
            printf("%s is found at entry %d\n",data,count+1);
			printf("Name:%s\n",new->name);
			printf("Roll no:%d\n",new->rollno);
			printf("Age:%d\n",new->age);
			printf("Gender:%s\n",new->gender);
			printf("Address:%s\n",new->address);
			return;
		}
		new = new->next;
		count++;
	}
	if (new == NULL) {
		printf ("\n%s not found in list\n",data);
	}
}

/*****************************************************************************
 *@function : delete()
 *@input    : Head Pointer
 *@return   : SUCCESS/FAILURE
 *@brief    : The function reads the name of student to be deleted, it scans
 *            in the database, if found delete and return success, else
 *            return failure.
*****************************************************************************/
int delete(node_t **head)
{
    char data[50];
    node_t *current, *prev;

	current = *head;
    getchar();
    printf("enter name to delete entry\n");
    fgets(data,50,stdin);
    while (current != NULL) {
        if (!(strcmp(data,current->name))) {
            if (current == *head) {
                *head = current->next;
                free(current);
                return SUCCESS;
            } else {
				prev->next = current->next;
				free(current);
				return SUCCESS;
            }
			printf("Deleted\n");
        } else {
			prev = current;
			current = current->next;
        }
    }
    printf("Data not found\n");
    return FAILURE;
}

/*****************************************************************************
 *@function : Modify
 *@input    : Head Pointer
 *@return   : SUCCESS/FAILURE
 *@brief    : The function reads the student name to edit the database,
 *            if found reads the new data and will update on position.
*****************************************************************************/
int Modify(node_t *head)
{
    node_t *new;
    int count = 0;
    char data[50];

    new = head;
    printf("enter name to search\n");
	getchar();
    fgets(data,50,stdin);
	while (new != NULL) {
		if (!(strcmp(data,new->name))) {
            printf("Enter the new details of %s to modify\n",data);
			printf("\nEnter the name:");
			fgets(new->name,60,stdin);
			printf("\nEnter the roll number:");
			scanf("%d",&(new->rollno));
			printf("\nEnter the age:");
			scanf("%d",&(new->age));
			printf("\nEnter gender M for male & F for female:");
			scanf("%s",(new->gender));
			printf("\nEnter the address:");
			getchar();
			fgets(new->address,200,stdin);
            return SUCCESS;
		}
		new = new->next;
		count++;
	}
	if (new == NULL) {
		printf ("\n%s not found in list\n",data);
	}
	return FAILURE;
}

/***************************************************************************
 *@function : swap_strings
 *@input 1  : String 1 pointer
 *@input 2  : String 2 pointer
 *@return   : SUCCESS
 *@brief    : The function swap the datas in String pointers.
***************************************************************************/
int swap_strings(char *Str1, char *Str2)
{
    char test[100];

	strcpy(test,Str1);
	strcpy(Str1,Str2);
	strcpy(Str2,test);
    return SUCCESS;
}

/**************************************************************************
 *@function : swap()
 *@input 2  : Pointer to node 1
 *@input 2  : Pointer to node 2
 *@return   : SUCCESS
 *@brief    : The function swaps the contents of entered nodes.
**************************************************************************/
int swap(node_t *a, node_t *b) {
	int temp;

	temp = a->rollno;
    a->rollno = b->rollno;
    b->rollno = temp;

    temp   = a->age;
    a->age = b->age;
    b->age = temp;

    swap_strings(a->name, b->name);
    swap_strings(a->address, b->address);
    swap_strings(a->gender, b->gender);
    return SUCCESS;
}

/**************************************************************************
 *@function : bubbleSort()
 *@input    : Head Pointer Address
 *@return   : No return
 *@brief    : The function sorts the linked list
 *            in ascending order based on rollno value.
**************************************************************************/
void bubbleSort(struct node **start)
{
	struct node *ptr1 = *start;
	int loop = 0, loop1 = 0,loop2 = 0;

	loop = traverse(*start);
	/* Checking for empty list */
	if (ptr1 == NULL) {
		return;
	}
	for(loop1 = 0; loop1<loop; loop1++) {
		ptr1 = *start;
		for (loop2 = 0;loop2<loop;loop2++) {
			if ((ptr1->rollno) > (ptr1->next->rollno)) {
				swap(ptr1,(ptr1->next));
			}
			ptr1 = (ptr1->next);
		}
	}

}

/**************************************************************************
 *@function : reverse()
 *@input    : Head Pointer Address
 *@return   : No return
 *@brief    : The function revereses the entire linked list.
**************************************************************************/
void reverse(node_t **head)
{
	node_t *next = NULL,*prev = NULL,*current;

	current = *head;
	while (current != NULL) {
		next  = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*head) = prev;
}

/**************************************************************************
 *@function : filebinwrite()
 *@input    : Head Pointer
 *@return   : SUCCESS/FAILURE
 *@brief    : The function writes the database of linked list into a file
 *            named databse.bin stored as binary.
**************************************************************************/
int filebinwrite(node_t *current)
{
	FILE *fptr1 = NULL;

	if (current == NULL) {
		printf("No data exist\n");
		return FAILURE;
	}
	fptr1 = fopen("database.bin","wb");
	while (current != NULL) {
		fwrite(current,sizeof(node_t)-sizeof(node_t *),1,fptr1);
		current = current->next;
	}
	fclose(fptr1);
	return SUCCESS;
}

/*@function : filebinread()
 *@input    : Head Pointer Address
 *@return   : SUCCESS/FAILURE
 *@brief    : The function loads the bin file database into a linked list.
*/
int filebinread(node_t **head)
{
	FILE *fptr2 = NULL;
	node_t *temp;
	char flag = 1;

	fptr2 = fopen("database.bin","rb");
	if (fptr2 == NULL) {
		printf("No database found\n");
		return FAILURE;
	}
	while (flag) {
		temp = (node_t *)malloc(sizeof(node_t));
		flag =	fread(temp,sizeof(node_t)-sizeof(node_t *),1,fptr2);
		if(flag == 0) {
			fclose(fptr2);
			return SUCCESS;
		}
		if (*head == NULL) {
			*head = temp;
		} else {
			temp->next = *head;
			*head = temp;
		}
	}
	fclose(fptr2);
	return SUCCESS;
}


/**************************************************************************
 *@function : main()
 *@input    : no input
 *@return   : SUCCESS/FAILURE
 *@brief    : The function performs all task required as per task.
 *            It calls the functions upon requirements.
***************************************************************************/
int main()
{
	int option = 0;
	node_t *head = NULL;

	/*Loading of database ; if exist it will load,else displays not found*/
	filebinread(&head);
	/*Sorting the data on read for user easiness in reading*/
	bubbleSort(&head);

	/*Menu For Options*/
LOOP:do {
		printf(">>>>>>>>>>>>>MENU>>>>>>>>>>>>>>\n");
		printf("\tEnter 1 : Display\n\tEnter 2 : Enroll\n\t"
			"Enter 3 : Search\n\tEnter 4 : Delete\n"
			"\tEnter 5 : Reverse\n\tEnter 6 : Sort\n\tEnter 7 : Save"
			"\n\tEnter 8 : Modify\n\tEnter 0 : Save & Exit\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		getchar();
		printf("Your choice is:");
		if (scanf("%d",&option)) {
			switch (option) {
				case 1:
					printf("\nThe Data Base is\n");
					print_list(head);
					break;
				case 2:
					push_begin(&head);
					getchar();
					break;
				case 3:
					Search(head);
					break;
				case 4:
					delete(&head);
					break;
				case 5:
					printf("\nReversed list is\n");
					reverse(&head);
					print_list(head);
					break;
				case 6:
					printf("\nSorted list is \n");
					bubbleSort(&head);
					print_list(head);
					break;
				case 7:
					filebinwrite(head);
					printf("\nData Written successfully\n");
					break;
				case 8:
					Modify(head);
					break;
				case 0:
					filebinwrite(head);
					printf("\n:) Thank You :)\n");
					return SUCCESS;
					break;
				default:
					printf("\nInvalid case\n\nEnter 0 to exit\n");
					break;
			}
		} else {
			goto LOOP;
		}
	} while (option != 0);
	return FAILURE;
}
