#include <stdio.h>
#define get getchar_unlocked

inline int scan_d(void){
	int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

int main(void) {
	int t,n,i;
	unsigned long long a,b,c;
	char ch;
	t=scan_d();
	while(t--)
	{
	    a=0;
	    b=1;
	    n=scan_d();
	    for(i=0;i<n;i++)
	    {
	        c = b;
	        ch = c%26;
	        if(!ch) ch=26;
	        printf("%c",ch+'A'-1);
	        c = a+b;
	        a = b;
	        b = c;
	    }
	    printf("\n");
	}
	return 0;
}
