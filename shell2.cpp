#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
using namespace std;

void display()
{
	puts("\n\nWELCOME TO MY SHELL\n\n");
}

int cd(char *path) 
{
	
	return chdir(path);
}
int main()
{
	 
while(1)
{
	display();
	char *args[100];string s;const char  * d=" "; char s1[100]; 
	printf(" %s@", getenv("USER"));
	
	pid_t pid;
	fflush(stdout);
	fflush(stdin);
	string z1="hostname";

	char *a=(char *)z1.c_str();
	args[0]=a;
	args[1]=NULL;
	pid=fork();
	
	if(pid==0)
	{
		int fd=open("file.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(1);
		dup(fd);   

		close(fd);    

		
	if(execvp(args[0],args)==-1)
	{
		perror("error");
	}
	  

	}
	else
	{
		    wait(0);
			char buffer[100];
			
			int fd=open("file.txt",O_RDONLY);
			read(fd,buffer,1000);
			buffer[30]=' ';
			
			cout<<buffer<<getcwd(s1,100)<<'$'<<" ";

			 
		

	}
	

	getline(cin,s);
	if(s[0]==NULL)
		continue;
	
	
		
	int i,c=0,f=1;string z="";

	char *ptr;
	ptr=strtok((char *) s.c_str()," ");
	
	while(ptr!=NULL)
	{
		args[c++]=ptr;
		ptr=strtok(NULL," ");
	}
	args[c]=NULL;
    if(strcmp(args[0],"cd")==0)
	{
		if (cd(args[1]) < 0) 
           perror(args[1]);
	   continue;
	}  
		   
	
	fflush(stdout);
	fflush(stdin);

	 pid=fork();

	if(pid==0)
	{

	if(execvp(args[0],args)==-1)
	{
		perror("error");
	}
	}
	else
	{
	wait(0);

	}

}
}