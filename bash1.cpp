#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
//#include<string.h>
using namespace std;
map<string, string> arr;
char *args[100];
/*void split(char **args,string s)
{
	//cout<<"hello";
		
	int i,c=0,f=1;string z="";

	char *ptr;
	ptr=strtok((char *) s.c_str()," ");
	
	while(ptr!=NULL)
	{
		args[c++]=ptr;
		ptr=strtok(NULL," ");
	}
	
	//cout<<args[0]<<"\n"<<args[1]<<"\n"<<args[2];
	args[c]=NULL;
}*/
void split(char **args,string s)
{
		
	int i,c=0,f=1;string z="";

	stringstream ss(s);
	string r[10];
	i=0;
	while(ss>>r[i])
	{
		args[i]=&r[i][0];//cout<<r[i]<<" ";
		i++;
	}
	args[i]=NULL;
	
	//return args;
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
void ech(string s)
{
   int l=s.length();
   int i;
   for(i=0;i<l;i++)
   {
	   if(s[i]==' ')
		   break;
   }
   if(s[i+1]=='$')
   {
	   string k=s.substr(i+2,l-1);
	  // if(k=="PS1")
		  // cout<<getcwd(k
	   char *arr=(char*)k.c_str();
	   cout<<getenv(arr);
	   //cout<<k;
   }
   else if(s[i+1]=='"')
   {
	   int j;
	   for(j=i+2;j<l;j++)
		   cout<<s[j];
   }
   else
   {
	   int j;
	   for(j=i+1;j<l;j++)
	   {
		   if(s[j]!=' '&&s[j]!='"')
			   cout<<s[j];
		   else if(s[j]==' '&&s[j-1]!=' ')
		   cout<<' ';
		   else 
			   continue;
	   }
          	   
   }
}
  
int main()
{
	while(1)
	{
	string k,z,z1="";int f=0,flag=0,flag2=0;int i,j;//char *args[100];
	getline(cin,k);
	//cout<<k<<"\n";
	
    /*split(args,k);
	
	//cout<<k<<endl;
	        
		string r="alias";
		char *k1=(char *)r.c_str();
		//cout<<args[0];
		//char *t1=(char *)(args[0]).c_str();
		
		
		if(strcmp(args[0],k1)==0)
		{
			//cout<<"hello";
			flag2=1;
			alia(k);
			continue;
	    }

	map<string,string>::iterator t;
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
	   
	   {
		   for(j=i;j<k.length();j++)
			   z1=z1+k[j];
	   }
	  //cout<<z1;
	  
		   char *arr1[100];
		   split(arr1,z1);
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
	   
		   
			
	/*for(t=arr.begin();t!=arr.end();t++)
	{
		//string k3="ll";
		char *k2=(char *)k.c_str();
		char *t1=(char *)(t->second).c_str();
		if(strcmp(t1,k2)==0)
		{
			//cout<<"hello";
			z=t->first;
		    flag =1;
			break;
		}
	}
	
	   if(flag==1)
	   {
	       
	   split(args,z);
	   }
	if(flag2==0&&flag==0)
	{
		//split(args,k);
	 
		for(t=arr.begin();t!=arr.end();t++)
		{
		//string k3="ll";
		//char *k1=(char *)args[0].c_str();
				char *t1=(char *)(t->second).c_str();
			if(strcmp(t1,args[0])==0)
			{
			//cout<<"hello";
				z1=t->first;
				f=1;
				break;
			}
		}
	  
		if(f==1)
		{
	
		char *t1=(char *)(z1).c_str();
		args[0]=t1;
		f=0;
		}
	}
		//ech(k);
		//continue;
		else
		{
			//cout<<"hello";
	 pid_t pid;
		 pid =fork();

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
	
	}*/
	ech(k);
}

return 1;
}