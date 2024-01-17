/*
(c) Jack Spencer 2023
Licensed under the Ludwig License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

const char* hobbies[] = {
    "reading books", "playing sports", "painting", "cooking", "singing", "gardening", "programming",
    "playing video games", "watching movies", "watching TV", "listening to music", "playing board games",
    "playing card games", "playing chess", "playing checkers", "playing poker", "playing mahjong",
    "writing stories", "writing poems", "writing songs", "writing code", "writing letters",
    "making crafts", "making art", "making sculptures", "making pottery", "making jewelry"
};

const char* traits[] = {
    "friendly", "optimistic", "creative", "logical", "organized", "charismatic", "adventurous",
    "kind", "caring", "compassionate", "empathetic", "honest", "loyal", "trustworthy", "reliable",
};

void generate_likes(char* likes) {
    // Generate random likes for the NPC
    int num_hobbies = sizeof(hobbies) / sizeof(hobbies[0]);

    sprintf(likes, "Likes: ");

    // Generate random number of likes
    int num_likes_generated = rand() % 3 + 1;
    for (int i = 0; i < num_likes_generated; i++) {
        const char* like = hobbies[rand() % num_hobbies];
        strcat(likes, like);
        if (i != num_likes_generated - 1) {
            strcat(likes, ", ");
        }
    }
}

void generate_personality(char* personality) {
    // Generate a random personality for the NPC
    int num_traits = sizeof(traits) / sizeof(traits[0]);

    sprintf(personality, "Personality: ");

    // Generate random number of traits
    int num_traits_generated = rand() % 3 + 1;
    for (int i = 0; i < num_traits_generated; i++) {
        const char* trait = traits[rand() % num_traits];
        strcat(personality, trait);
        if (i != num_traits_generated - 1) {
            strcat(personality, ", ");
        }
    }
}

void generate_bio(char* bio, const char* name, const char* gender) {
    // Generate a random biography based on the NPC's name.
    sprintf(bio, "%s is a %s NPC. ", name, gender);

    // Generate random age
    int age = rand() % 80 + 20;
    sprintf(bio + strlen(bio), "They are %d years old. ", age);

    // Generate random height and weight
    int height = rand() % 50 + 150;
    int weight = rand() % 50 + 50;
    sprintf(bio + strlen(bio), "They are %d cm tall and weigh %d kg. ", height, weight);

    // Generate random hobbies
    int num_hobbies = sizeof(hobbies) / sizeof(hobbies[0]);
    sprintf(bio + strlen(bio), "Their hobbies include ");
    for (int i = 0; i < 3; i++) {
        const char* hobby = hobbies[rand() % num_hobbies];
        strcat(bio, hobby);
        if (i != 2) {
            strcat(bio, ", ");
        }
    }
    strcat(bio, ".");

    // Generate random likes and personality
    char likes[MAX_BIOGRAPHY_LENGTH];
    generate_likes(likes);
    char personality[MAX_BIOGRAPHY_LENGTH];
    generate_personality(personality);

    // Print generated information
    printf("Biography: %s\n", bio);
    printf("%s\n", likes);
    printf("%s\n", personality);
}

int main() {
    srand(time(NULL));

    NPC npc;
    
    printf("Enter NPC name: ");
    fgets(npc.name, sizeof(npc.name), stdin);
    npc.name[strcspn(npc.name, "\n")] = '\0'; // remove trailing newline
    
    printf("Enter NPC gender: ");
    fgets(npc.gender, sizeof(npc.gender), stdin);
    npc.gender[strcspn(npc.gender, "\n")] = '\0'; // remove trailing newline

    // Generate NPC information
    sprintf(npc.biography, "%s is a %s NPC. ", npc.name, npc.gender);

    // Generate random age
    int age = rand() % 80 + 20;
    sprintf(npc.biography + strlen(npc.biography), "They are %d years old. ", age);

    // Generate random height and weight
    int height = rand() % 50 + 150;
    int weight = rand() % 50 + 50;
    sprintf(npc.biography + strlen(npc.biography), "They are %d cm tall and weigh %d kg. ", height, weight);

    // Generate random hobbies
    const char* hobbies[] = {"reading", "painting", "cooking", "playing music", "gardening"};
    int num_hobbies = sizeof(hobbies) / sizeof(hobbies[0]);
    sprintf(npc.biography + strlen(npc.biography), "Their hobbies include ");
    for (int i = 0; i < 3; i++) {
        const char* hobby = hobbies[rand() % num_hobbies];
        strcat(npc.biography, hobby);
        if (i != 2) {
            strcat(npc.biography, ", ");
        }
    }
    strcat(npc.biography, ".");

    // Generate random likes and personality
    char likes[MAX_LIKES_LENGTH];
    generate_likes(likes);
    char personality[MAX_PERSONALITY_LENGTH];
    generate_personality(personality);

    // Store generated information in the NPC struct
    strcpy(npc.likes, likes);
    strcpy(npc.personality, personality);

    // Print NPC information
    printf("Name: %s\n", npc.name);
    printf("Gender: %s\n", npc.gender);
    printf("Biography: %s\n", npc.biography);
    printf("%s\n", npc.likes);
    printf("%s\n", npc.personality);

    char filename[MAX_NAME_LENGTH + 5]; // +5 for ".npc" extension
    snprintf(filename, sizeof(filename), "%s.npc", npc.name);
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create NPC file.\n");
        return 1;
    }
    fprintf(file, "Name: %s\n", npc.name);
    fprintf(file, "Gender: %s\n", npc.gender);
    fprintf(file, "Biography: %s\n", npc.biography);
    fprintf(file, "%s\n", npc.likes);
    fprintf(file, "%s\n", npc.personality);
    fclose(file);
    printf("NPC saved to file: %s\n", filename);

    return 0;
}
