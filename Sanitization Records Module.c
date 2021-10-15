#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#pragma warning (disable:4996)
struct Date {
	int day;
	int month;
	int year;
};

struct StartTime {
	int startHour;
	int startMinute;
};

struct EndTime {
	int endHour;
	int endMinute;
};

typedef struct {
	struct Date add;
	struct StartTime start;
	struct EndTime end;
	char venueID[10];
	char venueDescrip[30];
	char company[40];
	char worker[30];
	char contact[30];
	double temperature;
	char ic[30];
}Sanitization;

void Add();
void Search();
void Modify();
void Display();
void Report();
void ReportType(int selection);
void Delete();


void sanitizationRecordsModule() {
	int ch;
	char choice;

	do {
		do {
			printf("							-------------------------------------\n");
			printf("							|                                   |\n");
			printf("							|    SANITIZATION RECORDS MODULE    |\n");
			printf("							|                                   |\n");
			printf("							-------------------------------------\n");
			printf("\t--------------------- ----------------------- ------------------------ ------------------------\t---------------------- ---------------------- ----------------\n");
			printf("\t|                   | |                     | |                      | |                      |\t|                    | |                    | |              |\n");
			printf("\t| [1] ADD  RECORDS  | | [2] SEARCH RECORDS  | |  [3] MODIFY RECORDS  | |  [4] DISPLAY RECORDS |\t| [5] DISPLAY REPORT | | [6] DELETE RECORDS | |   [7] EXIT   |\n");
			printf("\t|                   | |                     | |                      | |                      |\t|                    | |                    | |              |\n");
			printf("\t--------------------- ----------------------- ------------------------ ------------------------\t---------------------- ---------------------- ----------------\n");
			printf("\n\nPlease enter your selection (1-7),(7 for exit) :");
			rewind(stdin);
			scanf("%d", &ch);
			switch (ch) {
			case 1:
				Add();
				break;

			case 2:
				Search();
				break;

			case 3:
				Modify();
				break;

			case 4:
				Display();
				break;

			case 5:
				Report();
				break;

			case 6:
				Delete();
				break;

			case 7:
				system("cls");
				printf("\nExited\n");
				break;

			}
		} while (ch != 7 && isdigit(ch));

		printf("\nDo you want to back to menu?(Y/y=Yes):");
		rewind(stdin);
		scanf("%c", &choice);
	} while (toupper(choice) == 'Y' && isalpha(choice));


}

