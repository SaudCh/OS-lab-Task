#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	
	int pfd1[2],pfd2[2];
    	pid_t cid1,cid2;

	
	if( (pipe(pfd1) == -1) || ((cid1=fork()) == -1 )){
		 perror("Failed to setup pipeline");
      		return 1;		
	}
	
	
	if(cid1 == 0){
		if (dup2(pfd1[1], STDOUT_FILENO) == -1)
		 perror("Failed to redirect stdout of ls");
	      else if ((close(pfd1[0]) == -1) || (close(pfd1[1]) == -1))
		 perror("Failed to close extra pipe descriptors on ls");
	      else {
		 execl("/bin/sort", "sort", "-n", "+4", NULL);
		 perror("Failed to exec ls");
	      }
	      
	      return 1;
	}else if(cid1>0){
	
		if (dup2(pfd1[0], STDIN_FILENO) == -1)         
		perror("Failed to redirect stdin of sort");
			else if ((close(pfd1[0]) == -1) || (close(pfd1[1]) == -1))
				perror("Failed to close extra pipe file descriptors on sort");
			else {
				execl("/bin/ls", "ls", "-l", NULL);
				perror("Failed to exec sort");
			}
			
			if( (pipe(pfd2) == -1 ) ||  ((cid2 = fork()) == -1 ) ){
				perror("Failed to setup pipeline 2");
		      		return 1;
			}	
			
			if (cid2 > 0) { 
			    dup2(pfd2[1], STDOUT_FILENO);
			    close(pfd2[0]);  
			    execl("/bin/sort", "sort", "-n", "+4", NULL);

			} else if (cid2 == 0) {
			    dup2(pfd2[0], STDIN_FILENO);
			    close(pfd2[1]);
			    execl("/bin/ls", "ls", "-l", NULL);
			}
			
		
	}
       
	
	
	
	return 0;
}
