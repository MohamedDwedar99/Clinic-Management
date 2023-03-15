#include <stdio.h>
#include <stdlib.h>
#include "../../service/std.h"
#include "admin.h"

node * head = NULL;
reserve Time[5] ={{"2pm to 2:30pm",0},{"2:30pm to 3pm",0},{"3pm to 3:30pm",0},{"4pm to 4:30pm",0},{"4:30pm to 5pm",0}};
u8 admin(void)
{
	printf("Welcome To Admin Mode\n");
	printf("----------------------------------\n\n");
	u8 p;
	p = ask_pass();
	if (p == PASS_OK)
	{
		printf("Password Is Correct\n\n");
	}
	else
	{
		printf("Password Wrong 3 Times\n\n");
		return ADMIN_EXIT;
	}
	u8 x =0;
	while (x != EXIT)
	{
		printf("To Add new patient record press: 1\n");
		printf("To Edit patient record press: 2\n");
		printf("To Reserve a slot with doctor press: 3\n");
		printf("To Cancel reservation press : 4\n");
		printf("To Exit press: 5\n\n");
		printf("your choice : ");
		scanf("%hhd",&x);
		x -=1;
		printf("\n");
		switch (x)
		{
			case 0 : add_record(); break;
			case 1 : edit_record(); break;
			case 2 : reserve_slot(); break;
			case 3 : cancel_reserve(); break;
		}
		
	}
}
u8 ask_pass(void)
{
	u32 x = 0;
	u8 count = 0;
	do
	{
		printf("Password : ");
		scanf("%d",&x);
		if (x == 1234)
		{
			return PASS_OK;
		}

		else if (count < 2)
		{
			printf("Try again\n");
		}
		count++;
	}while(count < 3);
	return PASS_FAIL;
}
u8 add_record(void)
{
	node * new = (node*)malloc(sizeof(node));
	printf("name: ");
	scanf("%s",new->name);
	printf("age: ");
	scanf("%hhd",&new->age);
	printf("gender: ");
	scanf("%s",new->gender);
	printf("ID: ");
	scanf("%d",&new->id);
	new->next = NULL;
	
	if (head == NULL)
	{
		head = new;
		new = NULL;
		free(new);
		printf("\npatient added sucessfully\n\n");
		return ADD_OK;
	}
	else
	{
		node * temp = head;
		while(temp != NULL)
		{
			if (temp->id == new->id)
			{
				printf("\nID exist\nfail to add new patient\n\n");
				free(new);
				return ADD_FAIL;
			}
			temp = temp->next;
		}
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new = NULL;
		free(new);
		printf("\npatient added sucessfully\n\n");
		return ADD_OK;
	}
}
u8 edit_record(void)
{
	node * temp = head;
	if (temp == NULL)
	{
		printf("\nNo data to edit\n\n");
		return EDIT_FAIL;
	}
	u32 x;
	printf("Patient ID: ");
	scanf("%d",&x);
	while(temp != NULL)
	{
		if (temp->id == x)
		{
			printf("name: ");
			scanf("%s",temp->name);
			printf("age: ");
			scanf("%hhd",&temp->age);
			printf("gender: ");
			scanf("%s",temp->gender);
			printf("\nEdit Sucess\n\n");
			return EDIT_OK;
		}
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("\nID NOT FOUNT\n\n");
		return EDIT_FAIL;
	}
}
u8 reserve_slot(void)
{
	node * temp = head;
	if (temp == NULL)
	{
		printf("\nNo data to be reserved\n\n");
		return RESERVE_FAIL;
	}
	u8 f = 0;
	for (int i = 0; i < 5; i++)
	{
		if (Time[i].id != 0)
		{
			continue;
		}
		else 
		{
			f = 1;
		}
		printf("To select %s press %d\n",Time[i].time,i);
	}
	if (f = 0)
	{
		printf("No Time Availabel\n\n");
		return RESERVE_FAIL;
	}
	printf("Your select: ");
	scanf("%hhd",&f);
	if (Time[f].id != 0 || f > 4 || f < 0)
	{
		printf("\nWrong Choice\n\n");
		return RESERVE_FAIL;
	}
	u32 x;
	printf("Pateint ID: ");
	scanf("%d",&x);
	while(temp != NULL)
	{
		if (temp->id == x)
		{
			break;
		}
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("\nID NOT EXIST\n\n");
		return RESERVE_FAIL;
	}
	Time[f].id = x;
	printf("\nReserve Sucess\n\n");
	return RESERVE_OK;
}
u8 cancel_reserve(void)
{
	u32 x;
	printf("ID: ");
	scanf("%d",&x);
	for (u32 i = 0; i < 5;i++)
	{
		if (x == Time[i].id)
		{
			Time[i].id = 0;
			return CANCEL_OK;
		}
	}
	return CANCEL_FAIL;
}
