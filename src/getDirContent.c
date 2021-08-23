#include <dirent.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* get_dir_content(char * path)
{
  DIR * d1 = opendir(path); // open the path
  if(d1==NULL) return (char)0; // if was not able, return
  struct dirent * dir; // for the directory entries
  int len = 0;
  int newLen = 0;
  while ((dir = readdir(d1)) != NULL) // if we were able to read somehting from the directory
    {
      if(dir-> d_type != DT_DIR)
      {
        newLen = strlen(dir->d_name);
        len = len + 1 + newLen;
      }
    }
  closedir(d1); 
  
  char* dir_content;
  dir_content = malloc(sizeof(char)*len);
  int n;
  DIR * d2 = opendir(path);
  bool firstCall = true;
  while ((dir = readdir(d2)) != NULL) // if we were able to read somehting from the directory
    {
      if(dir-> d_type != DT_DIR)
      {
        if (firstCall)
        {
          n = sprintf(dir_content, "%s", dir->d_name);
          firstCall = false;
        }
        else
        {
          n = sprintf(dir_content, "%s%s%s", dir_content, "\n", dir->d_name);
        }
      }
    }
  closedir(d2); // finally close the directory
  return dir_content;
}