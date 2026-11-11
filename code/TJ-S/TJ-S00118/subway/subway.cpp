#include<bits/stdc++.h>
using namespace std;
bool b[200005];
vector<int> a[200005];
int dis[200005];
void bfs(int x,int y)
{
	queue<int> c;
	b[x]=1;
    c.push(x);
    int lon=1;
	while(!c.empty())
	{
		int u=c.front();
		c.pop();
		for(int i=0;i<a[u].size();i++)
    	{
	    	if(b[a[u][i]]==0)
	    	{
	    		if(dis[a[u][i]]==0)
	    		{
	    			dis[a[u][i]]=lon;
				}
	    		c.push(a[u][i]);
	    	}
	    }
	    lon++;
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c1,n,m,d,q;
    cin>>c1>>n>>m>>d>>q;
    long long w[500005];
    for(int i=1;i<=m;i++)
    {
    	cin>>w[i];
	}
	int x,t;
	vector<int> line[500][1];
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		int o,e;
		cin>>o;
		line[i][0].push_back(o);
		cin>>t;
		line[i][1].push_back(t);
		for(int j=2;j<=x;j++)
		{
			cin>>e>>t;
			a[o].push_back(e);
			a[e].push_back(o);
			line[i][0].push_back(e);
			line[i][1].push_back(t);
		}
	}
	int start,end;
	for(int i=1;i<=q;i++)
	{
		long long s=0;
		cin>>start>>end;
		s+=w[start];
		s+=w[end];
		bfs(start,end);
		cout<<dis[end]*t<<endl;
		memset(dis,0,sizeof(n));
		memset(b,0,sizeof(n));
	}
}
