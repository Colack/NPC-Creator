/*
(c) Jack Spencer 2023
Licensed under the Ludwig License.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100
#define MAX_GENDER_LENGTH 10
#define MAX_BIOGRAPHY_LENGTH 500
#define MAX_LIKES_LENGTH 100
#define MAX_PERSONALITY_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char gender[MAX_GENDER_LENGTH];
    char biography[MAX_BIOGRAPHY_LENGTH];
    char likes[MAX_LIKES_LENGTH];
    char personality[MAX_PERSONALITY_LENGTH];
} NPC;

int main() {
    char filename[MAX_NAME_LENGTH + 5]; // +5 for ".npc" extension

    printf("Enter NPC file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // remove trailing newline

    strcat(filename, ".npc");

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open NPC file.\n");
        return 1;
    }

    NPC npc;

    printf("NPC file contents:\n");
    printf("------------------\n");

    fscanf(file, "Name: %[^\n]\n", npc.name);
    fscanf(file, "Gender: %[^\n]\n", npc.gender);
    fscanf(file, "Biography: %[^\n]\n", npc.biography);
    fscanf(file, "%[^\n]\n", npc.likes);
    fscanf(file, "%[^\n]\n", npc.personality);

    printf("Name: %s\n", npc.name);
    printf("Gender: %s\n", npc.gender);
    printf("Biography: %s\n", npc.biography);
    printf("%s\n", npc.likes);
    printf("%s\n", npc.personality);

    fclose(file);

    return 0;
}
