#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#pragma warning (disable : 4996)

void add();
void search();
void mod();
void display();
void del();
void report();
void exits();


struct Locate {
	char vName[50];
	char vID[50];
	int maxV;
	int day;
	int month;
	int year;

};

struct Name {

	struct Locate L;
	char viN[50];
	char viIC[50];
	int mEn;
	int hEn;
	int mEx;
	int hEx;
	char tel[20];
	double tempe;

};
struct Name N;

FILE* rec;

void visitAndExitModule()
{
	char more;
	int choice;

	do {

		do {

			printf("\n\t\t\tWelcome to use TarucSejahtera contact-tracing system\n\n");
			printf("\n\t\t\t\t\tStay home, stay safe\n\n");

			printf("\tPlease select: \n");
			printf("\t 1. Add new record\n");
			printf("\t  2. Search records\n");
			printf("\t   3. Modify data\n");
			printf("\t    4. Display all records\n");
			printf("\t     5. Delete record\n");
			printf("\t      6. Report\n");
			printf("\t       7. Exit\n\n");
			rewind(stdin);
			printf("Enter an integer (1-7) : ");
			scanf("%d", &choice);

			switch (choice)

			{

			case 1: add();
				break;

			case 2: search();
				break;

			case 3: mod();
				break;

			case 4: display();
				break;

			case 5: del();
				break;

			case 6: report();
				break;

			case 7: exits();
				break;
			}

		} while (choice < 1 || choice > 7);

		rewind(stdin);
		printf("\n\nDo you want to return menu? (Y/y to return): ");
		scanf("%c", &more);
		system("cls");


	} while (more == 'Y' || more == 'y');

}



