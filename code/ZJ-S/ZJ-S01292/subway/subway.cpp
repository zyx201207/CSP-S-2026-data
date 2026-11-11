#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y;
};
int c,n,m,d,q,w[500005],a[500005],t[500005],vis[500005];
vector<node> v[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>a[i]>>t[i];
//			if(i>=2)
//			{
//				v[a[i-1]].push_back({a[i],t[i-1]+t[i]});
//				v[a[i]].push_back({a[i-1],t[i-1]+t[i]});
//			}
		}
		for(int i=1;i<k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				v[a[i]].push_back({a[j],t[i]+t[j]});
				v[a[j]].push_back({a[i],t[j]+t[i]});
			}
		}
	}
//	for(int i=0;i<v[3].size();i++)
//	{
//		cout<<v[3][i].x<<" "<<v[3][i].y<<endl;
//	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		int start,end;
		cin>>start>>end;
		queue<node> q;
		q.push({start,w[start]});
		while(!q.empty())
		{
			int x=q.front().x,y=q.front().y;
			q.pop();
			for(int i=0;i<v[x].size();i++)
			{
				if(vis[v[x][i].x]==0 or y+v[x][i].y<vis[v[x][i].x])
				{
//					cout<<v[x][i].x<<" "<<y+v[x][i].y<<endl;
					vis[v[x][i].x]=y+v[x][i].y;
					q.push({v[x][i].x,y+v[x][i].y});
					
				}
			}
		}
		cout<<vis[end]+w[end]<<endl;
	}
	return 0;
}