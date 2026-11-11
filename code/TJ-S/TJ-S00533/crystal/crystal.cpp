#include<bits/stdc++.h>
using namespace std;
long long a[500010],q[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	long long ans=0;
	long long j=n;
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
	}
	for(long long i=n;i>=1;i--)
	{
		for(;j>=1;j--)
		{
			if(a[i]*(i-j+1)-(q[i]-q[j-1])<=m)
			{
				ans=max(ans,i-j+1);
				
			}
			else break; 
		}
	}
	cout<<ans;
	return 0;
}
 