void Add() {
	char choice,clear;
	int added = 0;
	Sanitization records;
	FILE* fp;
	fp = fopen("Sanitization Records.bin", "ab");
	if (fp == NULL) {
		printf("File does not exists\n");
		exit(-1);
	}

	printf("							-------------------------------------\n");
	printf("							|                                   |\n");
	printf("							|           ADDING RECORDS          |\n");
	printf("							|                                   |\n");
	printf("							-------------------------------------\n");

	do {
		do {
			printf("Please enter the date (day(1-31)):");
			rewind(stdin);
			scanf("%d", &records.add.day);
		} while (records.add.day < 0 || records.add.day>31);

		do {
			printf("Please enter the date (year):");
			rewind(stdin);
			scanf("%d", &records.add.year);
		} while (records.add.year < 2000 || records.add.year>2099);

		do {
			printf("Please enter the date (month):");
			rewind(stdin);
			scanf("%d", &records.add.month);
			if (records.add.month == 2) {
				if (records.add.year % 4 == 0) {
					if (records.add.day < 0 || records.add.day>29) {
						printf("This year is leap year.\n");
						printf("Please enter your day (1-29):");
						rewind(stdin);
						scanf("%d", &records.add.day);
					}
				}

				else {
					if (records.add.day < 0 || records.add.day>28) {
						printf("Please enter your day (1-28):");
						rewind(stdin);
						scanf("%d", &records.add.day);
					}
				}
			}

			if (records.add.month == 4 || records.add.month == 6 || records.add.month == 9 || records.add.month == 11) {
				if (records.add.day < 0 || records.add.day>30) {
					printf("This month has only 30 days.\n");
					printf("Please enter the date (day):");
					rewind(stdin);
					scanf("%d", &records.add.day);
				}
			}

		} while (records.add.month < 0 || records.add.month>12);


		printf("\n");

		do {
			printf("Please enter start time (hour(8-18)):");
			rewind(stdin);
			scanf("%d", &records.start.startHour);
		} while (records.start.startHour < 8 || records.start.startHour>18);

		do {
			printf("Please enter start time (minute):");
			rewind(stdin);
			scanf("%d", &records.start.startMinute);
			if (records.start.startMinute == 60) {
				records.start.startHour += 1;
				records.start.startMinute = 0;
			}
		} while (records.start.startMinute < 0 || records.start.startMinute>60);
		printf("\n");

		do {
			printf("Please enter end time (hour(8-18)):");
			rewind(stdin);
			scanf("%d", &records.end.endHour);
		} while (records.end.endHour < 8 || records.end.endHour>18);

		do {
			printf("Please enter end time (minute):");
			rewind(stdin);
			scanf("%d", &records.end.endMinute);
			if (records.end.endMinute == 60) {
				records.end.endHour += 1;
				records.end.endMinute = 0;
			}
		} while (records.end.endMinute < 0 || records.end.endMinute>60);


		printf("\n");
		printf("Please enter venue ID:");
		rewind(stdin);
		scanf("%s", records.venueID);
		printf("Please enter venue description:");
		rewind(stdin);
		scanf("%[^\n]", records.venueDescrip);
		printf("Please enter company name:");
		rewind(stdin);
		scanf("%[^\n]", records.company);
		printf("Please enter worker name:");
		rewind(stdin);
		scanf("%[^\n]", records.worker);
		printf("Please enter contact number (format in 000-0000):");
		rewind(stdin);
		scanf("%[^\n]", records.contact);

		do {
			printf("Please enter temperature(35-37):");
			rewind(stdin);
			scanf("%lf", &records.temperature);
		} while (records.temperature < 35 || records.temperature>37);

		printf("Please enter the worker s\' IC number (format in 000000-00-0000):");
		rewind(stdin);
		scanf("%[^\n]", records.ic);

		fwrite(&records, sizeof(Sanitization), 1, fp);

		added++;

		printf("\nAny more record(s) to be added? (Y/y=Yes):");
		rewind(stdin);
		scanf("%c", &choice);
		printf("Do you want to clear the screen?:");
		rewind(stdin);
		scanf("%c", &clear);
		if (toupper(clear) == 'Y') {
			system("cls");
		}

	} while (toupper(choice) == 'Y' && isalpha(choice));

	printf("\n%d record(s) added\n", added);

	fclose(fp);

}

void Search() {
	Sanitization records[100];
	int rCount=0,x;
	char search[30], choice,clear;
	FILE* fp2;
	fp2 = fopen("Sanitization Records.bin", "rb");
	if (fp2 == NULL) {
		printf("File does not exists\n");
		exit(-1);
	}


	printf("							-------------------------------------\n");
	printf("							|                                   |\n");
	printf("							|          SEARCHING RECORDS        |\n");
	printf("							|                                   |\n");
	printf("							-------------------------------------\n");


	while (fread(&records[rCount], sizeof(Sanitization), 1, fp2)) {
		rCount++;
	}

	do {
		printf("Please enter the worker s\' IC number:");
		rewind(stdin);
		scanf("%[^\n]", search);

		for(x=0;x<rCount;x++){
			if (strcmp(search, records[x].ic) == 0) {
				printf("\nDate          Start Time     End Time     VenueID & Description         Sanitization Company Name       Worker Name\tContact Number    Temperature\n");
				printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%d-%d-%-6d%7d:%d%12d:%d%13s%15s%23s%25s%20s%17.2lf\n", records[x].add.day, records[x].add.month, records[x].add.year, records[x].start.startHour, records[x].start.startMinute, records[x].end.endHour, records[x].end.endMinute, records[x].venueID, records[x].venueDescrip, records[x].company, records[x].worker, records[x].contact, records[x].temperature);
				printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				
			}

			
		}

		printf("\nAny more record(s) to be searched?(Y/y=yes):");
		rewind(stdin);
		scanf("%c", &choice);
		printf("\nDo you want to clear the screen?:");
		rewind(stdin);
		scanf("%c", &clear);
		if (toupper(clear) == 'Y') {
			system("cls");
		}
	} while (toupper(choice) == 'Y' && isalpha(choice));

	fclose(fp2);
}

