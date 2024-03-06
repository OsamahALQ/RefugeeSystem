#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "refugee.h"

int main() {
    NodeType *list = NULL;
	char choosingEAIYQ;

    char *temp = NULL;
    char *user_id = malloc(MAX_ID);
	char *nameP = malloc(MAX_STR);
	char *job = malloc(MAX_STR);

	int ageP;


	while (1) {
		printf("==========================\n");
		printf("what would you like to do?\n");
		printf("==========================\n");
		printf("Enter information (E)\n");
		printf("Display information (A)\n");
		printf("Display information for an individual (I)\n");
		printf("Show youngest person (Y)\n");
		printf("Remove a user (R)\n");
		printf("Sort data (S)\n");
		printf("Quit (Q)\n");
		printf("--------------------------\n");

		printf("Enter a choice from the menu (E, A, I, Y, R, S, Q): ");
		scanf("%s", &choosingEAIYQ);
		fgetc(stdin);
		size_t size = 0;
		if (choosingEAIYQ == 'E' || choosingEAIYQ == 'e')
		{
			while (1)
			{
				printf("Enter the userid: ");
				//scanf("%s", user_id);
        temp = NULL;
				getline(&temp, &size, stdin);
                strcpy(user_id, temp);
                free(temp);

				int valid = 1;
				for (int i = 0; i < (int)(strlen(user_id) - 1); i++) {
					if (!isdigit(user_id[i])) {
						valid = 0;
						break;

					}
				}
				if (valid == 1)
					break;
          printf("error userid must be alphanumeric\n");
			}

			user_id[strlen(user_id) - 1] = 0;
			printf("Enter the name: ");

			//scanf("%s[^\n]", nameP);
            temp = NULL;
            getline(&temp, &size, stdin);
            strcpy(nameP, temp);
            free(temp);
            nameP[strlen(nameP) - 1] = 0;

			printf("Enter the occupation: ");
			//scanf("%s[^\n]", job);
            temp = NULL;
			getline(&temp, &size, stdin);
            strcpy(job, temp);
            free(temp);
			job[strlen(job) - 1] = 0;
      //boolean ageWhile = true;
			while (1)
			{
				printf("Enter the age: ");
				scanf("%d", &ageP);

				if (ageP <= 0 || ageP > 120) {
					printf("error age must be between 1 and 120 \n");
          printf("Age is out of bound, Please ");
				}else{
          break;
        }

			}

            Refugee* user = NULL;
            init_refugee(user_id, nameP, job, ageP, &user);
			add_user(&list, user, 0);
		}
		else if (choosingEAIYQ == 'A' || choosingEAIYQ == 'a') {
			display_users(&list);
		}
		else if (choosingEAIYQ == 'I' || choosingEAIYQ == 'i') {
			printf("Enter the userid: ");
            temp = NULL;
            getline(&temp, &size, stdin);
			strcpy(user_id, temp);
            free(temp);

			user_id[strlen(user_id) - 1] = 0;
			// 			scanf("%s", user_id);
			search_user(&list, user_id);
		}
		else if (choosingEAIYQ == 'Y' || choosingEAIYQ == 'y') {
			Refugee* yougest = youngest_user(&list);
			if (yougest != NULL)
			{
				printf("The yougest user is: ");
				print_refugee(yougest);
			}
		}
		else if (choosingEAIYQ == 'R' || choosingEAIYQ == 'r') {
			printf("Enter the userid: ");
            temp = NULL;

			getline(&temp, &size, stdin);
			strcpy(user_id, temp);
            free(temp);

			user_id[strlen(user_id) - 1] = 0;
			// 			scanf("%s", user_id);
			remove_user(&list, user_id);
		}
		else if (choosingEAIYQ == 'S' || choosingEAIYQ == 's') {
			sort_data(&list);
		}
		else if (choosingEAIYQ == 'Q' || choosingEAIYQ == 'q') {
			break;
		}

		//printf("%i\n",users );

	}

	cleanup(list);

	free(user_id);
	free(nameP);
	free(job);

	return (0);
}
