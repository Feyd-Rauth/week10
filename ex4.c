#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    DIR *dir;
    struct stat s;
    struct dirent *dp;
    char buff[PATH_MAX + 1];
    int* inums = (int*)calloc(20, sizeof(int));
    int i = 0;
    const char* names[20];
    if ((dir = opendir("tmp")) == NULL)
    {
        printf("Cannot open .");
        return 1;
    }
    while ((dp = readdir(dir)) != NULL)
    {
        if((strcmp(".", dp->d_name) == 0) || (strcmp("..", dp->d_name) == 0))
        {
            continue;
        }
        inums[i] = dp->d_ino;
        names[i] = dp->d_name;
        i++;
    }

    for (int k = 0; k < i + 1; k++)
    {
        for(int j = k + 1; j < i + 1; j++)
        {
            if(inums[k] == inums[j])
            {
                printf("%s %s\n", names[k], names[j]);
            }
        }
    }

}