void Modify() {
	Sanitization records[100];
	Sanitization modify;
	Sanitization temp;
	char search[30];
	int modified = 0, rCount = 0, x, y;
	char choice, selection,clear;

	FILE* fp3;
	fp3 = fopen("Sanitization Records.bin", "rb");
	if (fp3 == NULL) {
		printf("File does not exists\n");
		exit(-1);
	}

	printf("							-------------------------------------\n");
	printf("							|                                   |\n");
	printf("							|          MODIFYING RECORDS        |\n");
	printf("							|                                   |\n");
	printf("							-------------------------------------\n");


	while (fread(&records[rCount], sizeof(Sanitization), 1, fp3) != 0) {
		rCount++;
	}

	fclose(fp3);

	do {
		printf("Please enter the worker s\' IC number:");
		rewind(stdin);
		scanf("%[^\n]", search);
		for (x = 0; x < rCount; x++) {
			if (strcmp(search, records[x].ic) == 0) {
				printf("\n");
				printf("Before modify\n");
				printf("Date=%d-%d-%d\n", records[x].add.day, records[x].add.month, records[x].add.year);
				printf("Start time=%d:%d\n", records[x].start.startHour, records[x].start.startMinute);
				printf("End time=%d:%d\n", records[x].end.endHour, records[x].end.endMinute);
				printf("Venue ID=%s\n", records[x].venueID);
				printf("Venue description=%s\n", records[x].venueDescrip);
				printf("Sanitization Company Name=%s\n", records[x].company);
				printf("Worker name=%s\n", records[x].worker);
				printf("Contact number=%s\n", records[x].contact);
				printf("Temperature=%.2lf\n\n", records[x].temperature);
				printf("Do you want to modify the date (day) (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					do {
						printf("Please enter the date (day(1-31)):");
						rewind(stdin);
						scanf("%d", &modify.add.day);
					} while (modify.add.day < 0 || modify.add.day>31);
				}

				else {
					temp.add.day = records[x].add.day;
					modify.add.day = temp.add.day;
					records[x].add.day = modify.add.day;
				}

				printf("Do you want to modify the date (year) (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					do {
						printf("Please enter the date (year):");
						rewind(stdin);
						scanf("%d", &modify.add.year);
					} while (modify.add.year < 2000 || modify.add.year>2099);
				}

				else {
					temp.add.year = records[x].add.year;
					modify.add.year = temp.add.year;
					records[x].add.year = modify.add.year;
				}

				printf("Do you want to modify the date (month) (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					do {
						printf("Please enter the date (month):");
						rewind(stdin);
						scanf("%d", &modify.add.month);
						if (modify.add.month == 2) {
							if (modify.add.year % 4 == 0) {
								if (modify.add.day < 0 || modify.add.day>29) {
									printf("This year is leap year.\n");
									printf("Please enter your day (1-29):");
									rewind(stdin);
									scanf("%d", &modify.add.day);
								}
							}

							else {
								if (modify.add.day < 0 || modify.add.day>28) {
									printf("Please enter your day (1-28):");
									rewind(stdin);
									scanf("%d", &modify.add.day);
								}
							}
						}

						if (modify.add.month == 4 || modify.add.month == 6 || modify.add.month == 9 || modify.add.month == 11) {
							if (modify.add.day < 0 || modify.add.day>30) {
								printf("This month has only 30 days.\n");
								printf("Please enter the date (day):");
								rewind(stdin);
								scanf("%d", &modify.add.day);
							}
						}
					} while (modify.add.month < 0 || modify.add.month>12);
				}

				else {
					temp.add.month = records[x].add.month;
					modify.add.month = temp.add.month;
					records[x].add.month = modify.add.month;
				}
				printf("\n");

				printf("Do you want to modify start time (hour(0-24)) (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					do {
						printf("Please enter start time (hour(8-18)):");
						rewind(stdin);
						scanf("%d", &modify.start.startHour);
					} while (modify.start.startHour < 8 || modify.start.startHour>18);
				}

				else {
					temp.start.startHour = records[x].start.startHour;
					modify.start.startHour = temp.start.startHour;
					records[x].start.startHour = modify.start.startHour;
				}

				printf("Do you want to modify start time (minute) (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					do {
						printf("Please enter start time (minute):");
						rewind(stdin);
						scanf("%d", &modify.start.startMinute);
						
						if (modify.start.startMinute == 60) {
							modify.start.startHour += 1;
							modify.start.startMinute = 0;
						}
					} while (modify.start.startMinute < 0 || modify.start.startMinute>60);
				}

				else {
					temp.start.startMinute = records[x].start.startMinute;
					modify.start.startMinute = temp.start.startMinute;
					records[x].start.startMinute = modify.start.startMinute;
				}

				printf("\n");

				printf("Do you want to modify end time (hour(8-18)) (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					do {
						printf("Please enter end time (hour(0-24)):");
						rewind(stdin);
						scanf("%d", &modify.end.endHour);
					} while (modify.end.endHour < 8 || modify.end.endHour>18);
				}

				else {
					temp.end.endHour = records[x].end.endHour;
					modify.end.endHour = temp.end.endHour;
					records[x].end.endHour = modify.end.endHour;
				}

				printf("Do you want to modify end time (minute) (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					do {
						printf("Please enter end time (minute):");
						rewind(stdin);
						scanf("%d", &modify.end.endMinute);
						if (modify.end.endMinute == 60) {
							modify.end.endHour += 1;
							modify.end.endMinute = 00;
						}

					} while (modify.end.endMinute < 0 || modify.end.endMinute>60);
				}

				else {
					temp.end.endMinute = records[x].end.endMinute;
					modify.end.endMinute = temp.end.endMinute;
					records[x].end.endMinute = modify.end.endMinute;
				}


				printf("\n");

				printf("Do you want to modify venue ID (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					printf("Please enter venue ID:");
					rewind(stdin);
					scanf("%s", modify.venueID);
				}

				else {
					strcpy(temp.venueID, records[x].venueID);
					strcpy(modify.venueID, temp.venueID);
					strcpy(records[x].venueID, modify.venueID);
				}

				printf("Do you want to modify venue description (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					printf("Please enter venue description:");
					rewind(stdin);
					scanf("%[^\n]", modify.venueDescrip);
				}

				else {
					strcpy(temp.venueDescrip, records[x].venueDescrip);
					strcpy(modify.venueDescrip, temp.venueDescrip);
					strcpy(records[x].venueDescrip, modify.venueDescrip);
				}

				printf("Do you want to modify company name (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					printf("Please enter company name:");
					rewind(stdin);
					scanf("%[^\n]", modify.company);
				}

				else {
					strcpy(temp.company, records[x].company);
					strcpy(modify.company, temp.company);
					strcpy(records[x].company, modify.company);
				}

				printf("Do you want to modify worker s\' name (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					printf("Please enter worker name:");
					rewind(stdin);
					scanf("%[^\n]", modify.worker);
				}

				else {
					strcpy(temp.worker, records[x].worker);
					strcpy(modify.worker, temp.worker);
					strcpy(records[x].worker, modify.worker);
				}

				printf("Do you want to modify worker s\' contact number (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					printf("Please enter contact number (format in 000-0000):");
					rewind(stdin);
					scanf("%[^\n]", modify.contact);
				}

				else {
					strcpy(temp.contact, records[x].contact);
					strcpy(modify.contact, temp.contact);
					strcpy(records[x].contact, modify.contact);
				}

				printf("Do you want to modify worker s\' temperature (Y/y=Yes)?:");
				rewind(stdin);
				scanf("%c", &selection);
				if (toupper(selection) == 'Y' && isalpha(selection)) {
					do {
						printf("Please enter temperature (35-37):");
						rewind(stdin);
						scanf("%lf", &modify.temperature);
					} while (modify.temperature < 35 || modify.temperature>37);
				}

				else {
					temp.temperature = records[x].temperature;
					modify.temperature = temp.temperature;
					records[x].temperature = modify.temperature;
				}


				printf("\nAre you sure you want to modify it? (Y/y=Yes):");
				rewind(stdin);
				scanf("%c", &choice);

				if (toupper(choice) == 'Y' && isalpha(choice)) {
					records[x] = modify;
					printf("\nAfter modify:\n");
					printf("New Date=%d-%d-%d\n", records[x].add.day, records[x].add.month, records[x].add.year);
					printf("New start time=%d:%d\n", records[x].start.startHour, records[x].start.startMinute);
					printf("New end time=%d:%d\n", records[x].end.endHour, records[x].end.endMinute);
					printf("New venue ID=%s\n", records[x].venueID);
					printf("New venue description=%s\n", records[x].venueDescrip);
					printf("New sanitization Company Name=%s\n", records[x].company);
					printf("New worker name=%s\n", records[x].worker);
					printf("New contact number=%s\n", records[x].contact);
					printf("New temperature=%.2lf\n", records[x].temperature);
					strcpy(modify.ic, search);
					strcpy(records[x].ic, modify.ic);
					modified++;
				}


			}

		}
		printf("\nAny more record(s) to be modified?(Y/y=Yes):");
		rewind(stdin);
		scanf("%c", &choice);
		printf("\nDo you want to clear the screen?:");
		rewind(stdin);
		scanf("%c", &clear);
		if (toupper(clear) == 'Y') {
			system("cls");
		}

	} while (toupper(choice) == 'Y' && isalpha(choice));

	printf("\n%d record(s) modified", modified++);

	FILE* fp4;
	fp4 = fopen("Sanitization Records.bin", "wb");
	if (fp4 == NULL) {
		printf("File does not exists\n");
		exit(-1);
	}

	for (y = 0; y < rCount; y++) {
		fwrite(&records[y], sizeof(Sanitization), 1, fp4);
	}

	fclose(fp4);

}


