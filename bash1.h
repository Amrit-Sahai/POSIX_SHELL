#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <signal.h>
//#include<string.h>
using namespace std;
int p;
map<string ,string> arr1;
string start1(string s)
{
	char *args[100];
	//string s;const char  * d=" "; 
	char s1[100]; int f=0;
//	printf(" %s@", getenv("USER"));
	
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
			string z="",k;int i;
			for(i=0;i<31;i++)
				z=z+buffer[i];
			  //cout<<z;
			if(s=="HOSTNAME")
				return z;
			if(s=="$PS1")
			{
				k=k+z+getcwd(s1,100);
				z=k;
			}
			return z;

			 
		

	}
}
	
void setenviron()
{
	//arr1["$PATH1"]=
	string k=start1("$PS1");
	string m=start1("$HOSTNAME");
	arr1["$PS1"]=k;
	arr1["$HOSTNAME"]=m;
	arr1["$HOME"]=getenv("HOME");
	arr1["$PATH"]=getenv("PATH");
	arr1["$USER"]=getenv("USER");
	//arr1["$HOSTNAME"]=
}
void ech(string s)
{
   int l=s.length();
   int i;
   for(i=0;i<l;i++)
   {
	   if(s[i]==' ')
		   break;
   }
    string z="";
   for(int k=i+1;k<l;k++)
   {
	   z=z+s[k];
	   
   }
   //cout<<z;
   //return;
   if(arr1.find(z)!=arr1.end())
   {
	   cout<<arr1[z]<<endl;
   }
	   
   else if(s[i+1]=='$'&&s[i+2]=='$')
	   cout<<getpid();
   
  else if(s[i+1]=='$'&&s[i+2]=='?')
	  cout<<p;  
   else if(s[i+1]=='$')
   {
	   string k=s.substr(i+2,l-1);
	  
	   char *arr=(char*)k.c_str();
	   cout<<getenv(arr)<<endl;
	   //cout<<k;
   }
   else if(s[i+1]=='"')
   {
	   int j;
	   for(j=i+2;j<l-1;j++)
		   cout<<s[j];
   }
   else
   {
	   int j;
	   for(j=i+1;j<l;j++)
	   {
		   if(s[j]!=' '&&s[j]!='"'&&s[j]!='\'')
			   cout<<s[j];
		   else if(s[j]==' '&&s[j-1]!=' ')
		   cout<<' ';
		   else 
			   continue;
	   }
          	   
   }
}
  

