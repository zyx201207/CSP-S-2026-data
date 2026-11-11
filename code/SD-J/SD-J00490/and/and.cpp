#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],e[200010][50],vis[200010],last[200010],ans=0,maxn=0;
int main()
{
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ll now=0;
		cin>>a[i];
		while(a[i])
		{
			e[i][now++]=a[i]%2;
//			cout<<a[i]<<" "<<now<<endl;
			a[i]/=2;
		}
		maxn=max(maxn,now-1);
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=maxn;j++)
//		{
//			cout<<e[i][j];
//		}
//		cout<<endl;
//	}
	for(int i=maxn;i>=0;i--)
	{
		ll cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(e[j][i]==0)
			{
				vis[j]=1;
			}
			if(e[j][i]==1&&vis[j]==0)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				vis[j]=last[j];
			}
		}
		for(int j=1;j<=n;j++)
		{
			last[j]=vis[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}