void Display() {
	Sanitization records;
	int displayed = 0;
	char clear;
	FILE* fp5;
	fp5 = fopen("Sanitization Records.bin", "rb");
	if (fp5 == NULL) {
		printf("File does not exists\n");
		exit(-1);
	}


	printf("							-------------------------------------\n");
	printf("							|                                   |\n");
	printf("							|          DISPLAYING RECORDS       |\n");
	printf("							|                                   |\n");
	printf("							-------------------------------------\n");

	printf("\nDate          Start Time     End Time     Venue ID & Description         Sanitization Company Name       Worker Name\tContact Number    Temperature      IC No.\n");
	printf("=========================================================================================================================================================================\n");

	while (fread(&records, sizeof(Sanitization), 1, fp5) != 0) {
		printf("%-2d-%-2d-%-11d%-2d:%-11d%d:%-12d%-6s%-15s%24s%23s%17s%16.2lf%20s\n", records.add.day, records.add.month, records.add.year, records.start.startHour, records.start.startMinute, records.end.endHour, records.end.endMinute, records.venueID, records.venueDescrip, records.company, records.worker, records.contact, records.temperature, records.ic);
		displayed++;
	}

	printf("=========================================================================================================================================================================\n");
	printf("\n%d record(s) displayed", displayed);

	fclose(fp5);
	printf("\nDo you want to clear the screen?:");
	rewind(stdin);
	scanf("%c", &clear);
	if (toupper(clear) == 'Y') {
		system("cls");
	}



}