void add()
{
	char adds;
	do {


		rec = fopen("Visit And Exit Records.txt", "a");

		if (rec == NULL)
		{
			printf("File cannot be open\n");
			exit(-1);
		}

		printf("\n\nPLEASE ENTER NEW RECORD \n");

		printf("\nVenue name: ");
		rewind(stdin);
		scanf("%[^\n]", &N.L.vName);

		printf("\nVenue ID: ");
		rewind(stdin);
		scanf("%[^\n]", &N.L.vID);

		printf("\nMaximum visitor: ");
		rewind(stdin);
		scanf("%d", &N.L.maxV);


		printf("\nYears: ");
		rewind(stdin);
		scanf("%d", &N.L.year);

		printf("\nMonth (1 ~ 12 = January ~ December): ");
		scanf("%d", &N.L.month);

		while (N.L.month < 1 || N.L.month > 12) {

			printf("Invalid input\n");
			printf("please check again (1 ~ 12 = January ~ December): ");
			rewind(stdin);
			scanf("%d", &N.L.month);
		}


		switch (N.L.month)
		{

		case 1: rewind(stdin);
			printf("\nPlease enter day (1 ~ 31): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 31)
			{
				printf("\nInvalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's January): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 2:
			if (N.L.year % 4 == 0)
			{
				rewind(stdin);
				printf("\nPlease enter day (1 ~ 29): ");
				scanf("%d", &N.L.day);


				while (N.L.day < 1 || N.L.day > 29)
				{

					printf("\nInvalid input\n");
					rewind(stdin);
					printf("\nPlease enter day again (In a leap year, February has 29 days): ");
					scanf("%d", &N.L.day);
				}

			}

			else if (N.L.year % 4 != 0)
			{
				rewind(stdin);
				printf("\nPlease enter day (1 ~ 28): ");
				scanf("%d", &N.L.day);

				while (N.L.day < 1 || N.L.day > 28)
				{
					printf("Invalid input\n");
					rewind(stdin);
					printf("\nPlease enter day again (February has 28 days): ");
					scanf("%d", &N.L.day);
				}
			}
			break;

		case 3: rewind(stdin);
			printf("\nPlease enter day (1 ~ 31): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 31)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's March): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 4: rewind(stdin);
			printf("\nPlease enter day (1 ~ 30): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 30)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's April): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 5: rewind(stdin);
			printf("\nPlease enter day (1 ~ 31): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 31)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's May): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 6: rewind(stdin);
			printf("\nPlease enter day (1 ~ 30): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 30)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's June): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 7: rewind(stdin);
			printf("\nPlease enter day (1 ~ 31): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 31)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's July): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 8: rewind(stdin);
			printf("\nPlease enter day (1 ~ 31): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 31)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's August): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 9: rewind(stdin);
			printf("\nPlease enter day (1 ~ 30): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 30)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's September): ");
				scanf("%d", &N.L.day);
			}
			break;


		case 10: rewind(stdin);
			printf("\nPlease enter day (1 ~ 31): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 31)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's October): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 11: rewind(stdin);
			printf("\nPlease enter day (1 ~ 30): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 30)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\n\nPlease enter day again (It's November): ");
				scanf("%d", &N.L.day);
			}
			break;

		case 12: rewind(stdin);
			printf("\nPlease enter day (1 ~ 31): ");
			scanf("%d", &N.L.day);
			while (N.L.day < 1 || N.L.day > 31)
			{
				printf("Invalid input\n");
				rewind(stdin);
				printf("\nPlease enter day again (It's December): ");
				scanf("%d", &N.L.day);
			}
			break;
		}

		rewind(stdin);
		printf("\nVisitor name: ");
		scanf("%[^\n]", &N.viN);

		rewind(stdin);
		printf("\nVisitor IC (Please enter by this concept = xxxxxx-xx-xxxx): ");
		scanf("%[^\n]", &N.viIC);


		rewind(stdin);
		printf("\nTime Entered (Minutes, please enter 0 ~ 59): ");
		scanf("%d", &N.mEn);

		while (N.mEn < 0 || N.mEn > 59) {
			printf("\nError integer Input! (Enter 0 ~ 59 (minutes)): ");
			scanf("%d", &N.mEn);
			rewind(stdin);
		}

		printf("\nTime Entered (Hours, please enter in 24-hour concept 1 ~ 24 ): ");
		scanf("%d", &N.hEn);
		rewind(stdin);

		while (N.hEn < 1 || N.hEn > 24) {
			printf("\nError integer Input! (Enter 1 ~ 24 (hours)): ");
			scanf("%d", &N.hEn);
			rewind(stdin);
		}


		printf("\nTime Exited (Minutes, please enter 0 ~ 59): ");
		scanf("%d", &N.mEx);
		rewind(stdin);

		while (N.mEx < 0 || N.mEx > 59) {
			printf("\nError integer Input! (Enter 0 ~ 59 (minutes)): ");
			scanf("%d", &N.mEx);
			rewind(stdin);
		}

		printf("\nTime Exited (Hours, please enter in 24-hour concept 1 ~ 24 ): ");
		scanf("%d", &N.hEx);
		rewind(stdin);

		while (N.hEx < 1 || N.hEx > 24) {
			printf("\nError integer Input! (Enter 1 ~ 24 (hours)): ");
			scanf("%d", &N.hEx);
			rewind(stdin);
		}


		printf("\nTelephone numbers (Please enter by following concept: E.x. 012-3456789): ");
		scanf("%[^\n]", &N.tel);
		rewind(stdin);

		printf("\nTemperature (Please enter in Celsius E.x 36.1): ");
		scanf("%lf", &N.tempe);

		if (N.tempe > 38)
			printf("You are getting a fever!");


		else if (N.tempe < 35)
			printf("unusual temperature");

		fprintf(rec, "%s|%s|%d|%d/%d/%d|%s|%s|%d:%d|%d:%d|%s|%2.1lf\n", N.L.vName, N.L.vID, N.L.maxV, N.L.day, N.L.month, N.L.year, N.viN, N.viIC, N.hEn, N.mEn, N.hEx, N.mEx, N.tel, N.tempe);
		fclose(rec);

		rewind(stdin);
		printf("\n\nDo you want to continue to add more record? (enter Y/y to add more): ");
		scanf("%c", &adds);



	} while (adds == 'Y' || adds == 'y');

}


void search() {

	char s, n[50];

	do {

		rec = fopen("Visit And Exit Records.txt", "r");
		if (rec == NULL)
		{
			printf("File cannot be open\n");
			exit(-1);
		}


		rewind(stdin);
		printf("\nPlease enter the correct name to search the specific data: ");
		scanf("%[^\n]", &n);



		while (fscanf(rec, "%[^|]|%[^|]|%d|%d/%d/%d|%[^|]|%[^|]|%2d:%2d|%2d:%2d|%[^|]|%lf\n", &N.L.vName, &N.L.vID, &N.L.maxV, &N.L.day, &N.L.month, &N.L.year, &N.viN, &N.viIC, &N.hEn, &N.mEn, &N.hEx, &N.mEx, &N.tel, &N.tempe) != EOF) {


			if (strcmp(n, N.viN) == 0) {

				printf("\n\n| \t Venue name: %s\n| \t  Venue ID: %s\n| \t   Maximum visitor: %d\n| \t    Date: %d/%d/%d\n| \t     Visitor name: %s\n| \t     Visitor IC: %s\n| \t    Time entered: %2d:%2d\n| \t   Time exited: %2d:%2d\n| \t  Contact number: %s\n| \t Temperature: %2.1lf \n", N.L.vName, N.L.vID, N.L.maxV, N.L.day, N.L.month, N.L.year, N.viN, N.viIC, N.mEn, N.hEn, N.mEx, N.hEx, N.tel, N.tempe);
			}


		}

		rewind(stdin);
		printf("\nDo you want to search more? (enter Y/y to continue):");
		scanf("%c", &s);

	} while (s == 'Y' || s == 'y');

	fclose(rec);

}




void mod() {



	char n, lol;

	struct Name M[100];
	struct Name m[100];

	int count = 0, x, c = 0;

	char o[50];

	rec = fopen("Visit And Exit Records.txt", "r");
	if (rec == NULL)
	{
		printf("File cannot be open\n");
		exit(-1);
	}

	while (fscanf(rec, "%[^|]|%[^|]|%d|%d/%d/%d|%[^|]|%[^|]|%d:%d|%d:%d|%[^|]|%lf\n", &M[count].L.vName, &M[count].L.vID, &M[count].L.maxV, &M[count].L.day, &M[count].L.month, &M[count].L.year, &M[count].viN, &M[count].viIC, &M[count].hEn, &M[count].mEn, &M[count].hEx, &M[count].mEx, &M[count].tel, &M[count].tempe) != EOF)
	{
		count++;
	}
	fclose(rec);

	do {

		rewind(stdin);
		printf("\nPlease enter the correct name to modify the specific data: ");
		scanf("%[^\n]", &o);

		for (x = 0; x < count; x++) {

			if (strcmp(o, M[x].viN) == 0)
			{
				printf("\nVenue name: ");
				rewind(stdin);
				scanf("%[^\n]", &m[x].L.vName);


				printf("\nVenue ID: ");
				rewind(stdin);
				scanf("%[^\n]", &m[x].L.vID);

				printf("\nMaximum visitor: ");
				rewind(stdin);
				scanf("%d", &m[x].L.maxV);


				printf("\nYears: ");
				rewind(stdin);
				scanf("%d", &m[x].L.year);

				printf("\nMonth (1 ~ 12 = January ~ December): ");
				scanf("%d", &m[x].L.month);

				while (m[x].L.month < 1 || m[x].L.month > 12) {

					printf("Invalid input\n");
					printf("please check again (1 ~ 12 = January ~ December): ");
					rewind(stdin);
					scanf("%d", &m[x].L.month);
				}


				switch (m[x].L.month)
				{

				case 1: rewind(stdin);
					printf("\nPlease enter day (1 ~ 31): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 31)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's January): ");
						scanf("%d", &m[x].L.day);
					}
					break;

				case 2:
					if (m[x].L.year % 4 == 0)
					{
						rewind(stdin);
						printf("\nPlease enter day (1 ~ 29): ");
						scanf("%d", &m[x].L.day);


						while (m[x].L.day < 1 || m[x].L.day > 29)
						{

							printf("\nInvalid input\n");
							rewind(stdin);
							printf("\nPlease enter day again (In a leap year, February has 29 days): ");
							scanf("%d", &m[x].L.day);
						}

					}

					else if (m[x].L.year % 4 != 0)
					{
						rewind(stdin);
						printf("\nPlease enter day (1 ~ 28): ");
						scanf("%d", &m[x].L.day);

						while (m[x].L.day < 1 || m[x].L.day > 28)
						{
							printf("Invalid input\n");
							rewind(stdin);
							printf("\nPlease enter day again (February has 28 days): ");
							scanf("%d", &m[x].L.day);
						}
					}
					break;

				case 3: rewind(stdin);

					printf("\nPlease enter day (1 ~ 31): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 31)
					{

						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's March): ");
						scanf("%d", &m[x].L.day);

					}

					break;

				case 4: rewind(stdin);
					printf("\nPlease enter day (1 ~ 30): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 30)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's April): ");
						scanf("%d", &m[x].L.day);
					}
					break;

				case 5: rewind(stdin);
					printf("\nPlease enter day (1 ~ 31): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 31)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's May): ");
						scanf("%d", &m[x].L.day);
					}
					break;

				case 6: rewind(stdin);
					printf("\nPlease enter day (1 ~ 30): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 30)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's June): ");
						scanf("%d", &m[x].L.day);
					}
					break;

				case 7: rewind(stdin);
					printf("\nPlease enter day (1 ~ 31): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 31)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's July): ");
						scanf("%d", &m[x].L.day);
					}
					break;

				case 8: rewind(stdin);
					printf("\nPlease enter day (1 ~ 31): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 31)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's August): ");
						scanf("%d", &m[x].L.day);
					}
					break;

				case 9: rewind(stdin);
					printf("\nPlease enter day (1 ~ 30): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 30)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's September): ");
						scanf("%d", &m[x].L.day);
					}
					break;


				case 10: rewind(stdin);
					printf("\nPlease enter day (1 ~ 31): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 31)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's October): ");
						scanf("%d", &m[x].L.day);
					}
					break;

				case 11: rewind(stdin);
					printf("\nPlease enter day (1 ~ 30): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 30)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\n\nPlease enter day again (It's November): ");
						scanf("%d", &m[x].L.day);
					}
					break;

				case 12: rewind(stdin);
					printf("\nPlease enter day (1 ~ 31): ");
					scanf("%d", &m[x].L.day);
					while (m[x].L.day < 1 || m[x].L.day > 31)
					{
						printf("Invalid input\n");
						rewind(stdin);
						printf("\nPlease enter day again (It's December): ");
						scanf("%d", &m[x].L.day);
					}
					break;
				}


				rewind(stdin);
				printf("\nVisitor name: ");
				scanf("%[^\n]", &m[x].viN);

				rewind(stdin);
				printf("\nVisitor IC (Please enter by this concept = xxxxxx-xx-xxxx): ");
				scanf("%[^\n]", &m[x].viIC);


				rewind(stdin);
				printf("\nTime Entered (Minutes, please enter 1 ~ 60): ");
				scanf("%d", &m[x].mEn);

				while (m[x].mEn < 1 || m[x].mEn >60) {
					printf("\nError integer Input! (Enter 1 ~ 60 (minutes)): ");
					scanf("%d", &m[x].mEn);
					rewind(stdin);
				}

				printf("\nTime Entered (Hours, please enter in 24-hour concept 1 ~ 24 ): ");
				scanf("%d", &m[x].hEn);
				rewind(stdin);

				while (m[x].hEn < 1 || m[x].hEn > 24) {
					printf("\nError integer Input! (Enter 1 ~ 24 (hours)): ");
					scanf("%d", &m[x].hEn);
					rewind(stdin);
				}


				printf("\nTime Exited (Minutes, please enter 1 ~ 60): ");
				scanf("%d", &m[x].mEx);
				rewind(stdin);

				while (m[x].mEx < 1 || m[x].mEx >60) {
					printf("\nError integer Input! (Enter 1 ~ 60 (minutes)): ");
					scanf("%d", &m[x].mEx);
					rewind(stdin);
				}

				printf("\nTime Exited (Hours, please enter in 24-hour concept 1 ~ 24 ): ");
				scanf("%d", &m[x].hEx);
				rewind(stdin);

				while (m[x].hEx < 1 || m[x].hEx > 24) {
					printf("\nError integer Input! (Enter 1 ~ 24 (hours)): ");
					scanf("%d", &m[x].hEx);
					rewind(stdin);
				}


				printf("\nTelephone numbers (Please enter by following concept: E.x. 012-3456789): ");
				scanf("%[^\n]", &m[x].tel);
				rewind(stdin);

				printf("\nTemperature (Please enter in Celsius E.x 36.1): ");
				scanf("%lf", &m[x].tempe);

				if (m[x].tempe > 38)
					printf("\nYou are getting a fever!");


				else if (m[x].tempe < 35)
					printf("\nunusual temperature");


				rewind(stdin);
				printf("\n\nAre you sure want to modify? (Y/y to continue): ");
				scanf("%c", &lol);

				if (lol == 'Y' || lol == 'y') {

					strcpy(M[x].L.vName, m[x].L.vName);
					strcpy(M[x].L.vID, m[x].L.vID);
					M[x].L.maxV = m[x].L.maxV;
					M[x].L.day = m[x].L.day;
					M[x].L.month = m[x].L.month;
					M[x].L.year = m[x].L.year;
					strcpy(M[x].viN, m[x].viN);
					strcpy(M[x].viIC, m[x].viIC);

					M[x].mEn = m[x].mEn;
					M[x].hEn = m[x].hEn;
					M[x].mEx = m[x].mEx;
					M[x].hEx = m[x].hEx;
					strcpy(M[x].tel, m[x].tel);
					M[x].tempe = m[x].tempe;
					c++;

				} break;
			}
		}


		printf("\n\nDo you want to continue to modify more data? (Y/y to continue): ");
		rewind(stdin);
		scanf("%c", &n);



	} while (n == 'y' || n == 'Y');



	rec == fopen("Visit And Exit Records.txt", "w");

	if (rec == NULL)
	{
		printf("File cannot be open\n");
		exit(-1);
	}

	for (x = 0; x < count; x++) {

		fprintf(rec, "%s|%s|%d|%d/%d/%d|%s|%s|%2d:%2d|%2d:%2d|%s|%2.1lf\n", M[x].L.vName, M[x].L.vID, M[x].L.maxV, M[x].L.day, M[x].L.month, M[x].L.year, M[x].viN, M[x].viIC, M[x].hEn, M[x].mEn, M[x].hEx, M[x].mEx, M[x].tel, M[x].tempe);


	}
	printf("\n\n%d record(s) has been modified", c);

	fclose(rec);



}




