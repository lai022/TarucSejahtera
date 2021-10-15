#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#pragma warning (disable:4996)
void sanitizationRecordsModule();
void visitorInformationModule();
void administrativeStaffModule();
void visitAndExitModule();
void main() {
	char choice;
	int selection;
	do {
		do {
			printf("\t\t\t\t\t\t\t--------------------------------------\n");
			printf("\t\t\t\t\t\t\t|                                    |\n");
			printf("\t\t\t\t\t\t\t|       WELCOME TO TARUCSEJAHTERA    |\n");
			printf("\t\t\t\t\t\t\t|                                    |\n");
			printf("\t\t\t\t\t\t\t--------------------------------------\n");
			printf("\t---------------------------- ---------------------------- -------------------------- ------------------------------ -----------------\n");
			printf("\t|                          | |                          | |                        | |                            | |               |\n");
			printf("\t| [1] VISITOR INFORMATION  | | [2] ADMINISTARTIVE STAFF | |  [3] VISIT AND EXIT    | |  [4] SANITIZATION RECORDS  | |  [5] Exit     |\n");
			printf("\t|          MODULE          | |           MODULE         | |          MODULE        | |            MODULE          | |               |\n");
			printf("\t---------------------------- ---------------------------- -------------------------- ------------------------------ -----------------\n");
			printf("\nPlease enter your selection (1-5),(5 for exit) :");
			rewind(stdin);
			scanf("%d", &selection);
			switch (selection) {
			case 1:
				visitorInformationModule();
				break;

			case 2:
				administrativeStaffModule();
				break;

			case 3:
				visitAndExitModule();
				break;

			case 4:
				system("cls");
				sanitizationRecordsModule();
				break;

			case 5:
				system("cls");
				printf("Exited\n");

			}

			
		} while (selection != 5 && isdigit(selection));
		printf("\nDo you want to go back to MAIN menu ?(Y/y=Yes):");
		rewind(stdin);
		scanf("%c", &choice);
		if (choice != 'y' && choice != 'Y') {
			system("cls");
			printf("\t\t\t\t\t\t\t--------------------------------------\n");
			printf("\t\t\t\t\t\t\t|                                    |\n");
			printf("\t\t\t\t\t\t\t|    THANK YOU AND HAVE A NICE DAY   |\n");
			printf("\t\t\t\t\t\t\t|                                    |\n");
			printf("\t\t\t\t\t\t\t--------------------------------------\n");
		}

	} while (toupper(choice)=='Y' && isalpha(choice));
}