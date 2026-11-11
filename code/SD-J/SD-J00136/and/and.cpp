#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
int a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		int k=a[1];
		for(int i=2;i<=n;i++) k=(k&a[i]);
		cout<<k;
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=5)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				int k;
				if(i==1)
				{
					if(j==2) k=a[3];
					else k=a[2];
				}
				else k=a[1];
				for(int m=1;m<=n;m++)
				{
					if(m==i||m==j) continue;
					k=k&a[m];
				}
				ans=max(ans,k);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		int ans=a[1];
		for(int i=3;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=a[n-m+1];
	for(int i=n-m+2;i<=n;i++) ans=ans&a[i];
	cout<<ans;
	return 0;
} 
