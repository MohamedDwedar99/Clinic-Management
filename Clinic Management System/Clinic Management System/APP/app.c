#include <stdio.h>
#include "app.h"
#include "../service/std.h"
#include "../Modes/Admin/admin.h"
#include "../Modes/User/user.h"

void start_app(void)
{
	printf("Welcome to IMT Clinic \n");
	printf("----------------------------------\n\n");
	u8 x;
	while(1)
	{
		do
		{
			printf("For  	Admin 	Press: 1\n");
			printf("For 	User   	Press: 2\n");
			printf("To	Exit   	Press: 3\n\n");
			printf("----------------------------------\n");
			printf("Your	Choice		:  ");
			scanf("%hhd",&x);
			printf("----------------------------------\n\n");
			if (x !=1 && x !=2 && x != 3)
			{
				printf("Not Valid Choice \n\n");
			}
		}while(x !=1 && x !=2 && x != 3);
		switch (x)
		{
			case 1:	admin();	break;
			case 2:	user(); 		break;
		}
		if (x == 3)
		{
			printf("Good Luck\n");
			break;
		}
	}
}