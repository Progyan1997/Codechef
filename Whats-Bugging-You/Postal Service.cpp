// Link: https://www.codechef.com/WBY2016/problems/WBUP104

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXLEN 500
 
int compare(const void * a, const void * b)
{
	return *((int *)a) - *((int *)b);
}
 
int find(int key, int* ar, int sz){
    int a=0, b=sz-1;
    while(a<=b){
        int m = (a+b)/2;
        if(key == ar[m])
            return m;
        if(key>ar[m])
            a=m+1;
        else
            b=m;
    }
    assert(false);
    return -1;
}
 
void bubbleSort(int newPositions[MAXLEN], int switches[MAXLEN], int n)
{
	int temp;
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if (newPositions[j] < newPositions[j-1])
			{
				temp = newPositions[j];
				newPositions[j] = newPositions[j-1];
				newPositions[j-1] = temp;
				switches[j]++;
				switches[j-1]++;
			}
		}
	}
}
 
int main()
{
	int t;
	int n;
	int positions[MAXLEN];
	int directions[MAXLEN];
	int q;
	int postman;
	int time;
	int newPositions[MAXLEN];
	int switches[MAXLEN];
	
	int sorted_final[MAXLEN];
	int rev_count;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &positions[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &directions[i]);
			
		scanf("%d", &q);
		for(int i = 0; i < q; i++)
		{
			rev_count = 0;
			scanf("%d %d", &postman, &time);
			for(int j = 0; j < n; j++)
			{
				if (directions[j])
					newPositions[j] = positions[j]+time;
				else
					newPositions[j] = positions[j]-time;
				switches[j] = 0;
				sorted_final[j] = newPositions[j];
			}
			//bubbleSort(newPositions, switches, n);
			qsort(newPositions, n, sizeof(newPositions[0]), compare);
			for(int i=0; i<n; i++){
				if(sorted_final[i]==newPositions[postman]){
					rev_count++;
					continue;
				}
				int rank = find(sorted_final[i], newPositions, n);
				if((postman-i)*(postman-rank)<=0)
					rev_count++;
			}
			
			//printf("%d %d\n", newPositions[postman], switches[postman]);	
			printf("%d %d\n", newPositions[postman], --rev_count);	
		}
		
	}
	return 0;
}