void display() {

	rec = fopen("Visit And Exit Records.txt", "r");

	if (rec == NULL)
	{
		printf("File cannot be open\n");
		exit(-1);
	}

	printf("\n\n\t\tALL RECORD: \n\n");
	printf("\t-------------------\n\n\n");
	printf("\t+------------------------------~------------~-------------------~-------------------------~----------------~--------------~----------------~---------------~------------------~---------------+");
	printf("\n\t~          Venue name          |  Venue ID  |  Maximum visitor  |  Date (day/month/year)  |  Visitor name  |  Visitor IC  |  Time entered  |  Time exited  |  Contact number  |  Temperature  ~\n");

	while (fscanf(rec, "%[^|]|%[^|]|%d|%d/%d/%d|%[^|]|%[^|]|%d:%d|%d:%d|%[^|]|%lf\n", &N.L.vName, &N.L.vID, &N.L.maxV, &N.L.day, &N.L.month, &N.L.year, &N.viN, &N.viIC, &N.hEn, &N.mEn, &N.hEx, &N.mEx, &N.tel, &N.tempe) != EOF) {
		printf("\t!------------------------------+------------+-------------------+-------------------------+----------------+--------------+----------------+---------------+------------------+---------------!\n");
		printf("\t|%30s|%12s|%19d|%17d/%2d/%4d|%16s|%14s|%13d:%2d|%12d:%2d|%18s|%15.1lf|\n", N.L.vName, N.L.vID, N.L.maxV, N.L.day, N.L.month, N.L.year, N.viN, N.viIC, N.hEn, N.mEn, N.hEx, N.mEx, N.tel, N.tempe);

	}
	printf("\t+------------------------------~------------~-------------------~-------------------------~----------------~--------------~----------------~---------------~------------------~---------------+");

	fclose(rec);

}


