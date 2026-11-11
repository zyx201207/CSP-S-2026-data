#include<bits/stdc++.h> 
#define int long long
using namespace std;
int a[1000010];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt,maxn1=0,maxn2=0,maxn3=0;
	cin>>n>>m;
	cin>>a[1];
	cnt=a[1];
	maxn2=max(maxn2,a[1]);
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		maxn2=max(maxn2,a[i]);
		cnt=a[i]&cnt;
	} 
	if(m==1)
	{
		cout<<maxn2;
	}
	if(m==n)
	{
		cout<<cnt;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn1=max(maxn1,cnt|a[i]);
		}
		cout<<maxn1;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn3=max(maxn3,a[i]&a[j]);
			}
		}
		cout<<maxn3;
	}
	return 0; 
}
