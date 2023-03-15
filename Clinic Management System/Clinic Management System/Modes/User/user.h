#ifndef 	USER_H
#define	USER_H

void user(void);
u8 view_record(void);
u8 view_reservation(void);

enum Record1
{
	RECORD_FOUND,
	RECORD_NOT_FOUND
};
enum Reserve1
{
	RESERVE_FOUND,
	RESERVE_NOT_FOUND
};
#endif