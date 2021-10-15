#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int num;

void menu();
void addFunction();
void searchFunction();
void modifyFunction();
void displayFunction();
void deleteFunction();
void reportFunction();


struct date {
	int day;
	int month;
	int year;
};

struct date dates;

struct time {
	int hour;
	int minute;
};

struct time times;

struct user {
	char name[30];
	char IC[20];
	char latestVenue[30];
	char contactNumber[13];
	double temperature;
	char email[40];
	struct time times;
	struct date dates;
	char tarcstud;
};


visitorInformationModule()
{
	menu();
}

void menu()
{
	int choice;

	printf("+---------------------+\n");
	printf("|        Menu         |\n");
	printf("+---------------------+\n");
	printf("|1.Add new record     |\n");
	printf("|2.Search record      |\n");
	printf("|3.Modify record      |\n");
	printf("|4.Display all record |\n");
	printf("|5.Delete record      |\n");
	printf("|6.Report             |\n");
	printf("|7.Exit program       |\n");
	printf("+---------------------+\n\n\n");

	do {
		printf("Select a function : ");
		scanf("%d", &choice);
		rewind(stdin);

		if (choice < 1 || choice > 7)
			printf("The function is not available. Please enter again.\n\n");

		switch (choice)
		{
		case 1:addFunction();
			break;
		case 2:searchFunction();
			break;
		case 3:modifyFunction();
			break;
		case 4:displayFunction();
			break;
		case 5:deleteFunction();
			break;
		case 6:reportFunction();
			break;
		case 7:system("cls");
			printf("Thanks for using ~~");
			break;
		}
	} while (choice < 1 || choice > 7);
}

void addFunction()
{
	FILE* fptr;
	struct user info;
	fptr = fopen("Visitor Information Records.bin", "ab");
	if (fptr == NULL)
	{
		printf("Error!");
		exit(-1);
	}
	int count = 1;
	printf("\n\nEnter name : ");
	scanf("%[^\n]", &info.name);
	rewind(stdin);

	printf("Enter IC number (without '-'): ");
	scanf("%s", &info.IC);
	rewind(stdin);

	printf("Enter the latest venue visited : ");
	scanf("%[^\n]", &info.latestVenue);
	rewind(stdin);

	printf("Enter contact Number (without '-'): ");
	scanf("%s", &info.contactNumber);
	rewind(stdin);

	printf("Enter temperature : ");
	scanf("%lf", &info.temperature);
	rewind(stdin);

	printf("Enter the email : ");
	scanf("%s", &info.email);
	rewind(stdin);

	printf("Enter the time (24 hour system) =>\n");

	do {
		printf("Hours : ");
		scanf("%d", &info.times.hour);
		rewind(stdin);

		if (info.times.hour > 23)
			printf("Invalid ! Please enter again\n");
	} while (info.times.hour > 23);


	do {
		printf("Minutes : ");
		scanf("%d", &info.times.minute);
		rewind(stdin);

		if (info.times.minute > 59)
			printf("Invalid ! Please enter again\n");
	} while (info.times.minute > 59);

	do {
		printf("Enter the date =>\n");
		printf("Enter day : ");
		scanf("%d", &info.dates.day);
		rewind(stdin);
	} while (info.dates.day > 31);

	do {
		printf("Enter month : ");
		scanf("%d", &info.dates.month);
		rewind(stdin);
	} while (info.dates.month > 12);

	do {
		printf("Enter year : ");
		scanf("%d", &info.dates.year);
		rewind(stdin);
	} while (info.dates.year > 2021);

	do {
		printf("Are you TARUC student ?(Y/N)) : ");
		scanf("%c", &info.tarcstud);
		rewind(stdin);

		if (info.tarcstud != 'Y' && info.tarcstud != 'N')
			printf("Error! Please Enter again\n\n");
	} while (info.tarcstud != 'Y' && info.tarcstud != 'N');


	fwrite(&info, sizeof(struct user), 1, fptr);
	fclose(fptr);

	do {
		printf("\n\n1.Display Menu   or   2.Exit program ? : ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:menu();
			break;
		case 2:system("cls");
			printf("Thanks for using ~~");
			break;
		}

	} while (num < 1 || num > 2);
}

