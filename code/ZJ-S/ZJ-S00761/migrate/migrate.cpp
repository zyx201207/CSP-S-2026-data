#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int vis[N],a[N],d[N],cnt[N],id,T,n,m,pre[N],nxt[N];
vector<int>e[N];
void bfs(int st)
{
	queue<int>p,q;
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	p.push(0);
	q.push(st);
	cnt[st]=1;
	while(!q.empty())
	{
		int u=q.front(),pc=p.front();
		q.pop();
		p.pop();
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i];
			if(!(vis[v]&&pc==d[v]))
			{
				cnt[v]+=cnt[u];
				if(!vis[v])
				{
					d[v]=pc+1;
					vis[v]=1;
					q.push(v);
					p.push(pc+1);	
				}
			}
		}
	}
}
void wcypc()
{
	int d=a[2]-a[1];
	m/=d;
	if(m<=1)
		cout<<"0\n";
	else if(m>=2)
		cout<<max(n-(2*m-1),0ll)<<"\n";
}
void wcypc1()
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=upper_bound(a+1,a+1+n,a[i]-m)-a-1;
		nxt[i]=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
	}
	int t=upper_bound(a+1,a+1+n,a[1]+m)-a,ans=0;
	for(int i=1;i<t;i++)
	{
		int l=a[nxt[i]-2]+m+1,r=a[nxt[i]-1]+m;
		ans+=upper_bound(a+1,a+1+n,r)-lower_bound(a+1,a+1+n,l);
	}
	cout<<ans;
}
signed main()
{
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)	cin>>a[i];
		if(id==11||id==12)
		{
			wcypc();
			continue;
		}
		else if(id==13||id==14)
		{
			wcypc1();
			continue;
		}
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=m)
				e[i].push_back(j);
			else
				break;
		}
		int ans=0;
		for(int i=1;i<n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
				if(cnt[j]==2)
					ans++;
		}
		for(int i=1;i<=n;i++)
			e[i].clear();
		cout<<ans<<"\n";
	}
	return 0;
}
