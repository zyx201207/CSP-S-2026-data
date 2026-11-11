#include <iostream>
using namespace std;
int m,n,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int k=0,av=0,ma=-10000; 
	for(int i=n;i>=1;i--)
	{
		k=a[i]; 
		av=m;
		int sum=0;

		for(int j=i;j>=1;j--) 
		{
		    int f=k-a[j];
			av=av-f;
			if(av>=0)
			{
				sum++;
			}
			else
			{
				break;
			}
			
		}

	
		if(sum>ma)
		{
			ma=sum;
		}
	
			
	} 
	cout<<ma;
	return 0; 
}
