#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d;
int a[N],dis[15][15];
void dfs(int x,int pos)
{
	if(pos==n) return;
	for(int i=pos+1;i<=n;i++)
	{
		if(a[i]-a[pos]<=d) 
		{
			dis[pos][i]++;
			dfs(x+1,i);
		}
	}
}
void work()
{
	if(c==11||c==12)
	{
		int t=d/(a[2]-a[1]);
		if(t==0||t==1) {cout<<0<<"\n";return;}
		else
		{
			if(2*t-1>n) {cout<<0<<"\n";return;}
			else cout<<n-2*t+1<<"\n";
			return;
		}
	}
	else if(c==1||c==2)
	{
		memset(dis,0,sizeof(dis));
		dfs(1,1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dis[i][j]==2)
					ans++;
				cout<<dis[i][j]<<" ";
			}
			cout<<"\n";	
		}
		cout<<ans<<"\n";
	}
	else
		cout<<0<<"\n";
}
signed main(void)
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		work();
	}
}
