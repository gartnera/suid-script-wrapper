#include <unistd.h>

int main(int argc, char **argv)
{
	//must be absolute path
	char* interpreter = "/usr/bin/python";

	//should be absolute path (prevents environment attacks)
	char* source = "suid-test.py";

	//one additional position for source name and one for NULL terminator
	char* args[argc + 2];

	//first argument will by binary name
	args[0] = argv[0];
	//second will be source file for the interpreter to execute
	args[1] = source;

	//for each arg in argv, add to args
	int i, j;
	for (i = 2, j = 1; i < argc; ++i, ++j)
	{
		args[i] = argv[j];
	}
	//terminate args
	args[i] = NULL;

	//call command
	execv(interpreter, args);
	return 0;
}