FILE* fptr2;

void del() {


	int i = 0;
	char d[50], w, xd;

	do {

		rec = fopen("Visit And Exit Records.txt", "r");
		if (rec == NULL)
		{
			printf("File cannot be open\n");
			exit(-1);
		}

		fptr2 = fopen("wa.txt", "a");
		if (fptr2 == NULL)
		{
			printf("File cannot be open\n");
			exit(-1);
		}



		rewind(stdin);
		printf("\n\nEnter name to find the data to delete: ");
		scanf("%[^\n]", &d);


		while (fscanf(rec, "%[^|]|%[^|]|%d|%d/%d/%d|%[^|]|%[^|]|%d:%d|%d:%d|%[^|]|%lf\n", &N.L.vName, &N.L.vID, &N.L.maxV, &N.L.day, &N.L.month, &N.L.year, &N.viN, &N.viIC, &N.hEn, &N.mEn, &N.hEx, &N.mEx, &N.tel, &N.tempe) != EOF) {

			if (strcmp(d, N.L.vName) == 0) {
				printf("\n\n| \t Venue name: %s\n| \t  Venue ID: %s\n| \t   Maximum visitor: %d\n| \t    Date: %d/%d/%d\n| \t     Visitor name: %s\n| \t     Visitor IC: %s\n| \t    Time entered: %2d:%2d\n| \t   Time exited: %2d:%2d\n| \t  Contact number: %s\n| \t Temperature: %2.1lf\n", N.L.vName, N.L.vID, N.L.maxV, N.L.day, N.L.month, N.L.year, N.viN, N.viIC, N.mEn, N.hEn, N.mEx, N.hEx, N.tel, N.tempe);
				i++;
				printf("\nThis record has been removed");
			}

			else
				fprintf(fptr2, "%s|%s|%d|%d/%d/%d|%s|%s|%2d:%2d|%2d:%2d|%s|%2.1lf\n", N.L.vName, N.L.vID, N.L.maxV, N.L.day, N.L.month, N.L.year, N.viN, N.viIC, N.hEn, N.mEn, N.hEx, N.mEx, N.tel, N.tempe);

		}



		fclose(rec);
		fclose(fptr2);

		remove("Visit And Exit Records.txt");
		rename("wa.txt", "Visit And Exit Records.txt");


		rewind(stdin);
		printf("\n\nDo you want to delete more record? (Y/y to continue delete):");
		scanf("%c", &w);

	} while (w == 'Y' || w == 'y');

	printf("\n%d record has been removed", i);
}




