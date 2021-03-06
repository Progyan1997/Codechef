#include <stdio.h>
#define get getchar_unlocked

int arr[1000002]={1,1};

inline int scan_d(void){
	int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

void setPrime()
{
    int i,j;
    for(i=0;i<=1000000;i++)
    {
        if(arr[i]==0)
        for(j=2;(i*j)<=1000000;j++)
        arr[i*j]=1;
    }
}

int main(void) {
	int t,a,b;
	setPrime();
	t=scan_d();
	while(t--)
	{
	    int count=0;
	    a=scan_d();
	    b=scan_d();
	    while(a<=b)
	    {
	        if(arr[a]==0)
	            count++;
            a++;
	    }
	    printf("%d\n",count);
	}
	return 0;
}
