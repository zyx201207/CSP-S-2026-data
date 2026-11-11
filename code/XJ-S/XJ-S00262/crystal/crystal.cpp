#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]+i==a[i+1])
		{
			ans=m-i;
			sum=sum+1;
			if(ans/2+a[i+1]==a[i+2])
			{
				sum++;
			}
		}
		if(a[i]==a[i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;	
}
