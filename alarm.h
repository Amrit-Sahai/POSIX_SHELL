
//#define _POSIX_SOURCE
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include<fcntl.h>
#include<bits/stdc++.h>
#include<sys/wait.h>
#include<fcntl.h>
using namespace std;

int flag=0;


void ctch(int signum) 
{
  cout<<"alarm exist\n";
}
void alam(int x)
{
  /* struct sigaction sact;
  volatile double count;
  time_t t;

  sigemptyset(&sact.sa_mask);
  sact.sa_flags = 0;
  sact.sa_handler = ctch;
  sigaction(SIGALRM, &sact, NULL);
   */
   alarm(x);
  
}
	


