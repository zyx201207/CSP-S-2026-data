#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
struct Node{
	vector<int> l;//经过该站的线路
	int t[505]; //到t[i]站台的时间 
}st[M];
int w[M];
void solve(int u,int v)
{
	for(int x=0;x<st[u].l.size();x++)
	{
		for(int y=0;y<st[v].l.size();y++)
		{
			if(st[u].l[x]==st[u].l[y])
			{
				int line=st[u].l[x];
				int ans=w[u]+st[u].t[line]+st[v].t[line]+w[v];
				cout<<ans<<'\n';
				return; 
			}
		}
	}
	int ans=w[u]+st[u].t[0]+st[v].t[1]+w[v];
	for(int i=u;i<=v;i++)
	{
		ans+=st[i].t[st[i].l[0]]+st[i].t[st[i].l[1]];
	}
	cout<<ans<<'\n';
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int j=1;j<=m;j++)
	{
		cin>>w[j];
	}
	for(int j=1;j<=n;j++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int p,q;
		    cin>>p>>q;
			st[p].l.push_back(j);
			st[p].t[j]=q;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		solve(u,v);
	}
	return 0;
}

