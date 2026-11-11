#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int s;
	int a[500000];
	int sum=0;
	int num=0;
	int yum=0;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=a[i];
		if(a[i-1]<sum)
		{
			if((s+a[i-1]-sum)>=0)
			{
		        s-=a[i];	
		        yum++;
		    }
		}
	}
	yum++;
	cout<<yum;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	return 0;
}
