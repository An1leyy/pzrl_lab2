#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labpzrl2.h"

void fileReplace(const char *filename, const char *old_text, const char *new_text)
{
    FILE *File = fopen(filename, "r");
    if (File == NULL)
    {
        printf("Не удалось открыть файл\n");
        exit(1);
    }
    FILE *temp_File = fopen("tempFile.txt", "w");
    if (temp_File == NULL)
    {
        printf("Не удалось открыть файл\n");
        exit(1);
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), File))
    {
        while (strstr(buffer, old_text) != NULL)
        {
            char *point = strstr(buffer, old_text);
            memmove(point, point + strlen(old_text), strlen(point + strlen(old_text)) + 1);
            memmove(point + strlen(new_text), point, strlen(point) + 1);
            for (size_t i = 0; i < strlen(new_text); i++)
            {
                *(point + i) = new_text[i];
            }
        }
        fputs(buffer, temp_File);
    }
    rename("tempFile.txt", filename);
    fclose(temp_File);
    fclose(File);
}

void fileDelete(const char *filename, const char *delete_text)
{
    FILE *File = fopen(filename, "r");
    if (File == NULL)
    {
        printf("Не удалось открыть файл\n");
        exit(1);
    }
    FILE *temp_File = fopen("tempFile.txt", "w");
    if (temp_File == NULL)
    {
        printf("Не удалось открыть файл\n");
        exit(1);
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), File))
    {
        while (strstr(buffer, delete_text) != NULL)
        {
            char *point = strstr(buffer, delete_text);
            memmove(point, point + strlen(delete_text), strlen(point + strlen(delete_text)) + 1);
        }
        fputs(buffer, temp_File);
    }
    rename("tempFile.txt", filename);
    fclose(temp_File);
    fclose(File);
}

void fileFront(const char *filename, const char *text)
{

}

void fileBack(const char *filename, const char *text)
{

}