void searchFunction()
{
	struct user info;
	FILE* fptr;
	char found[30];
	int num = 1;

	fptr = fopen("Visitor Information Records.bin", "rb");
	if (fptr == NULL)
	{
		printf("Error!");
		exit(-1);
	}

	printf("The name of student : ");
	scanf("%[^\n]", &found);
	rewind(stdin);

	printf("+---+------------------------+------------------+--------------------------------------+---------------+-------------+-----------------------------+------+----------+-------+\n");
	printf("|   |          Name          |     IC number    |         Latest venue visited         | contact number| temperature |            email            | time |   date   | Adult |\n");
	printf("+---+------------------------+------------------+--------------------------------------+---------------+-------------+-----------------------------+------+----------+-------+\n");
	while (fread(&info, sizeof(struct user), 1, fptr) != 0)
	{

		if (strcmp(found, info.name) == 0)
		{
			printf("| %2d|%20s    |%16s  |%30s        | %12s  |    %.1lf     |%30s |%2d:%2d |%2d-%2d-%4d|   %c   |\n", num, info.name, info.IC, info.latestVenue, info.contactNumber, info.temperature, info.email, info.times.hour, info.times.minute, info.dates.day, info.dates.month, info.dates.year, info.tarcstud);
			num++;
		}
	}

	printf("+---+------------------------+------------------+--------------------------------------+---------------+-------------+-----------------------------+------+----------+-------+\n");
	fclose(fptr);

	do {
		printf("\n\n1.Display Menu   or   2.Exit program ? : ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:menu();
			break;
		case 2:system("cls");
			printf("Thanks for using ~~");
			break;
		}

	} while (num < 1 || num > 2);
}

void displayFunction()
{
	struct user info;
	int num = 1;

	FILE* fptr;
	fptr = fopen("Visitor Information Records.bin", "rb");
	if (fptr == NULL)
	{
		printf("Error!");
		exit(-1);
	}
	printf("+---+------------------------+------------------+--------------------------------------+---------------+-------------+---------------------------------+------+----------+--------------+\n");
	printf("|   |          Name          |     IC number    |         Latest venue visited         | contact number| temperature |              email              | time |   date   | TARC student |\n");
	printf("+---+------------------------+------------------+--------------------------------------+---------------+-------------+---------------------------------+------+----------+--------------+\n");


	fread(&info, sizeof(struct user), 1, fptr);

	while (fread(&info, sizeof(struct user), 1, fptr) != 0) {
		printf("| %2d|%20s    |%16s  |%30s        | %12s  |    %.1lf     |%32s |%2d:%2d |%2d-%2d-%4d|      %c       |\n", num, info.name, info.IC, info.latestVenue, info.contactNumber, info.temperature, info.email, info.times.hour, info.times.minute, info.dates.day, info.dates.month, info.dates.year, info.tarcstud);
		num++;
	}

	printf("+---+------------------------+------------------+--------------------------------------+---------------+-------------+---------------------------------+------+----------+--------------+\n");

	fclose(fptr);

	do {
		printf("\n\n1.Display Menu   or   2.Exit program ? : ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:menu();
			break;
		case 2:system("cls");
			printf("Thanks for using ~~");
			break;
		}

	} while (num < 1 || num > 2);
}