void report() {

	char r;
	double tempe;
	int g = 0;

	do {

		rec = fopen("Visit And Exit Records.txt", "r");

		if (rec == NULL)
		{
			printf("File cannot be open\n");
			exit(-1);
		}


		rewind(stdin);
		printf("\nPlease enter abnormal temperature to report: ");
		scanf("%lf", &tempe);


		while (fscanf(rec, "%[^|]|%[^|]|%d|%d/%d/%d|%[^|]|%[^|]|%d:%d|%d:%d|%[^|]|%lf\n", &N.L.vName, &N.L.vID, &N.L.maxV, &N.L.day, &N.L.month, &N.L.year, &N.viN, &N.viIC, &N.hEn, &N.mEn, &N.hEx, &N.mEx, &N.tel, &N.tempe) != EOF) {

			if (tempe == N.tempe) {

				printf("\n\n| \t Venue name: %s\n| \t  Venue ID: %s\n| \t   Maximum visitor: %d\n| \t    Date: %d/%d/%d\n| \t     Visitor name: %s\n| \t     Visitor IC: %s\n| \t    Time entered: %d:%d\n| \t   Time exited: %d:%d\n| \t  Contact number: %s\n| \t Temperature: %2.1lf\n", N.L.vName, N.L.vID, N.L.maxV, N.L.day, N.L.month, N.L.year, N.viN, N.viIC, N.mEn, N.hEn, N.mEx, N.hEx, N.tel, N.tempe);
				printf("\nTHIS PERSON HAS BEEN REPORTED");
				g++;
			}
		}

		fclose(rec);

		rewind(stdin);
		printf("\n\nDo you want to continue to report? (Y/y to continue): ");
		scanf("%c", &r);

	} while (r == 'Y' || r == 'y');

	printf("\n%d has been reported", g);


}


void exits() {
	printf("\nThank you for using\n\n");

}
