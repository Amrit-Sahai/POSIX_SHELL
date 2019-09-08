#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <signal.h>
#include<termios.h>
using namespace std;
int c=0;vector<string> hist;
int k;
map<string, string> arr;


	
int split(char **args,string s)
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
		    args[i]=&t[0];
		    i++;
		    continue;
		}
		
		args[i]=&r[i][0];
		i++;
	}
	args[i]=NULL;
	return i;
	
}

void alia(string s)
{
  int l=s.length();
  int i,j;string z,k;
  for(i=0;i<l;i++)
  {
     if(s[i]==' ')
        break;
  }
  for(j=i+1;j<l;j++)
  {
	  if(s[j]=='"')
		  continue;
	   if(s[j]=='=')
		  break;
	  if(s[j]!=' ')
		  k=k+s[j];
	 
  }
  for(i=j+2;i<l-1;i++)
	  z=z+s[i];
  map<string,string>::iterator t;
  for(t=arr.begin();t!=arr.end();t++)
  {
	  if(t->second==k)
	  {
		  arr.erase(t->first);
		  //arr.insert(pair<string,string>(t->first,t->second));
	  }
  }
   if(arr.find(z)==arr.end())
    arr.insert(pair<string,string>(z,k));
   else
   {
	   arr.erase(z);
	    arr.insert(pair<string,string>(z,k));
	//cout<<arr[z];
   } 
}  	

int checkalias(string k)
{
	map<string,string>::iterator t;
	string z,z1="";int f=0,flag=0,flag2=0;int i,j;
	 for(i=0;i<k.length();i++)
	   {
		       if(k[i]!=' ')
			   z=z+k[i];
		       else
		       break;
	   }
	   //cout<<z<<endl;
		for(t=arr.begin();t!=arr.end();t++)
		{
		    char *k2=(char *)z.c_str();
		    char *t1=(char *)(t->second).c_str();
		    if(strcmp(t1,k2)==0)
		    {
			  f=1;
			  z1=z1+t->first;
			  break;
		    }
		}
		//cout<<f;
		//cout<<z1<<endl;
		if(f==1)
		{
	      for(i=0;i<k.length();i++)
	      {
		      if(k[i]==' ')
			   break;
	      }
	     
			
			   for(j=i;j<k.length();j++)
				   z1=z1+k[j];
			      
			   k=z1;
		   
		        char *arr1[100];
			    split(arr1,k);
				pid_t pid;
			    pid =fork();

			if(pid==0)
			{

			    if(execvp(arr1[0],arr1)==-1)
			    {
				 perror("error");
			    }
		    }
			 else
			 {
			   wait(0);

			 }
		}
		return f;
		
}	
		
void start()
{
	char *args[100];
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
			} 
}
string check_keypress() 
{
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
			else if(ch_test[0] == 27) 
			{
				ch_test[1] = getchar();
				if (ch_test[1] == 91) 
				{
					ch_test[2] = getchar();
				
					if(ch_test[2] == 'A')
					{
					
						 cout<<"\r                                                                                            \r";
					     start();
						if(k>0)
						{
						  cout<<hist[k-1];
			              s=hist[k-1];
					    }
					
					    k--;
					    if(k<0&&hist.size()!=0)
					    k=hist.size()-1;
					
				    }
				       else if(ch_test[2] == 'B')
				       {
							cout<<"\r                                                                                           \r";
							start();
							if(c<hist.size())
							{
							  cout<<hist[c];
							  s=hist[c];
							  c++;
							}
				      }
				           else if(ch_test[2] == 'C')
					       cout<<'\t';
				           else if(ch_test[2] == 'D')
				           cout<<'\b';
				}
                else
		        ch = ch_test [1];
		    } 
		   else
		   {
			   if(ch_test[0]=='\b')
				   cout<<"\b \b";
				cout<<ch_test[0];
				if(ch_test[0]!='\n')
				{
			
					s=s+ch_test[0];
				}
			   ch = ch_test [0];
			}
	    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
	hist.push_back(s);
    return s;
}

void display()
{
	puts("\n\nWELCOME TO MY SHELL\n\n");
}


void append(string s, string k)
{
	//cout<<s;
	
	char *args[100];
	int num=split(args,s);
	//cout<<args[0]<<" "<<args[1];
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
		      perror("error");
	        }
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
	
	  z1=z1+" File100.txt";
	  
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
	   {
		   cout<<"hello";
	   wait(0);
	   }
	  
}

int main()
{
	 
while(1)
{  
    
	char *args[100];
	
	const char  * d=" "; 
	char s1[100]; int f=0;
	printf(" %s@", getenv("USER"));
	
	pid_t pid;
	fflush(stdout);
	
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
			//cout<<"heeloo";
			char buffer[1000];
			
			int fd=open("file500.txt",O_RDONLY);
			read(fd,buffer,1000);
			buffer[30]=' ';
			
			cout<<buffer<<getcwd(s1,100)<<'$'<<" ";

			 
		

	}
	

	string s=check_keypress();
	k=hist.size();
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
//	cout<<"hello";
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
	int c1=split(args,s);int h=0;
	if(string(args[0])=="alias")
	{
		alia(s);
		continue;
	}
	int flag=checkalias(s);
	if(flag==0)
	{
	
	//cout<<s<<endl;
	/*if(strcmp(args[c1-1],"&")==0)
	{
		cout<<"hello";
		args[c1-1]=NULL;
		 pid=fork();

		if(pid==0)
		{ 
	      
              setpgid(0,1);
			if(execvp(args[0],args)==-1)
			{
			perror("error");
			}
		}
		else
		{
			continue;
		}
	}*/
	
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
			if(args[2]==NULL)
				h=1;
            if(f==0&&(strcmp(args[1],">>"))==0)
		   {
			  // cout<<"hello";
			   append(args[0],args[2]);
			   //f=0;
			   continue;
		   }
             if(f==0&&h==0&&(strcmp(args[2],">>"))==0)
			 {
                 string d=string(args[0]);
				 string d1=string(args[1]);
			     string k=d+" "+d1;
				 //cout<<k;
                 append(k,args[3]);
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
		    if(f==0&&h==0&&args[2][0]=='>')
		   {
			   //cout<<args[0]<<endl;;
			   //cout<<args[2];
			     string d=string(args[0]);
				 string d1=string(args[1]);
			     string k=d+" "+d1;
				// char *arr1=(char*)k.c_str();
				 //cout << k;
                 append(k,args[3]);
				 continue;
		   }
		   
	
	fflush(stdout);
	fflush(stdin);

	 pid=fork();

	if(pid==0)
	{
		//cout<<"hello";

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
	else
	continue;
}
}