#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labpzrl2.h"

int main(int argc, char** argv)
{
    if (argc < 4 || argc > 5)
    {
        printf("Ошибка пользовательского ввода: too few or too more arguments\n");
        exit(1);
    }
    if (!strcmp(argv[2], "-r"))
    {
        if (argc != 5)
        {
            printf("Ошибка пользовательского ввода: too few or too more arguments\n");
            exit(1);
        }
        fileReplace(argv[1], argv[3], argv[4]);
    }
    else if (!strcmp(argv[2], "-d"))
    {
        if (argc != 4)
        {
            printf("Ошибка пользовательского ввода: too few or too more arguments\n");
            exit(1);
        }
        fileDelete(argv[1], argv[3]);
    }
    else if (!strcmp(argv[2], "-i"))
    {
        if (argc != 5)
        {
            printf("Ошибка пользовательского ввода: too few or too more arguments\n");
            exit(1);
        }
        if (!strcmp(argv[3], "-f"))
        {
            fileFront(argv[1], argv[4]);
        }
        else if (!strcmp(argv[3], "-b"))
        {
            fileBack(argv[1], argv[4]);
        }
        else
        {
            printf("Ошибка пользовательского ввода: unknown flag\n");
            exit(1);
        }
    }
    else
    {
        printf("Ошибка пользовательского ввода: unknown flag\n");
        exit(1);
    }
    return 0;
}