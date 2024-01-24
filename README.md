# NPC Generator

This code segment implements an NPC (Non-Player Character) generator in C. It allows you to generate a random NPC with a name, gender, biography, likes, and personality traits. The generated NPC information can be displayed on the console and saved to a file.

## Usage

1. Compile the code using a C compiler.
2. Run the compiled executable.
3. Follow the prompts to enter the NPC's name and gender.
4. The program will generate a random biography, likes, and personality traits for the NPC.
5. The generated NPC information will be displayed on the console.
6. The NPC information will also be saved to a file with the NPC's name as the filename and a ".npc" extension.

## Dependencies

This code requires the following libraries:

- `stdio.h`
- `stdlib.h`
- `string.h`
- `time.h`

## NPC Structure

The NPC structure defined in the code has the following fields:

- `name`: The name of the NPC (character array of maximum length 100).
- `gender`: The gender of the NPC (character array of maximum length 10).
- `biography`: A brief biography of the NPC (character array of maximum length 500).
- `likes`: Likes and hobbies of the NPC (character array of maximum length 100).
- `personality`: Personality traits of the NPC (character array of maximum length 100).

## Functions

### `void generate_likes(char* likes)`

This function generates random likes and hobbies for the NPC and stores them in the `likes` character array.

### `void generate_personality(char* personality)`

This function generates random personality traits for the NPC and stores them in the `personality` character array.

### `void generate_bio(char* bio, const char* name, const char* gender)`

This function generates a random biography for the NPC based on the provided name and gender. The generated biography is stored in the `bio` character array.

### `int main()`

The main function of the program handles the user input, generates the NPC information, and saves it to a file. It utilizes the above helper functions to generate the NPC's biography, likes, and personality traits.
