#ifndef LABPZRL2_H
#define LABPZRL2_H

void fileReplace(const char *filename, const char *old_text, const char *new_text);
void fileDelete(const char *filename, const char *delete_text);
void fileFront(const char *filename, const char *text);
void fileBack(const char *filename, const char *text);

#endif