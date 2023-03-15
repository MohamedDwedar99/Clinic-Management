#include <stdio.h>
#include "../../service/std.h"
#include "../Admin/admin.h"
#include "user.h"

node  extern * head;
reserve extern Time[5];

void user(void)
{
	printf("Welcome To User Mode\n");
	printf("----------------------------------\n\n");
	u8 x =0;
	while (x != 2)
	{
		printf("To view patient record: 1\n");
		printf("To View today's reservations: 2\n");
		printf("To Exit press: 3\n\n");
		printf("your choice : ");
		scanf("%hhd",&x);
		x -=1;
		printf("\n");
		switch (x)
		{
			case 0 : view_record(); break;
			case 1 : view_reservation(); break;
		}
	}
}
u8 view_record(void)
{
	u32 x;
	printf("ID: ");
	scanf("%d",&x);
	node * temp = head;
	while (temp != NULL)
	{
		if (temp->id == x)
		{
			printf("Name: %s\n",temp->name);
			printf("Gender: %s\n",temp->gender);
			printf("Age: %d\n\n",temp->age);
			return RECORD_FOUND;
		}
		temp = temp->next;
	}
	printf("\nID is not registried\n\n");
	return RECORD_NOT_FOUND;
}

u8 view_reservation(void)
{
	printf("Reservations\n----------------------\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s : ",Time[i].time);
		if (Time[i].id == 0)
		{
			printf("Empty\n");
		}
		else
		{
			printf("%d\n",Time[i].id);
		}
	}
	printf("\n");
}