/*************************************************************************
	> File Name: shixianll.c
	> Author: 
	> Mail: 
	> Created Time: 2019年04月27日 星期六 18时51分11秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h> //兼容
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
void showinfo(char *name) {
    struct stat st;
    if (stat(name, &st) <0) {
        perror("stat");
    }
    printf("%s\t%d\n", name, st.st_nlink);
}
    int main(int argc,char *argv[]){
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        showinfo(entry->d_name);
    }
    return 0;
        
}
