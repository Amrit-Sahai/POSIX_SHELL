
#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <signal.h>
#include<termios.h>
#include "alias.h" 
#include "alarm.h" 
#include "bash1.h"
using namespace std;
int c=0;vector<string> hist;
int k;
void start()
{
	char *args[100];
	//string s;const char  * d=" "; 
	char s1[100]; int f=0;
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
			//cout<<'\n';

			 
		

	}
}
	
	string check_keypress() {
	string s="";
	
    struct termios old_settings, new_settings;
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ECHO|ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_settings);

    
    char ch = 0,ch_test[3] = {0,0,0};
	while(ch_test[0]!='\n')
	{
		ch_test[0] = getchar();
	if(ch_test[0]== 0x7f)
			{
				cout<<"\b \b";
				s=s.substr(0,s.size()-1);
			}
		else if(ch_test[0] == 27) {
			ch_test[1] = getchar();
			if (ch_test[1]=='C')
				start();
			if (ch_test[1] == 91) {
				ch_test[2] = getchar();
				if(ch_test[2] == 'A')
				{
					
					cout<<"\r                                                                             \r";
					//cout<<*rear1;
					//int k=hist.size();
					start();
					if(k>0)
					{
					cout<<hist[k-1];
					//s="";
					s=hist[k-1];
					}
					k--;
					if(k<0&&hist.size()!=0)
					k=hist.size()-1;
					//s[s.length()-1]='\0';
					//ch = -10;
				}
				else if(ch_test[2] == 'B')
				{
					cout<<"\r                                                                               \r";
					//cout<<*rear1;
					
					start();
					if(c<hist.size())
					{
					cout<<hist[c];
					//s="";
					s=hist[c];
					c++;
					}
					else
					c=0;	
				
					
				}
				else if(ch_test[2] == 'C')
					cout<<'\t';
				else if(ch_test[2] == 'D')
				   cout<<'\b';
			}
			else
				ch = ch_test [1];
		} else
		{
			cout<<ch_test[0];
			if(ch_test[0]!='\n')
			{
			
			s=s+ch_test[0];
			}
			ch = ch_test [0];
		}
	}
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
	//cout<<s<<"\n";
	hist.push_back(s);
    return s;
}

void display()
{
	puts("\n\nWELCOME TO MY SHELL\n\n");
}

