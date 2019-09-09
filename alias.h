#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <signal.h>
//#include<string.h>
using namespace std;
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