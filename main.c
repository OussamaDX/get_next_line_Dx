#include "get_next_line.h"
#include "get_next_line_bonus.h"

//without bonus
int main()
{
    char *str;
	int fd;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n",str);

}

// for bonus
int main()
{
    char *str;
	char *s1;
	int fd;
	int fd1;

	fd = open("test.txt", O_RDONLY);
	fd1 = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	s1 = get_next_line(fd1);

	printf("%s\n",str);
	printf("%s",s1);
}