void append(string s, string k)
{
	//cout<<"hello";
	char *args[100];
	split(args,s);
	pid_t pid =fork();
	if(pid==0)
	{
		char *a=(char *)k.c_str();
		int fd=open(a,O_WRONLY |O_APPEND, 0644);
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
	
    }
}	
void cp(string s,string k)
{
	char *args[100];
	split(args,s);
	pid_t pid=fork();
	
	if(pid==0)
	{
		char *a=(char *)k.c_str();
		int fd=open(a,O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
	
    }
}
	
int cd(char *path) 
{
	if(path==NULL)
	{
		//cout<<"!";
		return (chdir(getenv("HOME")));
	}
	return chdir(path);
}
void pip3(string s)
{
	
	int i,j,k1,m,c=0,f=0;string z1,z;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='|')
			c++;
	}
	
	for(i=0;i<s.length();i++)
	{
			
		if(s[i]!='|')
		{
			z=z+s[i];
		}
		if(s[i]=='|')
			break;
	}
     

     pid_t pid=fork();
	
	if(pid==0)
	{
		char *args[100];
		//char *a=(char *)k.c_str();
		split(args,z);
		int fd=open("File100.txt",O_WRONLY | O_CREAT | O_TRUNC , 0644);
		close(1);
		dup(fd);   

		close(fd);    

		
	    if(execvp(args[0],args)==-1)
	    {
			p=127;
		   perror("error");
	    }
		else
		p=0;	
	
	}
	else
	{
		wait(0);
	}
	m=i+1;
	for(k1=1;k1<c;k1++)
	{
		string k;
		while(s[m]!='|')
		{
			f=1;
			k=k+s[m];
			m++;
		} 
		   int fd1=open("File100.txt",O_RDONLY,0777);
		   int fd2=open("File1.txt",O_WRONLY | O_TRUNC | O_CREAT,0777);
		   while (1) 
           {
			  char buf[1000];
              int in = read(fd1, buf, 1000);
              if (in <= 0) break;
              int out = write(fd2, buf, in);
              if (out <= 0) break;
           }
		k=k+" File1.txt";
	  
        pid=fork();
	   if(pid==0)
	   {
			char *args[100];
			split(args,k);
			
			int fd=open("File100.txt",O_WRONLY | O_TRUNC | O_CREAT, 0777);
			close(1);
			dup(fd);   
			close(fd);
			if(execvp(args[0],args)==-1)
	        {
		      perror("error");
	        }
	   }
	  else
	  wait(0);
      m++;
	}
	
	
		if(f==1)
		{
			for(k1=m;k1<s.length();k1++)
				z1=z1+s[k1];
		}
		else
		{
			for(k1=i+1;k1<s.length();k1++)
				z1=z1+s[k1];
		}
		z1=z1+"File100.txt";
	   pid=fork();
	   if(pid==0)
	   {
			char *args[100];
			split(args,z1);
			
			int fd=open("File200.txt",O_WRONLY | O_TRUNC | O_CREAT, 0777);
			close(1);
			dup(fd);   
			close(fd);
			if(execvp(args[0],args)==-1)
	        {
				p=127;
		      perror("error");
	        }
			else
			p=0;
	   }
	   else
	   wait(0);

	
}
void pip2(string z1)
{
   int i;string s,k;
	for(i=0;i<z1.length();i++)
    {
		//cout<<"hello";
	 if(z1[i]!='>')
	 s=s+z1[i];
     if(z1[i]=='>')
		 break;
    }
     //cout<<s;
	//return;
	pip3(s);
	for(int j=i+1;j<z1.length();j++)
	{
		   if(z1[j]!=' ')
			k=k+z1[j];
	}
	   //cout<<k;
	       char *h=(char *)k.c_str();
	       int fd1=open("File200.txt",O_RDONLY,0777);
		   string z=string(h);
		   stringstream ss(z);
		   ss>>z;
		   h=&z[0];
		   int fd2=open(h,O_WRONLY | O_TRUNC | O_CREAT,0777);
		   while (1) 
           {
			  char buf[1000];
              int in = read(fd1, buf, 1000);
              if (in <= 0) break;
              int out = write(fd2, buf, in);
              if (out <= 0) break;
           }
	
}
void pip(string s)
{
	int i,j,k1,m,c=0,f=0;string z1,z;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='>')
		{
			pip2(s);
			return;
		}
	}
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='|')
			c++;
	}
	
	for(i=0;i<s.length();i++)
	{
		/*if(s[i]=='|')
          break;
                 */		
		if(s[i]!='|')
		{
			z=z+s[i];
		}
		if(s[i]=='|')
			break;
	}
     

       pid_t pid=fork();
	
	if(pid==0)
	{
		char *args[100];
		//char *a=(char *)k.c_str();
		split(args,z);
		int fd=open("File100.txt",O_WRONLY | O_CREAT | O_TRUNC , 0644);
		close(1);
		dup(fd);   

		close(fd);    

		
	if(execvp(args[0],args)==-1)
	{
		p=127;
		perror("error");
	}
	else
	p=0;
	
	}
	else
	{
		wait(0);
	}
	m=i+1;
	for(k1=1;k1<c;k1++)
	{
		string k;
		while(s[m]!='|')
		{
			f=1;
			k=k+s[m];
			m++;
		} 
		   int fd1=open("File100.txt",O_RDONLY,0777);
		   int fd2=open("File1.txt",O_WRONLY | O_TRUNC | O_CREAT,0777);
		   while (1) 
          {
			  char buf[1000];
            int in = read(fd1, buf, 1000);
             if (in <= 0) break;
            int out = write(fd2, buf, in);
             if (out <= 0) break;
          }
		k=k+" File1.txt";
	  //cout<<z1;
	  pid=fork();
	  if(pid==0)
	  {
	    char *args[100];
	  //char *args[100];
		//char *a=(char *)k.c_str();
		split(args,k);
		
		int fd=open("File100.txt",O_WRONLY | O_TRUNC | O_CREAT, 0777);
		 close(1);
		 dup(fd);   
         close(fd);
			if(execvp(args[0],args)==-1)
	       {
			   p=127;
		      perror("error");
	       }
		
	  }
	   else
	  wait(0);
    m++;
	}
	
		if(f==1)
		{
			for(k1=m;k1<s.length();k1++)
				z1=z1+s[k1];
		}
		else
		{
			for(k1=i+1;k1<s.length();k1++)
				z1=z1+s[k1];
		}
	
	  z1=z1+" File100.txt";
	  //cout<<z1;
	  char *args[100];
	  split(args,z1);
	    pid=fork();
		if(pid==0)
	   {
		   if(execvp(args[0],args)==-1)
	      {
			  p=127;
		    perror("error");
	      }
		  else
		   p=0;
	   }
	   else
	  wait(0);
	  
    //wait(0);
	
    	 
	
}

