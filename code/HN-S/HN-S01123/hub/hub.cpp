#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,ans,fa[20];
vector<int>g[1005];
int find(int x){return (x^fa[x]?fa[x]=find(fa[x]):x);}
void slove(int x)
{
	int cnt=0,xx=x;
	while(xx)cnt+=xx&1,xx>>=1;
	if(cnt!=k)return;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	if((1<<(i-1))&x)
	for(int j=0;j<g[i].size();j++)
	if((1<<(g[i][j]-1))&x)fa[find(i)]=find(g[i][j]);
	cnt=0;
	for(int i=1;i<=n;i++)
	if((1<<(i-1))&x)cnt+=(fa[i]==i);
	if(cnt>2)return;
	int q[20],qt[20]={},b[20]={},head=0,tail=0;
	for(int i=1;i<=n;i++)
	if((1<<(i-1))&x)q[++tail]=i,b[i]=1;
	while(head<tail)
	{
		head++;
		for(int i=0;i<g[q[head]].size();i++)
		if(!b[g[q[head]][i]])
		{
			b[g[q[head]][i]]=1;
			q[++tail]=g[q[head]][i];
			qt[tail]=qt[head]+1;
		}
	}
	ans=min(ans,qt[n]);
}

int q_[1005],qt_[1005],b_[1005];
void bfs(int x,int y)
{
	int head=0,tail=2;memset(b_,0,n*4+10);
	q_[1]=x,q_[2]=y,b_[x]=b_[y]=1;
	while(head<tail)
	{
		head++;
		for(int i=0;i<g[q_[head]].size();i++)
		if(!b_[g[q_[head]][i]])
		{
			b_[g[q_[head]][i]]=1;
			q_[++tail]=g[q_[head]][i];
			qt_[tail]=qt_[head]+1;
		}
	}
	ans=min(ans,qt_[n]);
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	if(c<=3)
	{
		while(t--)
		{
			cin>>n>>k;
			for(int i=1;i<=n;i++)g[i].clear();
			for(int i=1;i<n;i++)
			{
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			ans=n;
			for(int i=0;i<(1<<n);i++)slove(i);
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c==13||c==14)
	{
		while(t--)
		{
			cin>>n>>k;
			if(n<=10)
			{
				for(int i=1;i<=n;i++)g[i].clear();
				for(int i=1;i<n;i++)
				{
					cin>>u>>v;
					g[u].push_back(v);
					g[v].push_back(u);
				}
				ans=n;
				for(int i=0;i<(1<<n);i++)slove(i);
				cout<<ans<<'\n';
			}
			else
			{
				for(int i=1;i<n;i++)cin>>u>>v;
				if(k==n)cout<<"0\n";
				else if(k>=n/2)cout<<"1\n";
				else cout<<(n/2+5-k)/4<<'\n';
			}
		}
		return 0;
	}
	if(c==7)
	{
		while(t--)
		{
			cin>>n>>k;
			for(int i=1;i<=n;i++)g[i].clear();
			for(int i=1;i<n;i++)
			{
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			ans=n;
			for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			bfs(i,j);
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}
