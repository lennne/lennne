#include<stdio.h>
#include<iostream>
#include<stdlib.h>
int no_of_processes,a_time[100],b_time[100],c_time[100],w_time[100],t_time[100],rb_time[100],tt_quantum=0,r_queue[100];
double avgt_time=0,avgw_time=0;
int cu_time,t_process,pointer,t_quantum_1,t_quantum_2,t_quantum_itr,r_processes;
int main()
{
using namespace std;
cout<<"How many number of process :";
cin>>no_of_processes;
cout<<"\n\nArrival time and burst time of each process\n"
;
for(int pid=0;pid<no_of_processes;pid++)
{
cout<<"\nProcess P"<<pid+1<<"\n";
cout<<"\tEnter arrival time = ";
cin>>a_time[pid];
cout<<"\tEnter burst time = ";
cin>>b_time[pid];
rb_time[pid]=b_time[pid];
tt_quantum+=b_time[pid];
}
cout<<"Assigning Processor.\n\n";
t_quantum_1=3;
t_quantum_2=6;
t_quantum_itr=1;
cu_time=0;
r_processes=no_of_processes;
for(int pid=0;pid<r_processes;pid++)
{
if(rb_time[pid]<t_quantum_1 && rb_time[pid]>=0&&cu_time<9)
{
cu_time+=rb_time[pid];
rb_time[pid]=0;
pointer = 1;
t_quantum_itr++;
r_processes--;
}
else if(rb_time[pid]>0&&cu_time<9)
{
if(t_quantum_itr==1)
{rb_time[pid]-=t_quantum_1;
t_quantum_itr++;
cu_time+=t_quantum_1;}
else if(t_quantum_itr==2)
{rb_time[pid]-=t_quantum_2;
cu_time+=t_quantum_2;}
}
else if(rb_time[pid]<9 && rb_time[pid]>=
3&&cu_time<9)
{
cu_time+=rb_time[pid];
rb_time[pid]=0;
r_processes--;
pointer = 1;
}
else if(rb_time[pid]>3&&cu_time<9)
{
rb_time[pid]-=t_quantum_2;
cu_time+=t_quantum_2;
}
if(rb_time[pid]==0 && pointer==1)
{
t_process--;
c_time[pid]=cu_time;
t_time[pid]=c_time[pid]-
a_time[pid];
w_time[pid]=t_time[pid]-
b_time[pid];
pointer = 0;
}
}
for(int pid=0;pid<r_processes;pid++)
{
int min =rb_time[0];
int i = 0,j=0;
for (i; i < no_of_processes; i++)
{
if (min > rb_time[i] && cu_time>a_time[i])
{
min = rb_time[i];
}
}
for (j; j < no_of_processes; j++)
{
if(rb_time[j]==min)
break;
}
if(cu_time>a_time[j] && min!=100000)
{
rb_time[j]=100000;
cu_time+=min;
c_time[j]=cu_time;
t_time[j]=c_time[j]-a_time[j];
w_time[j]=t_time[j]-b_time[j];
}
}
cout<<"\nProcess\t\tArival time\tBurst time\tCompletion time\tTurnaround Time\t\tWaiting time";
for(int i=0;i<no_of_processes;i++)
{
cout<<"\nP"<<i+1<<"\t\t"<<a_time[i]<<"\t\t"<<b_time[i]<<"\t\t"<<c_time[i]<<"\t\t\t"<<t_time[i]<<"\t\t\t"<<w_time[i];
}
for(int k=0;k<no_of_processes;k++)
{
avgw_time+=w_time[k];
avgt_time+=t_time[k];
}
cout<<"\n\n Average Turnaround time : "<<(avgt_time)/no_of_processes<<endl;
cout<<" Average Waiting time : "<<(avgw_time)/no_of_processes<<endl;
}
