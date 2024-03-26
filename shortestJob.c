#include<stdio.h>


void main(){
	
	int num_process;
	printf("Enter the number of processes:");
	scanf("%d",&num_process);
	
	int process[num_process];
	
	printf("Start entering the processes..\n");
	for(int i=0;i<num_process;i++){
		scanf("%d",&process[i]);	
	
	}
	
	//Burst times
	
	int burstTime[num_process];
	printf("Enter the burst times of each processes.\n");
	for(int i=0;i<num_process;i++){
		scanf("%d",&burstTime[i]);
	}
	
	//Sorting the burst times in ascending..
	int sortedBT[num_process];
	for(int i=0;i<num_process;i++){
		sortedBT[i]=burstTime[i];
	}
	for(int i=0;i<num_process;i++){
		for(int j=0;j<num_process-i-1;j++){
			if(sortedBT[j] > sortedBT[j+1]){
				int temp = sortedBT[j];
				sortedBT[j] = sortedBT[j+1];
				sortedBT[j+1] = temp;
			}
		}
	}
	
	int wt[num_process];
	wt[0]=0;
	for(int i=1;i<num_process;i++){
		wt[i] = sortedBT[i-1] + wt[i-1];
	}
	float tat=0;
	float twt=0;
	
	for(int i=0;i<num_process;i++){
		tat=tat+wt[i];		
		twt=twt+(wt[i]+sortedBT[i]);
	}
	printf("Process ID\t Burst Time\t Waiting Time\n");
	for(int i=0;i<num_process;i++){
		
		printf("\t%d\t \t%d\t \t%d\n",process[i],burstTime[i],wt[i]);
	
	}
	
	//Average
	float awt = twt/num_process;
	float atat = tat/num_process;
	
	//Printing the results
	
	printf("The average waiting time is: %f\n",awt);
	printf("The average Turn Around Time is: %f\n",atat);

}
