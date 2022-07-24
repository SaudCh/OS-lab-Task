#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<dirent.h>

int main(){
	int childpid;
	
	for(int i=0;i<4;i++){
		childpid = fork();
		if(childpid==-1)
		{
			printf("Failed to fork!");
		}
		
		if(childpid == 0){
			
			if(i==0)
			{
				//Child 1	
				execl("/bin/sh", "sh", "-c", "/bin/cat > saud.txt", NULL);	
			}
		}else if(i==1){
	           //Child 2
		   DIR *dir;
		   struct dirent *rd;
		   dir = opendir(".");
		   
		   if(dir == NULL)
		   {
		      printf("Error opening directory!");
		      exit(0);
		   }
		   
		   while((rd = readdir(dir)) != NULL)
		   {
		   	printf("Dir Name: %s\n",rd->d_name);
		   }
		   
		   closedir(dir);
			
		}else if(i==2){
			//child 3
			char *args[] = {"mkdir","folder",NULL};
              		execvp("/bin/mkdir",args);
		}else if(i==3)
		{
			//child 4
			char *args[] = {"rmdir","folder", NULL};
                        execvp("/bin/rmdir",args); 
		}
	
}

return 0;

}

