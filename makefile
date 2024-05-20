# Run the command gcc -o writeNPC src/main.c

writeNPC: src/main.c
	gcc -o writeNPC src/main.c

readNPC: src/read.c
	gcc -o readNPC src/read.c

clean:
	rm writeNPC readNPC