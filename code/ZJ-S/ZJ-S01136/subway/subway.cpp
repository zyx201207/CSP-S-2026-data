#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y,gu,sh,dis[500005],w[500005],k[500005];
bool vis[500005];
vector<int>a[500005],b[505],t[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>gu>>sh;
			a[gu].push_back(i);
			b[i].push_back(gu);
			t[gu].push_back(sh);
		}
		for(int j=1;j<=m;j++) if(t[j].size()<i) t[j].push_back(-1);
	}
	while(q--)
	{
		cin>>x>>y;
		memset(vis,0,sizeof vis);
		priority_queue< pair<int,int> ,vector< pair<int,int> >,greater< pair<int,int> > >que;
		que.push(make_pair(0,x));
		vis[x]=1;
		while(!que.empty())
		{
			int t1=que.top().first;
			int t2=que.top().second;
			que.pop();
			if(t2==y)
			{
				cout<<t1+w[x]+w[y]<<endl;
				break;
			}
			for(int i=0;i<a[t2].size();i++)
				for(int j=0;j<b[a[t2][i]].size();j++) 
				{
					int f=b[a[t2][i]][j];
					if(!vis[f])
					{
						vis[f]=1;
						que.push(make_pair(t1+t[t2][a[t2][i]-1]+t[f][a[t2][i]-1],f));	
					}
				}
		}
	}
}