int main()
{
	
signal( SIGALRM, ctch); 
 while(1)
 {  
    setenviron();
    char *args[100];
	const char  * d=" "; 
	char s1[100]; int f=0;
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
		int fd=open("file500.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
			
			char buffer[1000];
			
			int fd=open("file500.txt",O_RDONLY);
			read(fd,buffer,1000);
			buffer[30]=' ';
			
			cout<<buffer<<getcwd(s1,100)<<'$'<<" ";

			 
		

	}
	

		string s=check_keypress();
		//cout<<s<<"hello";
		k=hist.size();
		if(s=="")
			continue;
		int i;
		
		for(i=0;i<s.length();i++)
		{
			if(s[i]=='|')
			{
				
				pip(s);
				break;
			}
		}
		if(i!=s.length())
			continue;
			
		
		
		char *arg[100];
		
		int c1=split(arg,s);int h=0;
		//cout<<arg[0];
		if(string(arg[0])=="echo")
		{
			ech(s);
			continue;
		}
		if(string(arg[0])=="alarm")
		{
			string k=arg[1];
			int t=stoi(k);
			//cout<<t;
			alam(t);
			continue;
		}

		if(string(arg[0])=="open")
		{
			string z=s.substr(5,s.length()-1);
			//cout<<z<<endl;
			string k="xdg-open ";
			z=k+z;
			s=z;
		}
		if(string(arg[0])=="alias")
		{
			alia(s);
			continue;
		}
		int flag=checkalias(s);
		//cout<<flag;
	
	if(flag==0)
	{
		 char *args1[100];
			 split(args1,s);
		//cout<<"hello";
		if(strcmp(args1[0],"cd")==0)
		{
			//cout<<args1[0]<<endl;
			if (cd(args1[1]) < 0) 
			perror(args1[1]);
			continue;
	    } 
				fflush(stdout);
				fflush(stdin);

				if(arg[1]==NULL)
                f=1;	
				if(f==0&&(strcmp(args1[1],">>"))==0)
			    {
			  
					append(args1[0],args1[2]);
			        continue;
		        }			
	
		    if(f==0&&args1[1][0]=='>')
		    {
			   
			  cp(args1[0],args1[2]);
			  f=0;
			  continue;
		    }
		   
	
	
			
			 pid=fork();

			if(pid==0)
			{
		       if(execvp(args1[0],args1)==-1)
	           {
				   p=127;
		         perror("error");
	           }
			   else
				p=0;
	        }
	      else
	      {
			wait(0);

	      }
	}
	else
   continue;
	

 }
}