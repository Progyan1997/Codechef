// Link: https://www.codechef.com/WBY2016/problems/WBUP101

#include <iostream>
using namespace std;
int main() {
	int T,a,b;
	cin>>T;
	for(int i=0;i<T;++i)
	{
		cin>>a;
		cin>>b;
		int r,c;
		c=a*b;
		while (a!=b)
		{
			if(a>b)
				{
				a-=b;
				}
			else
			{
				b-=a;
			}
			
		}
		cout<<a<<" "<<(c/a)<<endl;
	}
	return 0;
}
