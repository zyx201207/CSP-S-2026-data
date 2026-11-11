#include<bits/stdc++.h>
using namespace std;
#define int long long
//void dij(int p)
//{
//	priority_queue<int>Q;
//	Q.push(p);
//	
//	for(int i=1;i<=n;i++)
//	{
//		
//	}
//	while(Q.size())
//	{
//		int x=Q.top();
//		Q.pop();
//		if(vis[x])
//		{
//			continue;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for()
//		}
//	}
//}
int ans;
int a[500002],sum[500002],n,m;
int ef(int s)//s´Ó0~n-1 
{
	int l=0,r=n-s+1;
//	cout<<'*'<<r;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(a[mid+s]*(mid-1)-(sum[mid+s-1]-sum[s])<=m)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
//	cout<<'|'<<l+s<<' '<<l-1<<' '<<l+s-1<<' '<<s<<'|'<<'\n';//<<a[l+s]*(l-1)-(sum[l+s-1]-sum[s]);
	return l;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	a[n+1]=2e12;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=0;i<n;i++)
	{
		int f=ef(i);
//		cout<<f<<' ';
		ans=max(ans,f);
	}
//	cout<<a[5]*1-(sum[4]-sum[3]);
	cout<<ans;
	return 0;
}