void modifyFunction()
{
	struct user info;
	char modiname[30];

	FILE* fptr;
	FILE* fp;

	fptr = fopen("Visitor Information Records.bin", "rb");

	if (fptr == NULL)
	{
		printf("Error!");
		exit(-1);
	}

	fp = fopen("files.bin", "ab");
	if (fp == NULL)
	{
		printf("Error!");
		exit(-1);
	}

	printf("Enter the name you want to modify : ");
	scanf("%[^\n]", &modiname);
	rewind(stdin);

	while (fread(&info, sizeof(struct user), 1, fptr) != 0)
	{
		if (strcmp(modiname, info.name) == 0)
		{
			printf("A record is founded\n\n");
			printf("\n\nEnter new name : ");
			scanf("%[^\n]", &info.name);
			rewind(stdin);

			printf("Enter new IC number : ");
			scanf("%s", &info.IC);
			rewind(stdin);

			printf("Enter the new latest venue visited : ");
			scanf("%[^\n]", &info.latestVenue);
			rewind(stdin);

			printf("Enter new contact Number : ");
			scanf("%s", &info.contactNumber);
			rewind(stdin);

			printf("Enter new temperature : ");
			scanf("%lf", &info.temperature);
			rewind(stdin);

			printf("Enter the new email : ");
			scanf("%s", &info.email);
			rewind(stdin);

			printf("Enter the new time (24 hour system) =>\n");

			do {
				printf("Hours : ");
				scanf("%d", &info.times.hour);
				rewind(stdin);

				if (info.times.hour > 23)
					printf("Invalid ! Please enter again\n");
			} while (info.times.hour > 23);


			do {
				printf("Minutes : ");
				scanf("%d", &info.times.minute);
				rewind(stdin);

				if (info.times.minute > 59)
					printf("Invalid ! Please enter again\n");
			} while (info.times.minute > 59);

			printf("Enter the new date =>\n");
			printf("Enter day : ");
			scanf("%d", &info.dates.day);
			rewind(stdin);
			printf("Enter month : ");
			scanf("%d", &info.dates.month);
			rewind(stdin);
			printf("Enter year : ");
			scanf("%d", &info.dates.year);
			rewind(stdin);

			do {
				printf("Are you TARUC student ?(Y/N)) : ");
				scanf("%c", &info.tarcstud);
				rewind(stdin);

				if (info.tarcstud != 'Y' && info.tarcstud != 'N')
					printf("Error! Please Enter again\n\n");
			} while (info.tarcstud != 'Y' && info.tarcstud != 'N');

			fwrite(&info, sizeof(struct user), 1, fp);
		}

		else
		{
			fwrite(&info, sizeof(struct user), 1, fp);
		}
	}

	fclose(fptr);
	fclose(fp);

	remove("Visitor Information Records.bin");
	rename("files.bin", "Visitor Information Records.bin");

	printf("done\n");

	do {
		printf("\n\n1.Display Menu   or   2.Exit program ? : ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:menu();
			break;
		case 2:system("cls");
			printf("Thanks for using ~~");
			break;
		}

	} while (num < 1 || num > 2);
}

void deleteFunction()
{
	struct user info;
	char delname[30];
	int found = 0;

	FILE* fptr;
	FILE* fp;

	fptr = fopen("Visitor Information Records.bin", "rb");

	if (fptr == NULL)
	{
		printf("Error!");
		exit(-1);
	}

	fp = fopen("files.bin", "ab");
	if (fp == NULL)
	{
		printf("Error!");
		exit(-1);
	}

	printf("Enter the name you want to delete : ");
	scanf("%s", &delname);
	rewind(stdin);

	while (fread(&info, sizeof(struct user), 1, fptr) != 0)
	{
		if (strcmp(delname, info.name) == 0)
		{
			printf("A record is founded\n\n");
		}

		else
		{
			fwrite(&info, sizeof(struct user), 1, fp);
		}
	}

	fclose(fptr);
	fclose(fp);

	remove("Visitor Information Records.bin");
	rename("files.bin", "Visitor Information Records.bin");

	printf("done\n");

	do {
		printf("\n\n1.Display Menu   or   2.Exit program ? : ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:menu();
			break;
		case 2:system("cls");
			printf("Thanks for using ~~");
			break;
		}

	} while (num < 1 || num > 2);
}


void reportFunction()
{
	struct user info;
	FILE* fptr;
	fptr = fopen("Visitor Information Records.bin", "rb");

	while (fread(&info, sizeof(struct user), 1, fptr) != 0) {

		if (info.temperature > 37.3) {
			printf("Dangerous place : ");
			printf("%s\n\n", info.latestVenue);

			printf("+--------------------+\n");
			printf("|  User Information  |\n");
			printf("+--------------------+-----------------------------+\n");
			printf("|        Name        |      %20s   |\n", info.name);
			printf("+--------------------+-----------------------------+\n");
			printf("|         IC         |       %16s      |\n", info.IC);
			printf("+--------------------+-----------------------------+\n");
			printf("|   Contact Number   |         %12s        |\n", info.contactNumber);
			printf("+--------------------+-----------------------------+\n");
			printf("|        Email       |%28s |\n", info.email);
			printf("+--------------------+-----------------------------+\n");
			printf("| TARC Student (Y/N) |               %c             |\n", info.tarcstud);
			printf("+--------------------+-----------------------------+\n\n\n");
		}
	}

	do {
		printf("\n\n1.Display Menu   or   2.Exit program ? : ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:menu();
			break;
		case 2:system("cls");
			printf("Thanks for using ~~");
			break;
		}

	} while (num < 1 || num > 2);
}