#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    	int number = 1;
	int numberstore;

	DIR *fpdir;
	struct dirent *namefile;
	char buf[4096];
	int choice = 0;
	char bufpath[4096];
	char *pathname;

	if(argc == 1 || strcmp(argv[1], "--help") == 0)
	{
		printf("%s <file ...>\n", argv[0]);
		return 0;
	}

	while(choice != 100)
	{
		while(choice != 1 && choice != 2 && choice != 3 && choice != 4 &&  choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11 && choice != 12 && choice != 13 && choice != 100)
		{
			printf("Enter 1 to configure all packages on command line\n");
			printf("Enter 2 to fetch all packages on command line\n");
			printf("Enter 3 to make all packages on command line\n");
			printf("Enter 4 to install all packages on command line\n");
			printf("Enter 5 to uninstall all packages on command line\n");
			printf("Enter 6 to clean all packages on command line\n");
			printf("Enter 7 to fetch and extract ports tree\n");
			printf("Enter 8 to fetch and update ports tree\n");
			printf("Enter 9 to get shell\n");
			printf("Enter 10 to compile a kernel with a specific config (defaults to GENERIC).\n");
			printf("Enter 11 to install the GENERIC kernel\n");
			printf("Enter 12 to edit GENERIC i386 kernel config\n");
			printf("Enter 13 to edit GENERIC amd64 kernel config\n");
			printf("Enter 100 to exit\n");
			fflush(stdin);
			scanf("%d", &choice);
		}
		
		if(choice == 100)
		{
			return 0;
		}
		if(choice == 1)
		{
			number = 1;

			while(number < argc)
			{
				chdir(argv[number]);
				
				fpdir = opendir(argv[number]);

				while((namefile = readdir(fpdir)) != NULL)
				{
					if(strcmp(namefile->d_name, "Makefile") == 0)
					{
						system("make config-recursive");
					}
				}
				
				closedir(fpdir);

				number++;
			}
		}
		if(choice == 2)
		{
			number = 1;

			while(number < argc)
			{
				chdir(argv[number]);
				
				fpdir = opendir(argv[number]);

				while((namefile = readdir(fpdir)) != NULL)
				{
					if(strcmp(namefile->d_name, "Makefile") == 0)
					{
						system("make fetch-recursive");
					}
				}

				closedir(fpdir);

				number++;
			}
		}
		if(choice == 3)
		{
			number = 1;

			while(number < argc)
			{
				chdir(argv[number]);
				
				fpdir = opendir(argv[number]);

				while((namefile = readdir(fpdir)) != NULL)
				{
					if(strcmp(namefile->d_name, "Makefile") == 0)
					{
						system("make");
					}
				}

				closedir(fpdir);

				number++;
			}
		}
		if(choice == 4)
		{
			number = 1;

			while(number < argc)
			{
				chdir(argv[number]);

				fpdir = opendir(argv[number]);
				
				while((namefile = readdir(fpdir)) != NULL)
				{
					if(strcmp(namefile->d_name, "Makefile") == 0)
					{
						system("make install");
					}
				}

				closedir(fpdir);

				number++;
			}
		}
		if(choice == 5)
		{
			number = 1;
			
			while(number < argc)
			{
				for(int i = 0; i < sizeof(buf); i++)
				{
					buf[i] = '\0';
				}

				strncpy(buf, argv[number], sizeof(buf) - 1);

				char buffer[4096];

				snprintf(buffer, sizeof(buffer), "echo %s > .test1; gawk -F/ '{print $NF}' .test1 > .test2; pkg info `cat .test2` > .test3; pkg remove `cat .test3`; rm .test1 .test2 .test3", buf);

				system(buffer);

				for(int i = 0; i < sizeof(buffer); i++)
				{
					buffer[i] = '\0';
				}

				number++;
			}
		}
		if(choice == 6)
		{
			number = 1;
			
			while(number < argc)
			{
				chdir(argv[number]);

				fpdir = opendir(argv[number]);

				while((namefile = readdir(fpdir)) != NULL)
				{
					if(strcmp(namefile->d_name, "Makefile") == 0)
					{
						system("make clean");
					}
				}
			
				closedir(fpdir);

				number++;
			}
		}
		if(choice == 7)
		{
			chdir("/usr");

			system("portsnap fetch");
			system("portsnap extract");
		}
		if(choice == 8)
		{
			chdir("/usr");

			system("portsnap fetch");
			system("portsnap update");
		}
		if(choice == 9)
		{
			system("su -");
		}
		if(choice == 10)
		{
			chdir("/usr/src");
			system("make buildkernel KERNCONF=GENERIC");
		}
		if(choice == 11)
		{
			chdir("/usr/src");
			system("make installkernel KERNCONF=GENERIC");
		}
		if(choice == 12)
		{
			system("/usr/bin/vi /usr/src/sys/i386/conf/GENERIC");
		}
		if(choice == 13)
		{
			system("/usr/bin/vi /usr/src/sys/amd64/conf/GENERIC");
		}
		
		printf("Enter 1 to config all packages on command line\n");
		printf("Enter 2 to fetch all packages on command line\n");
		printf("Enter 3 to make all packages on command line\n");
		printf("Enter 4 to install all packages on command line\n");
		printf("Enter 5 to uninstall all packages on command line\n");
		printf("Enter 6 to clean all packages on command line\n");
		printf("Enter 7 to fetch and extract ports tree\n");
		printf("Enter 8 to fetch and update ports tree\n");
		printf("Enter 9 to get shell\n");
		printf("Enter 10 to compile a kernel with a specific config (defaults to GENERIC).\n");
		printf("Enter 11 to install the GENERIC kernel\n");
		printf("Enter 12 to edit GENERIC i386 kernel config\n");
		printf("Enter 13 to edit GENERIC amd64 kernel config\n");
		printf("Enter 100 to exit\n");

		fflush(stdin);
		scanf("%d", &choice);
	}

	return 0;
}
