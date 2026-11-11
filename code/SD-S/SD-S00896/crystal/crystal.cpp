#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
long long n,m;
long long a[666666];
long long f[666666];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	long long k=0;
	long long l=1,r=n;
	int tot=0;
	while(l<r&&tot<=70)
	{
		tot++;
		k=l+(r-l)/2;
		bool u=0;
		for(int i=1;i+k<=n;i++)
		{
			int h=k+i-1;
			long long t=f[h]-f[i]-(i-1)*(a[h]-a[i]);
			if(t<=m)
			{
				u=1;
			}
		}
		if(u==1)
		{
			l=k;
		}
		else r=k-1;
	}
	cout<<l;
	return 0;
 }
