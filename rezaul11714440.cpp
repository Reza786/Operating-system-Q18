//Name : Rezaul Islam , Reg no: 11714440, Roll No :18, Question no: 18;
#include<iostream>
#include<stdio.h> 
#include<conio.h>
void findWaitingTime(int processes[], int n, 
             int bt[], int wt[], int quantum) 
{ 

    int rem_bt[n]; 
    for (int i = 0 ; i < n ; i++) 
        rem_bt[i] =  bt[i]; 
  
    int t = 0; 
    while (1) 
    { 
        bool done = true;
        for (int i = 0 ; i < n; i++) 
        { 
            if (rem_bt[i] > 0) 
            { 
                done = false; 
  
                if (rem_bt[i] > quantum) 
                {
                    t += quantum;
                    rem_bt[i] -= quantum; 
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i]; 
                    rem_bt[i] = 0; 
                } 
            } 
        } 
        if (done == true) 
          break; 
    } 
} 

void findTurnAroundTime(int processes[], int n, 
                        int bt[], int wt[], int tat[]) 
{ 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

void findavgTime(int processes[], int n, int bt[], 
                                     int quantum) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat); 
    printf( "Processes   Burst time  Waiting time   Turn around time\n"); 
    for (int i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf( " ");printf("%d", i+1 );printf("\t\t"); printf("%d",bt[i]); printf("\t ");
        printf("%d",wt[i]);
        printf("\t\t");
        printf("%d",tat[i]);
        printf("\n");
        
    } 
    printf("Total waiting time = ");
    printf("%d",total_wt); 
    printf("\nTotal turn around time = ");
    printf("%d",total_tat); ; 
    printf( "\nAverage waiting time = ");
    printf("%f", total_wt /n); 
    printf("\nAverage turn around time = ");
    printf("%f",total_tat /n); 
} 
int main() 
{    
     int a,i;
    printf("Enter how many process:");
    scanf("%d",a);
     int processes[a];
     int burst_time[a];
   
    printf("Enter : \n");
    for(i=0;i<a;i++)
    {
    	scanf("%d",processes[i]);
	}
    
    int n = sizeof processes / sizeof processes[0]; 
    printf("Enter brust time :\n");
    for(i=0;i<a;i++)
    {
    	scanf("%d",burst_time[i]);
	}
   
    int quantum;
    printf("Enter time quantum:\n");
    scanf("%d",quantum);
    findavgTime(processes, n, burst_time, quantum); 
    return 0; 
} 
