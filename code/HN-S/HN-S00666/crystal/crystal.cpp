#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m; 
int a[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]*(j-i+1)-(sum[j]-sum[i-1])<=m)
				{
					if(j-i+1>ans)
						ans=j-i+1;
				}
			}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[mid]*(mid-i+1)-(sum[mid]-sum[i-1])<=m)
					l=mid+1;
				else
					r=mid-1;	
			} 
			ans=max(ans,r-i+1);
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
2 2 4 8 9
4 4 8 9
16 9

5 8
-3 -1 2 2 7

5 4
1 9 10 11 11
*/