void Report() {
	int x;
	char choice,clear;

	printf("							-------------------------------------\n");
	printf("							|                                   |\n");
	printf("							|          DISPLAYING  REPORT       |\n");
	printf("							|                                   |\n");
	printf("							-------------------------------------\n");

	do {
		do {
			printf("\t\t\t\t\t---------------------\t\t--------------------------------------------\n");
			printf("\t\t\t\t\t|                   |\t\t|                                          |\n");
			printf("\t\t\t\t\t|  [1] TIME REPORT  |\t\t|  [2] SANITIZATION WORKER DETAILS REPORT  |\n");
			printf("\t\t\t\t\t|                   |\t\t|                                          |\n");
			printf("\t\t\t\t\t---------------------\t\t--------------------------------------------\n");
			printf("\nPlease enter your selection:");
			rewind(stdin);
			scanf("%d", &x);
			ReportType(x);
		} while (x > 2 && isdigit(x));

		printf("\nDo you want to go back to report menu (Y/y=Yes) ?:");
		rewind(stdin);
		scanf("%c", &choice);
		printf("\nDo you want to clear the screen?:");
		rewind(stdin);
		scanf("%c", &clear);
		if (toupper(clear) == 'Y') {
			system("cls");
		}

	} while (toupper(choice) == 'Y' && isalpha(choice));

}

