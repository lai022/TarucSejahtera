#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning ( disable : 4996)

void Menu(void);
void Addition(void);
void Searching(void);
void Modifying(void);
void Displaying(void);
void Reporting(void);
void Deleting(void);

struct Date {
	int day;
	int month;
	int year;
};

struct Time {

	int hour;
	int min;

};

struct Admin {

	char name[31], ic[16], staffID[13], password[50], faculty[9];
	struct Date date;
	struct Time time;
	char contactNum[20];
	double temp;

};



void administrativeStaffModule() {

	int select;
	char choise;

	do {

		Menu();

		printf("\n\n\t\t\t\tWhat your selection:");
		scanf("%d", &select);
		rewind(stdin);

		system("cls");

		if (select == 1)
			Addition();

		else if (select == 2)
			Searching();

		else if (select == 3)
			Modifying();

		else if (select == 4)
			Displaying();

		else if (select == 5)
			Reporting();

		else if (select == 6)
			Deleting();

		while (select < 1 || select >7) {

			system("cls");

			Menu();
			printf("\n\n\t\t\t\t   WRONG INPUT!!!\n");
			printf("\n\n\t\t\t\tWhat your selection:");
			scanf("%d", &select);
			rewind(stdin);

			system("cls");

			if (select == 1)
				Addition();

			else if (select == 2)
				Searching();

			else if (select == 3)
				Modifying();

			else if (select == 4)
				Displaying();

			else if (select == 5)
				Reporting();

			else if (select == 6)
				Deleting();
		}
		printf("\n\tdo you want to go back to main menu? ('y' to go back / other to Exit)\n");
		printf("\tPls Enter your choose:");
		rewind(stdin);
		scanf("%c", &choise);

		system("cls");

	} while (choise == 'y');

	printf("\n\n\n\t\tThank you for using!!!\n\n\n\n");

}

void Menu(void) {

	printf("\n\t\t\t     Administrative Staff Module\n");
	printf("\n\t\t\t\t {     Menu:     }\n");
	printf("\t\t\t------------------------------------\n");
	printf("\t\t\t|\t1. Add new reconds\t   |\n");
	printf("\t\t\t|\t2. Search reconds\t   |\n");
	printf("\t\t\t|\t3. Modify reconds\t   |\n");
	printf("\t\t\t|\t4. Display reconds\t   |\n");
	printf("\t\t\t|\t5. Reports\t\t   |\n");
	printf("\t\t\t|\t6. Delete reconds\t   |\n");
	printf("\t\t\t|\t7. Exit\t\t\t   |\n");
	printf("\t\t\t------------------------------------\n");

}

