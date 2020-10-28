#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include <dirent.h>
#include <dlfcn.h>
#include <string.h>

// Name: Parth Patel
// netID: ptp26
// RUID: 177003793
// your code for readdir goes here


struct dirent *readdir(DIR *dirp){

  //printf("MY FUNCTION IS BEING CALLED");
  
  struct dirent *(*my_readdir)(DIR *dirp);
  struct dirent *temp;
  char *isHidden = getenv("HIDDEN");
        
  my_readdir = dlsym (RTLD_NEXT, "readdir");

  while((temp = my_readdir(dirp))){

    if(strcmp (temp->d_name,isHidden) == 0){
      //printf("HIDDEN FILE\n");
      temp = readdir(dirp);
      return temp;
    } else {
      return temp;
    }
  } 
  
  return 0;  
}

