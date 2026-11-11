#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
int n,d,a[N],minn[N],tot[N];//minn:最短路；tot：数量 
vector<int> g[N];
void bfs(int x)
{
	memset(minn,0x3f,sizeof(minn));
	memset(tot,0,sizeof(tot));
	queue<int> q;
	q.push(x);
	minn[x]=0; tot[x]=1;
	while(q.size())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(minn[v]>minn[u]+1)
			{
				minn[v]=minn[u]+1;
				tot[v]=1;
				q.push(v);
			}
			else if(minn[v]==minn[u]+1) tot[v]++;
		}
	}
	
}
void calc()
{
	cin>>n>>d;
	bool flag1=true;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cha=a[2]-a[1];
	for(int i=1;i<=n-1;i++)
	{
		if(a[i+1]-a[i]!=cha)
		{
			flag1=false;
			break;
		}
	}
	if(flag1)
	{
		int step=d/cha;
		if(step<=1)
		{
			cout<<"0"<<endl;
			return;
		}
		int t=step*2-1;
		if(t+1>n)
		{
			cout<<0<<endl;
			return;
		}
		cout<<n-t<<endl;
		return;
	}
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d) g[i].push_back(j);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=i+1;j<=n;j++)
		{
			if(tot[j]==2)
			{
				ans++;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		calc();
	}
	return 0;
}