void Addition(void) {

	struct Admin newrecord;
	char selectss;
	char datecheck;
	do {

		FILE* fp;

		fp = fopen("Administrative Staff Records.txt.txt", "a");

		if (fp == NULL) {

			printf("Unable to open the file\n");
			exit(-1);
		}



		printf("\t\t\t\t==================================\n");
		printf("\t\t\t\t||       Add New Reconds        ||\n");
		printf("\t\t\t\t==================================\n");

		printf("\n\n\t\t\tPlease Enter");
		printf("\n\t\t\t________________________");
		printf("\n\n\t\t\tName:");
		scanf("%[^\n]", &newrecord.name);
		rewind(stdin);

		printf("\n\t\t\tIC number (in format XXXXXX-XX-XXXX)  :");
		scanf("%[^\n]", &newrecord.ic);
		rewind(stdin);

		printf("\n\t\t\tStaff ID:");
		scanf("%[^\n]", &newrecord.staffID);
		rewind(stdin);

		printf("\n\t\t\tPassword:");
		scanf("%[^\n]", &newrecord.password);
		rewind(stdin);

		printf("\n\t\t\tFaculty:");
		scanf("%[^\n]", &newrecord.faculty);
		rewind(stdin);

		printf("\t\t\t---------------------------------\n");

		printf("\n\t\t\tPlease Enter The Date:\n");

		printf("\n\t\t\tyear:");
		scanf("%d", &newrecord.date.year);
		rewind(stdin);
		while (newrecord.date.year <= 1799 || newrecord.date.year >= 2022) {
			printf("\n\t\t\tYear is not valid.\n");
			printf("\n\t\t\tyear:");
			scanf("%d", &newrecord.date.year);
			rewind(stdin);
		};

		printf("\n\t\t\tmonth:");
		scanf("%d", &newrecord.date.month);
		rewind(stdin);
		while (newrecord.date.month < 1 || newrecord.date.month > 12) {
			printf("\n\t\t\tMonth is not valid.\n");
			printf("\n\t\t\tmonth:");
			scanf("%d", &newrecord.date.month);
			rewind(stdin);
		};

		do {
			printf("\n\t\t\tday:");
			scanf("%d", &newrecord.date.day);
			rewind(stdin);
			if ((newrecord.date.day >= 1 && newrecord.date.day <= 31) && (newrecord.date.month == 1 || newrecord.date.month == 3 || newrecord.date.month == 5 || newrecord.date.month == 7 || newrecord.date.month == 8 || newrecord.date.month == 10 || newrecord.date.month == 12))
				datecheck = 'y';
			else if ((newrecord.date.day >= 1 && newrecord.date.day <= 30) && (newrecord.date.month == 4 || newrecord.date.month == 6 || newrecord.date.month == 9 || newrecord.date.month == 11))
				datecheck = 'y';
			else if ((newrecord.date.day >= 1 && newrecord.date.day <= 28) && (newrecord.date.month == 2))
				datecheck = 'y';
			else if (newrecord.date.day == 29 && newrecord.date.month == 2 && (newrecord.date.year % 400 == 0 || (newrecord.date.year % 4 == 0 && newrecord.date.year % 100 != 0)))
				datecheck = 'y';
			else {
				printf("\n\t\t\tDay is invalid.\n");
				datecheck = 'n';
			}

		} while (datecheck == 'n');

		printf("\t\t\t---------------------------------\n");


		printf("\n\t\t\tPlease Enter Time (in 24 hours format)  :\n");

		printf("\n\t\t\thour :");
		scanf("%d", &newrecord.time.hour);
		rewind(stdin);
		while (newrecord.time.hour < 0 || newrecord.time.hour >= 24) {
			printf("\n\t\t\tHour is not valid.\n");
			printf("\n\t\t\thour:");
			scanf("%d", &newrecord.time.hour);
			rewind(stdin);
		}

		printf("\n\t\t\tMinute :");
		scanf("%d", &newrecord.time.min);
		rewind(stdin);
		while (newrecord.time.min < 1 || newrecord.time.min >= 60) {
			printf("\n\t\t\tMinute is not valid.\n");
			printf("\n\t\t\tMinute :");
			scanf("%d", &newrecord.time.min);
			rewind(stdin);
		}

		printf("\t\t\t---------------------------------\n");

		printf("\n\t\t\tTemperture:");
		scanf("%lf", &newrecord.temp);
		rewind(stdin);
		while (newrecord.temp < 34 || newrecord.temp >37) {
			printf("\n\t\t\tTemperture is not valid.\n");
			printf("\n\t\t\tTemperture:");
			scanf("%lf", &newrecord.temp);
			rewind(stdin);
		}

		printf("\n\t\t\tContact number (without '-') :");
		scanf("%[^\n]", &newrecord.contactNum);
		rewind(stdin);

		printf("\t\t\t---------------------------------\n");

		fprintf(fp, "%s|%s|%s|%s|%s|%d %d %d|%d %d|%s|%2.1lf\n", newrecord.name, newrecord.ic, newrecord.staffID, newrecord.password, newrecord.faculty, newrecord.date.day, newrecord.date.month, newrecord.date.year, newrecord.time.hour, newrecord.time.min, newrecord.contactNum, newrecord.temp);

		fclose(fp);

		printf("\n\t\t\tDo u want to add other new record? ('y' for Yes, other for no) ");
		printf("\n\t\t\tPls Enter your choose:");
		scanf("%c", &selectss);
		rewind(stdin);

		system("cls");

	} while (selectss == 'y' || selectss == 'Y');



}