void ReportType(int selection) {
	int hour1, hour2, time1, time2, difference1, difference2 = 0, day = 0, maxDuration = 0, minDuration = 0, record1 = 0, record2 = 0;
	double duration1, duration2, duration3, duration4, duration5 = 0, duration6 = 0, maxTemperature = 0;
	Sanitization records;
	FILE* fp6;
	fp6 = fopen("Sanitization Records.bin", "rb");
	if (fp6 == NULL) {
		printf("File does not exists\n");
		exit(-1);
	}
	switch (selection) {
	case 1:
		printf("							-------------------------------------\n");
		printf("							|                                   |\n");
		printf("							|              REPORT 1             |\n");
		printf("							|                                   |\n");
		printf("							-------------------------------------\n");

		printf("\n");
		printf("\t\t\t\tTIME REPORT\n");
		printf("Date              Start Hour      Start Minute        End Hour       End Minute      Duration\n");
		printf("===================================================================================================\n");
		while (fread(&records, sizeof(Sanitization), 1, fp6)) {
			hour2 = records.end.endHour * 60;
			hour1 = records.start.startHour * 60;
			time2 = hour2 + records.end.endMinute;
			time1 = hour1 + records.start.startMinute;
			difference1 = time2 - time1;
			duration1 = (double)(difference1 % 60);
			duration2 = difference1 / 60;
			printf("%-2d-%-2d-%-16d%-2d%16d%19d%15d%9dhour%-2dminute\n", records.add.day, records.add.month, records.add.year, records.start.startHour, records.start.startMinute, records.end.endHour, records.end.endMinute, (int)duration2, (int)duration1);
			difference2 += difference1;
			day++;
			record1++;
			if (difference1 > maxDuration) {
				maxDuration = difference1;
				duration5 = (double)(maxDuration % 60);
				duration6 = maxDuration / 60;
			}

		}
		printf("===================================================================================================\n");

		duration3 = (double)(difference2 % 60);
		duration4 = difference2 / 60;
		printf("%d record(s) listed\n", record1);
		printf("\nTotal Duration           : %dhour%dminute\n", (int)duration4, (int)duration3);
		printf("Total Days Recorded      : %d\n", day);
		printf("Longest Duration         : %-2dhour%dminute\n", (int)duration6, (int)duration5);

		break;

	case 2:
		printf("							-------------------------------------\n");
		printf("							|                                   |\n");
		printf("							|              REPORT 2             |\n");
		printf("							|                                   |\n");
		printf("							-------------------------------------\n");

		printf("\n");
		printf("\t\t\tSANITIZATION WORKER DETAILS REPORT\n");
		printf("Sanitization Company Name     Worker Name     Contact Number     Temperature    Ic No.\n");
		printf("==============================================================================================\n");
		while (fread(&records, sizeof(Sanitization), 1, fp6)) {
			printf("%-23s%15s%19s%15.2lf%20s\n", records.company, records.worker, records.contact, records.temperature, records.ic);
			record2++;
			if (records.temperature > maxTemperature) {
				maxTemperature = records.temperature;
			}

		}
		printf("==============================================================================================\n");
		printf("%d Sanitization Worker Details Listed\n", record2);
		printf("\nHighest Temperature Recorded:%.2lf\'C\n", maxTemperature);
		break;

	}

	fclose(fp6);
}

void Delete() {
	Sanitization records[100];
	int rCount = 0, x, deleted = 0, y;
	char ic[30];
	char choice,clear;
	FILE* fp7;
	fp7 = fopen("Sanitization Records.bin", "rb");
	if (fp7 == NULL) {
		printf("File does not exists\n");
		exit(-1);
	}

	printf("							-------------------------------------\n");
	printf("							|                                   |\n");
	printf("							|           DELETING RECORDS        |\n");
	printf("							|                                   |\n");
	printf("							-------------------------------------\n");


	while (fread(&records[rCount], sizeof(Sanitization), 1, fp7) != 0) {
		rCount++;
	}

	do {
		printf("Please enter worker \'s IC No.:");
		rewind(stdin);
		scanf("%s", ic);
		for (x = 0; x < rCount; x++) {
			if (strcmp(ic, records[x].ic) == 0) {
				printf("Are you sure you want to delete this worker \'s details?");
				rewind(stdin);
				scanf("%c", &choice);
				if (toupper(choice) == 'Y' && isalpha(choice)) {
					while (x < rCount - 1) {
						records[x] = records[x + 1];
						x++;
					}
					rCount--;
					deleted++;
				}

			}

		}
		printf("\nAnymore records to be deleted (Y/y=Yes)?");
		rewind(stdin);
		scanf("%c", &choice);
		printf("\nDo you want to clear the screen?:");
		rewind(stdin);
		scanf("%c", &clear);
		if (toupper(clear) == 'Y') {
			system("cls");
		}
	} while (toupper(choice) == 'Y' && isalpha(choice));

	printf("\n%d records deleted\n", deleted);

	FILE* fp8;
	fp8 = fopen("Sanitization Records.bin", "wb");
	if (fp8 == NULL) {
		printf("File does not exists\n");
		exit(-1);
	}

	for (y = 0; y < rCount; y++) {
		fwrite(&records[y], sizeof(Sanitization), 1, fp8);
	}

	fclose(fp7);
	fclose(fp8);
}

