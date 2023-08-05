#include <proto/dos.h>
#include <proto/exec.h>

int main(int argc, char *argv[])
{
	if (!Cli())
	{
		PutStr((STRPTR)"Amiga Dynamically Linked Library\n");
		return 1;
	}
	Wait(SIGBREAKF_CTRL_C);
	return 0;
}