void Searching(void) {


	struct Admin newrecord;
	char select;
	char name[30];

	FILE* searchrecord;


	do {

		searchrecord = fopen("Administrative Staff Records.txt", "r");

		if (searchrecord == NULL) {

			printf("Unable to open the file\n");
			exit(-1);
		}
		printf("\n\n                                                                       ================================                                                 \n");
		printf("                                                                       |||      Search Record       |||                                                 \n");
		printf("                                                                       ================================                                               \n\n");
		printf("\n\n\t\t\t\t\t\t  Please Enter the Name :");
		rewind(stdin);
		scanf("%[^\n]", &name);

		printf("\n\n\n\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");
		printf("\t|       Name       |        IC.no        |     staffID    |      Password       |     Faculty    |      Date      |   Time    |     Phone.no     |   Tempeture   |\n");

		fscanf(searchrecord, "%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &newrecord.name, &newrecord.ic, &newrecord.staffID, &newrecord.password, &newrecord.faculty, &newrecord.date.day, &newrecord.date.month, &newrecord.date.year, &newrecord.time.hour, &newrecord.time.min, &newrecord.contactNum, &newrecord.temp);

		while (!feof(searchrecord)) {


			if (strcmp(newrecord.name, name) == 0) {
				printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");

				printf("\t| %-16s | %-19s | %-14s | %-19s | %-14s | %2d-%2d-%-9d|   %d:%d   | %-16s |     %-2.1lfc     |\n", newrecord.name, newrecord.ic, newrecord.staffID, newrecord.password, newrecord.faculty, newrecord.date.day, newrecord.date.month, newrecord.date.year, newrecord.time.hour, newrecord.time.min, newrecord.contactNum, newrecord.temp);

			}

			fscanf(searchrecord, "\n%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &newrecord.name, &newrecord.ic, &newrecord.staffID, &newrecord.password, &newrecord.faculty, &newrecord.date.day, &newrecord.date.month, &newrecord.date.year, &newrecord.time.hour, &newrecord.time.min, &newrecord.contactNum, &newrecord.temp);

		}



		printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");

		printf("\n\n\n\n\t\t\t\t\t\t ============================================================================\n");
		printf("\t\t\t\t\t\t !!!      If there is empty meaning that the record cannot be found       !!! \n");
		printf("\t\t\t\t\t\t ============================================================================\n");

		printf("\n\t__________________________________________________________________________________________________________________________________________________________________");
		printf("\n\n\n\t\tDo you want to find other record? (press 'y' = yes / other = no)\n");
		printf("\t\tEnter your choose:");
		rewind(stdin);
		scanf("%c", &select);

		system("cls");

	} while (select == 'y' || select == 'Y');

	fclose(searchrecord);
}



void Modifying(void) {

	FILE* modifyrecord;
	FILE* editmodify;
	struct Admin p[100];
	char modname[30];
	char choose;
	int pCount = 0, i, y;
	char datechecking;

	char newPassword[30];
	int newYear, newMonth, newDay;
	int newHour, newMin;
	char newContactNum[13];


	modifyrecord = fopen("Administrative Staff Records.txt", "r");

	if (modifyrecord == NULL) {

		printf("file cannot be found\n");
		exit(-1);

	}

	fscanf(modifyrecord, "%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &p[pCount].name, &p[pCount].ic, &p[pCount].staffID, &p[pCount].password, &p[pCount].faculty, &p[pCount].date.day, &p[pCount].date.month, &p[pCount].date.year, &p[pCount].time.hour, &p[pCount].time.min, &p[pCount].contactNum, &p[pCount].temp);

	while (!feof(modifyrecord)) {

		pCount++;

		fscanf(modifyrecord, "\n%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &p[pCount].name, &p[pCount].ic, &p[pCount].staffID, &p[pCount].password, &p[pCount].faculty, &p[pCount].date.day, &p[pCount].date.month, &p[pCount].date.year, &p[pCount].time.hour, &p[pCount].time.min, &p[pCount].contactNum, &p[pCount].temp);
	}


	fclose(modifyrecord);

	do {

		printf("\n\n                                                                       ================================                                                 \n");
		printf("                                                                       |||      Modify Records      |||                                                 \n");
		printf("                                                                       ================================                                               \n\n");

		printf("\n\n\n\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");
		printf("\t|       Name       |        IC.no        |     staffID    |      Password       |     Faculty    |      Date      |   Time    |     Phone.no     |   Tempeture   |\n");
		printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");


		for (y = 0; y < pCount; y++) {

			printf("\t| %-16s | %-19s | %-14s | %-19s | %-14s | %2d-%2d-%-9d|   %d:%d   | %-16s |     %-2.1lfc     |\n", p[y].name, p[y].ic, p[y].staffID, p[y].password, p[y].faculty, p[y].date.day, p[y].date.month, p[y].date.year, p[y].time.hour, p[y].time.min, p[y].contactNum, p[y].temp);

		}

		printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");


		printf("\tWhich record you want to modify?\n");
		printf("\tEnter the Name:");
		scanf("%[^\n]", &modname);
		rewind(stdin);
		printf("\n\t ====================================================================================\n");
		printf("\t !!! If there is nothing to let you enter meaning that the record cannot be found !!! \n");
		printf("\t ====================================================================================\n\n");

		for (i = 0; i < pCount; i++) {

			if (strcmp(modname, p[i].name) == 0) {

				printf("\tPassword:");
				scanf("%[^\n]", &newPassword);
				rewind(stdin);

				printf("\t---------------------------------\n");

				printf("\tPlease enter the date:\n");

				printf("\tyear:");
				scanf("%d", &newYear);
				rewind(stdin);
				while (newYear <= 1799 || newYear >= 2022) {
					printf("\tYear is not valid.\n");
					printf("\tyear:");
					scanf("%d", &newYear);
					rewind(stdin);
				};

				printf("\tmonth:");
				scanf("%d", &newMonth);
				rewind(stdin);
				while (newMonth < 1 || newMonth > 12) {
					printf("\tMonth is not valid.\n");
					printf("\tmonth:");
					scanf("%d", &newMonth);
					rewind(stdin);
				};

				do {
					printf("\tday:");
					scanf("%d", &newDay);
					rewind(stdin);
					if ((newDay >= 1 && newDay <= 31) && (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12))
						datechecking = 'y';
					else if ((newDay >= 1 && newDay <= 30) && (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11))
						datechecking = 'y';
					else if ((newDay >= 1 && newDay <= 28) && (newMonth == 2))
						datechecking = 'y';
					else if (newDay == 29 && newMonth == 2 && (newYear % 400 == 0 || (newYear % 4 == 0 && newYear % 100 != 0)))
						datechecking = 'y';
					else {
						printf("\tDay is invalid.\n");
						datechecking = 'n';
					}

				} while (datechecking == 'n');

				printf("\t---------------------------------\n");

				printf("\tTime (in 24 hours format)\n");

				printf("\thour :");
				scanf("%d", &newHour);
				rewind(stdin);
				while (newHour < 0 || newHour >= 24) {
					printf("\tHour is not valid.\n");
					printf("\thour:");
					scanf("%d", &newHour);
					rewind(stdin);
				}

				printf("\tMinute :");
				scanf("%d", &newMin);
				rewind(stdin);
				while (newMin < 1 || newMin >= 60) {
					printf("\tMinute is not valid.\n");
					printf("\tMinute :");
					scanf("%d", &newMin);
					rewind(stdin);
				}

				printf("\t---------------------------------\n");

				printf("\tContact number:");
				scanf("%[^\n]", &newContactNum);
				rewind(stdin);


				printf("\t---------------------------------\n");

				printf("\n\n\tAre you sure to modify? (press 'y' = yes / other = no) \n");
				printf("\tEnter your choose:");
				scanf("%c", &choose);
				rewind(stdin);

				if (choose == 'y' || choose == 'Y') {


					strcpy(p[i].password, newPassword);
					p[i].date.year = newYear;
					p[i].date.month = newMonth;
					p[i].date.day = newDay;
					p[i].time.hour = newHour;
					p[i].time.min = newMin;
					strcpy(p[i].contactNum, newContactNum);


				}break;
			}
		}
		printf("\n\n\t---------------------------------\n");
		printf("\n\n\tdo want modify other records? (enter 'y' = yes/ other = no)\n");
		printf("\tEnter your answer:");
		scanf("%c", &choose);
		rewind(stdin);

		system("cls");

	} while (choose == 'y');

	editmodify = fopen("Administrative Staff Records.txt", "w");

	if (editmodify == NULL) {

		printf("file cannot be found\n");
		exit(-1);

	}

	for (y = 0; y < pCount; y++) {

		fprintf(editmodify, "%s|%s|%s|%s|%s|%d %d %d|%d %d|%s|%2.1lf\n", p[y].name, p[y].ic, p[y].staffID, p[y].password, p[y].faculty, p[y].date.day, p[y].date.month, p[y].date.year, p[y].time.hour, p[y].time.min, p[y].contactNum, p[y].temp);

	}

	fclose(editmodify);
}





void Displaying(void) {

	struct Admin newrecord;

	FILE* displayrecord;
	displayrecord = fopen("Administrative Staff Records.txt", "r");
	if (displayrecord == NULL) {

		printf("Unable to open the file\n");
		exit(-1);

	}

	printf("\n\n                                                                       =================================                                                \n");
	printf("                                                                       |||      Display Records      |||                                                 \n");
	printf("                                                                       =================================                                               \n\n");

	printf("\n\n\n\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");
	printf("\t|       Name       |        IC.no        |     staffID    |      Password       |     Faculty    |      Date      |   Time    |     Phone.no     |   Tempeture   |\n");

	fscanf(displayrecord, "%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &newrecord.name, &newrecord.ic, &newrecord.staffID, &newrecord.password, &newrecord.faculty, &newrecord.date.day, &newrecord.date.month, &newrecord.date.year, &newrecord.time.hour, &newrecord.time.min, &newrecord.contactNum, &newrecord.temp);

	while (!feof(displayrecord)) {

		printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");
		printf("\t| %-16s | %-19s | %-14s | %-19s | %-14s | %2d-%2d-%-9d|   %d:%d   | %-16s |     %-2.1lfc     |\n", newrecord.name, newrecord.ic, newrecord.staffID, newrecord.password, newrecord.faculty, newrecord.date.day, newrecord.date.month, newrecord.date.year, newrecord.time.hour, newrecord.time.min, newrecord.contactNum, newrecord.temp);
		fscanf(displayrecord, "\n%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &newrecord.name, &newrecord.ic, &newrecord.staffID, &newrecord.password, &newrecord.faculty, &newrecord.date.day, &newrecord.date.month, &newrecord.date.year, &newrecord.time.hour, &newrecord.time.min, &newrecord.contactNum, &newrecord.temp);
	}


	printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");

	fclose(displayrecord);

}



void Reporting(void) {

	struct Admin newrecord;

	char choose;
	int select, pCount = 0;

	FILE* reportrecord;


	do {
		printf("\n\n\t\t\t=====================================\n");
		printf("\t\t\t|||         Report Records        |||\n");
		printf("\t\t\t=====================================\n\n");
		printf("\t\t\tWhich report you want to see? \n\n\t\t\t1. Admin and Staff Information\n\t\t\t2. The High Risk With Sickness Report\n\n ");
		printf("\t\t\tPlease Enter your selection:");
		rewind(stdin);
		scanf("%d", &select);

		while (select != 1 && select != 2) {

			system("cls");
			printf("\n\n\t\t\t=====================================\n");
			printf("\t\t\t|||         Report Records        |||\n");
			printf("\t\t\t=====================================\n\n");
			printf("\n\t\t\t\t!!!WRONG INPUT!!!\n\n");
			printf("\t\t\tWhich report you want to see? \n\n\t\t\t1. Admin information\n\t\t\t2. The high risk with sickness\n\n ");
			printf("\t\t\tPlease Enter your selection:");
			rewind(stdin);
			scanf("%d", &select);
		}

		if (select == 2) {

			reportrecord = fopen("Administrative Staff Records.txt", "r");

			if (reportrecord == NULL) {

				printf("Unable to open the file\n");
				exit(-1);
			}

			printf("\n\n\n\t                                                          ========================================\n");
			printf("\t                                                          !! The High Risk With Sickness Report !!                                                                \n");
			printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");
			printf("\t|       Name       |        IC.no        |     staffID    |      Password       |     Faculty    |      Date      |   Time    |     Phone.no     |   Tempeture   |\n");
			printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");


			fscanf(reportrecord, "%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &newrecord.name, &newrecord.ic, &newrecord.staffID, &newrecord.password, &newrecord.faculty, &newrecord.date.day, &newrecord.date.month, &newrecord.date.year, &newrecord.time.hour, &newrecord.time.min, &newrecord.contactNum, &newrecord.temp);

			while (!feof(reportrecord)) {

				if (newrecord.temp > 36.5) {


					printf("\t| %-16s | %-19s | %-14s | %-19s | %-14s | %2d-%2d-%-9d|   %d:%d   | %-16s |     %-2.1lfc     |\n", newrecord.name, newrecord.ic, newrecord.staffID, newrecord.password, newrecord.faculty, newrecord.date.day, newrecord.date.month, newrecord.date.year, newrecord.time.hour, newrecord.time.min, newrecord.contactNum, newrecord.temp);
					printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");

				}

				fscanf(reportrecord, "\n%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &newrecord.name, &newrecord.ic, &newrecord.staffID, &newrecord.password, &newrecord.faculty, &newrecord.date.day, &newrecord.date.month, &newrecord.date.year, &newrecord.time.hour, &newrecord.time.min, &newrecord.contactNum, &newrecord.temp);

			}

			fclose(reportrecord);
		}
		else if (select == 1) {

			reportrecord = fopen("Administrative Staff Records.txt", "r");

			if (reportrecord == NULL) {

				printf("Unable to open the file\n");
				exit(-1);
			}
			printf("\n\n\n\t\t\t\t\t\t=================================\n");
			printf("\t\t\t\t\t\t!! Admin and Staff Information !!");
			printf("\n\t+------------------+---------------------+----------------+---------------------+----------------+----------------+\n");
			printf("\t|       Name       |        IC.no        |     staffID    |      Password       |     Faculty    |    Phone.no    |\n");

			fscanf(reportrecord, "%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &newrecord.name, &newrecord.ic, &newrecord.staffID, &newrecord.password, &newrecord.faculty, &newrecord.date.day, &newrecord.date.month, &newrecord.date.year, &newrecord.time.hour, &newrecord.time.min, &newrecord.contactNum, &newrecord.temp);


			while (!feof(reportrecord)) {

				printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+\n");
				printf("\t| %-16s | %-19s | %-14s | %-19s | %-14s |  %-14s|\n", newrecord.name, newrecord.ic, newrecord.staffID, newrecord.password, newrecord.faculty, newrecord.contactNum);

				fscanf(reportrecord, "\n%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &newrecord.name, &newrecord.ic, &newrecord.staffID, &newrecord.password, &newrecord.faculty, &newrecord.date.day, &newrecord.date.month, &newrecord.date.year, &newrecord.time.hour, &newrecord.time.min, &newrecord.contactNum, &newrecord.temp);


			}

			printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+\n");

			fclose(reportrecord);
		}

		printf("\n\n\n\n\t\t\t__________________________________________________\n");

		printf("\n\n\t\t\tDo you want to see other report? (press 'y' = yes / other = no)\n");
		printf("\t\t\tPlease Enter your choose:");
		rewind(stdin);
		scanf("%c", &choose);

		system("cls");


	} while (choose == 'y' || choose == 'Y');

}






void Deleting(void) {

	struct Admin p[100];
	int count = 0, x, deleted = 0, y;
	char name[50];
	char choose;

	FILE* fp;
	FILE* fptr;

	fp = fopen("Administrative Staff Records.txt", "r");

	if (fp == NULL) {

		printf("File cannot be found!");
		exit(-1);

	}

	fscanf(fp, "%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &p[count].name, &p[count].ic, &p[count].staffID, &p[count].password, &p[count].faculty, &p[count].date.day, &p[count].date.month, &p[count].date.year, &p[count].time.hour, &p[count].time.min, &p[count].contactNum, &p[count].temp);

	while (!feof(fp)) {

		count++;

		fscanf(fp, "\n%[^\|] | %[^\|] | %[^\|] | %[^\|] | %[^\|] | %d %d %d | %d %d | %[^\|] | %lf", &p[count].name, &p[count].ic, &p[count].staffID, &p[count].password, &p[count].faculty, &p[count].date.day, &p[count].date.month, &p[count].date.year, &p[count].time.hour, &p[count].time.min, &p[count].contactNum, &p[count].temp);
	}

	do {

		printf("\n\n                                                                       =================================                                                \n");
		printf("                                                                       |||      Delete  Records      |||                                                 \n");
		printf("                                                                       =================================                                               \n\n");

		printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");
		printf("\t|       Name       |        IC.no        |     staffID    |      Password       |     Faculty    |      Date      |   Time    |     Phone.no     |   Tempeture   |\n");
		printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");


		for (y = 0; y < count; y++) {

			printf("\t| %-16s | %-19s | %-14s | %-19s | %-14s | %2d-%2d-%-9d|   %d:%d   | %-16s |     %-2.1lfc     |\n", p[y].name, p[y].ic, p[y].staffID, p[y].password, p[y].faculty, p[y].date.day, p[y].date.month, p[y].date.year, p[y].time.hour, p[y].time.min, p[y].contactNum, p[y].temp);
			printf("\t+------------------+---------------------+----------------+---------------------+----------------+----------------+-----------+------------------+---------------+\n");

		}



		printf("\n\n\tEnter the name that you want to delete:");
		rewind(stdin);
		scanf("%[^\n]", &name);

		for (x = 0; x < count; x++) {

			if (strcmp(name, p[x].name) == 0) {

				while (x < count - 1) {

					p[x] = p[x + 1];
					x++;

				}
				count--;
				deleted++;
			}

		}
		printf("\n\n\tDo you want to delete other report? (press 'y' = yes / other = no)\n");
		printf("\tPlease Enter your choose:");
		rewind(stdin);
		scanf("%c", &choose);

		system("cls");

	} while (choose == 'Y' || choose == 'y');

	if (deleted == 1) {
		printf("\n\n\t!!! %d reocord has been deleted !!!\n\n\n", deleted);
	}
	else
		printf("\n\n\t!!! %d reocord have been deleted !!!\n\n\n", deleted);

	fptr = fopen("Administrative Staff Records.txt", "w");
	if (fptr == NULL) {

		printf("File cannot be found!");
		exit(-1);
	}

	for (y = 0; y < count; y++) {

		fprintf(fptr, "%s|%s|%s|%s|%s|%d %d %d|%d %d|%s|%2.1lf\n", p[y].name, p[y].ic, p[y].staffID, p[y].password, p[y].faculty, p[y].date.day, p[y].date.month, p[y].date.year, p[y].time.hour, p[y].time.min, p[y].contactNum, p[y].temp);

	}

	fclose(fp);
	fclose(fptr);

}
