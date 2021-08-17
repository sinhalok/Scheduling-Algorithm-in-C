
#include <stdio.h>
#include<stdio.h>
struct priority_preemptive
{
char pn;
int at, bt, ct, wt, tat, priority;
int s;
}pq[10];
int limit;
void at_Sorting()
{
struct priority_preemptive temp;
int i, j;
for(i = 0; i < limit - 1; i++)
{
for(j = i + 1; j < limit; j++)
{
if(pq[i].at > pq[j].at)
{
temp = pq[i];
pq[i] = pq[j];
pq[j] = temp;
}
}
}
}
int main()
{
char c; int x;
do{
printf("1.FCFS\n2.PRIORITY\n3.SJF\n4.ROUND ROBIN\n5.PRE-EMPTIVE PRIORITY\n6.SRTF\n");
scanf("%d",&x);
switch(x)
{
case 1:
{
int at[10],bt[10],gnc[10],wt[10],tat[10];
float awt=0;
float atat=0;
int n,i,j;
for(i=0;i<10;i++)
{
at[i]=0;
bt[i]=0;
gnc[i]=0;
tat[i]=0;
wt[i]=0;
}
printf("enter the number of process that you want to proceed \n");
scanf("%d",&n);
printf("enter all the process \n");
int p[10];
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("enter all the arrival time \n");
for(i=0;i<n;i++)
{
scanf("%d",&at[i]);
}
printf("enter all the brust time \n");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
gnc[0]=0;
for(i=0;i<10;i++)
gnc[i+1]=gnc[i]+bt[i];
for(i=0;i<n;i++)
{
wt[i]=gnc[i]-at[i];
tat[i]=gnc[i+1]-at[i];
awt=awt+wt[i];
atat=atat+tat[i];
}
awt =awt/n;
atat=atat/n;
printf("\n\tprocess\tarrival time\tbrust time\twaiting time\tturn arround time\n");
for(i=0;i<n;i++)
{
printf("\tp%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,at[i],bt[i],wt[i],tat[i]);
}
printf("the average waiting time is %f\n",awt);
printf("the average turn around time is %f\n",atat);
break;
}
case 2:
{
int bt[20],prty[20],wt[20],tat[20];
int n,i,j,pos,temp;
float awt,atat,total=0;
printf("Enter Total Number of Process:");
scanf("%d",&n);
printf("enter all the process \n");
int p[10];
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("enter all the brust time \n");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
printf("enter all the priority time \n");
for(i=0;i<n;i++)
{
scanf("%d",&prty[i]);
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(prty[j]<prty[pos])
pos=j;
}
temp=prty[i];
prty[i]=prty[pos];
prty[pos]=temp;
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
total+=wt[i];
}
awt=total/n;
total=0;
printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\nP[%d]\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
}
atat=total/n;
printf("\n\nthe average waiting time=%f",awt);
printf("\naverage turnaround time=%f\n",atat);
break;
}
case 3:{
int bt[20],wt[20],tat[20],i,j,n,pos,temp;
float awt,atat,total=0;
printf("Enter number of process:");
scanf("%d",&n);
printf("enter all the process \n");
int p[10];
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("\nEnter Burst Time:\n");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(bt[j]<bt[pos])
pos=j;
}
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
total+=wt[i];
}
awt=total/n;
total=0;
printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\np[%d]\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
}
atat=total/n;
printf("\n\nAverage Waiting Time=%f",awt);
printf("\nAverage Turnaround Time=%f\n",atat);
break;
}
case 4:
{
int i,j,n,time,remain,d=0,qt;
int wt=0,tat=0,at[10],bt[10],t[10];
printf("Enter Total Process:\t ");
scanf("%d",&n);
remain=n;
for(i=0;i<n;i++)
{
printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
scanf("%d",&at[i]);
scanf("%d",&bt[i]);
t[i]=bt[i];
}
printf("Enter Time Quantum:\t");
scanf("%d",&qt);
printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
for(time=0,i=0;remain!=0;)
{
if(t[i]<=qt && t[i]>0)
{
time+=t[i];
t[i]=0;
d=1;
}
else if(t[i]>0)
{
t[i]-=qt;
time+=qt;
}
if(t[i]==0 && d==1)
{
remain--;
printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
wt+=time-at[i]-bt[i];
tat+=time-at[i];
d=0;
}
if(i==n-1)
i=0;
else if(at[i+1]<=time)
i++;
else
i=0;
}
printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
printf("Avg Turnaround Time = %f",tat*1.0/n);
break;
}
case 5:
{
int i, time = 0, bt = 0, largest;
char c;
float wait_time = 0, tat = 0, average_wt, average_tat;
printf("\nEnter Total Number of Processes:\t");
scanf("%d", &limit);
for(i = 0, c = 'A'; i < limit; i++, c++)
{
pq[i].pn = c;
printf("\nEnter Details For Process[%C]:\n", pq[i].pn);
printf("Enter Arrival Time:\t");
scanf("%d", &pq[i].at );
printf("Enter Burst Time:\t");
scanf("%d", &pq[i].bt);
printf("Enter Priority:\t");
scanf("%d", &pq[i].priority);
pq[i].s = 0;
bt = bt + pq[i].bt;
}
at_Sorting();
pq[9].priority = -9999;
printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
for(time = pq[0].at; time < bt;)
{
largest = 9;
for(i = 0; i < limit; i++)
{
if(pq[i].at <= time && pq[i].s != 1 && pq[i].priority > pq[largest].priority)
{
largest = i;
}
}
time = time + pq[largest].bt;
pq[largest].ct = time;
pq[largest].wt = pq[largest].ct - pq[largest].at - pq[largest].bt;
pq[largest].tat = pq[largest].ct - pq[largest].at;
pq[largest].s = 1;
wait_time = wait_time + pq[largest].wt;
tat = tat + pq[largest].tat;
printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", pq[largest].pn, pq[largest].at, pq[largest].bt, pq[largest].priority, pq[largest].wt);
}
average_wt = wait_time / limit;
average_tat = tat / limit;
printf("\n\nAverage waiting time:\t%f\n", average_wt);
printf("Average Turnaround Time:\t%f\n", average_tat);
break;}
case 6:
{
int at[10], bt[10], temp[10];
int i, smallest, c = 0, time, n;
double wt = 0, tat = 0, end;
float awt, atat;
printf("\nEnter the Total Number of Processes:\t");
scanf("%d", &n);
printf("\nEnter Details of %d Processes\n", n);
for(i = 0; i < n; i++)
{
printf("\nEnter Arrival Time:\t");
scanf("%d", &at[i]);
printf("Enter Burst Time:\t");
scanf("%d", &bt[i]);
temp[i] = bt[i];
}
bt[9] = 9999;
for(time = 0; c != n; time++)
{
smallest = 9;
for(i = 0; i < n; i++)
{
if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
{
smallest = i;
}
}
bt[smallest]--;
if(bt[smallest] == 0)
{
c++;
end = time + 1;
wt = wt + end - at[smallest] - temp[smallest];
tat = tat + end - at[smallest];
}
}
awt = wt / n;
atat = tat / n;
printf("\n\nAverage Waiting Time:\t%lf\n", awt);
printf("Average Turnaround Time:\t%lf\n", atat);
break;
}
{
default:
printf("invalid choice");
break;
}
}
//printf("to continue press 'Y' or 'y' else any letter to exit\n");
//1
//scanf("%c",&c);
}
while(1);
}

