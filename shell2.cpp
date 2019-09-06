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
int split2(vector<string>z,string s)
{
	int i,c=0;//s=s+" ";
	string k="";
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='"')
		 continue;
		if(s[i]!=' ')
		{
			k=k+s[i];
		}
		else
		{
             z.push_back(k);
			// cout<<z[0]<<endl;
			c++;
			//cout<<k;
			k="";
			//cout<<args[c]<<endl;
		}
	}
	z.push_back(k);
	c++;
	//z.push_back("");
	//cout<<"hello";
	//args[c]=NULL;
	//cout<<"hello";
	return c;
}
	
void split(char **args,string s)
{
		
	int i,c=0,f=1;string z="";

	stringstream ss(s);
	string r[10];
	i=0;
	while(ss>>r[i])
	{
		if(r[i][0]=='"'&&r[i][r[i].length()-1]=='"')
		{
			int l=r[i].length();
			string t="";
			for(int j=1;j<l-1;j++)
				t+=string(1,r[i][j]);
		args[i]=&t[0];//cout<<r[i]<<" ";
		i++;
		continue;
		}
		
		args[i]=&r[i][0];//cout<<r[i]<<" ";
		i++;
	}
	args[i]=NULL;
	
	//return args;
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
void pip(string s)
{
	int i,j,k1,m,c=0,f=0;string z1,z;
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
		perror("error");
	}
	
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
		    perror("error");
	      }
	   }
	   else
	  wait(0);
	  
    //wait(0);
	
    	 
	
}

int main()
{
	 
while(1)
{  
    //setenv("shell2.cpp","/home/",50);
	//display();
	char *args[100];
	string s;const char  * d=" "; 
	char s1[100]; int f=0;
	printf(" %s@", getenv("USER"));
	
	pid_t pid;
	fflush(stdout);
	//fflush(stdin);
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
			cout<<"heeloo";
			char buffer[1000];
			
			int fd=open("file500.txt",O_RDONLY);
			read(fd,buffer,1000);
			buffer[30]=' ';
			
			cout<<buffer<<getcwd(s1,100)<<'$'<<" ";

			 
		

	}
	

	getline(cin,s);
	if(s[0]==NULL)
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
		
	
	
		
	/*int i,c=0,f=1;string z="";

	char *ptr;
	ptr=strtok((char *) s.c_str()," ");
	
	while(ptr!=NULL)
	{
		args[c++]=ptr;
		ptr=strtok(NULL," ");
	}
	args[c]=NULL;*/
	/*vector<string> z;
	int c=split(z,s);
	cout<<c;
	for(i=0;i<c;i++)
	{
		args[i]=(char *) z[i].c_str();
		cout<<args[i]<<endl;
	}*/
	//args[i]=NULL;
	split(args,s);
	//cout<<args[1];
    if(strcmp(args[0],"cd")==0)
	{
		if (cd(args[1]) < 0) 
           perror(args[1]);
	       continue;
	} 
fflush(stdout);
fflush(stdin);
          // cout<<strargs[1].compare(">>");
              if(args[1]==NULL)
                f=1;	
            if(f==0&&(strcmp(args[1],">>"))==0)
		   {
			   cout<<"hello";
			   append(args[0],args[2]);
			   //f=0;
			   continue;
		   }			
	
		  if(f==0&&args[1][0]=='>')
		   {
			   //cout<<args[0]<<endl;;
			   //cout<<args[2];
			  cp(args[0],args[2]);
			  f=0;
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