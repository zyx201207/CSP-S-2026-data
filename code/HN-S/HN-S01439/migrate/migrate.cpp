#include<bits/stdc++.h>
#include<cstdio>
using namespace std; 
#define ll long long
const int N=1e6+10;
ll n,m,t;
ll z[N],d[N];
ll sum,ans;
void bfs(ll a,ll b,ll res)
{
	if(b==n)
	{
		if(res==a)
		{
			sum++;
		}
		else if(a<res)
		{
			res=a;
			sum=1;
		}
	}
	for(int i=b+1;i<=n;i++)
	{
		if(z[i]-z[b]<=m)
		{
			bfs(a+1,i,res);
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>z[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(z[i]-z[i-1]>m)
		{
			cout<<"0"<<endl;
			return ;
		}
	}
	sum=n;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		bfs(0,i,n);
		if(sum==2)ans++;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll c;
	cin>>c;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
