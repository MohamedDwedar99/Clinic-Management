#ifndef 	ADMIN_H
#define	ADMIN_H

u8 admin(void);
u8 ask_pass(void);
u8 add_record(void);
u8 edit_record(void);
u8 reserve_slot(void);
u8 cancel_reserve(void);
typedef struct node
{
	u8 name[15];
	u8 age;
	u8 gender[10];
	u32 id;
	struct node * next;
}node;

typedef struct reserve
{
	u8 time[20];
	u32 id;
}reserve;

enum pass
{
	PASS_OK,
	PASS_FAIL
};
enum admin
{
	ADMIN_EXIT
};

enum add
{
	ADD_OK,
	ADD_FAIL
};
enum edit
{
	EDIT_OK,
	EDIT_FAIL
};

enum Reserve
{
	RESERVE_OK,
	RESERVE_FAIL
};
enum Cancel
{
	CANCEL_OK,
	CANCEL_FAIL
};
enum RECORD
{
	NEW_REC,
	EDIT_REC,
	RESERVE,
	CANCEL,
	EXIT
};

#endif