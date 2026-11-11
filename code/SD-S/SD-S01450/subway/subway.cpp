#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int N=505,M=5e5+10;
vector<pair<int,int> >vec[M];
int w[M];
int a[M],t[M],dis[M];
priority_queue<pair<int,int> >qq;
const int MAX=1e18;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=11)
	{
		for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++) scanf("%lld%lld",&a[j],&t[j]);
			for(int l=1;l<k;l++)
			{
				for(int r=l+1;r<=k;r++)
				{
					vec[a[l]].push_back({a[r],t[l]+t[r]});
					vec[a[r]].push_back({a[l],t[l]+t[r]});
				}
			}
			for(int j=1;j<=k;j++) a[j]=0,t[j]=0;
		}
		while(q--)
		{
			int u,v;
			scanf("%lld%lld",&u,&v);
			for(int i=1;i<=m;i++) dis[i]=MAX;
			dis[u]=0;
			qq.push({0,u});
			while(!qq.empty())
			{
				int x=-qq.top().first,y=qq.top().second;
				qq.pop();
				if(x>dis[y]) continue;
				dis[y]=x;
				int len=vec[y].size();
				for(int i=0;i<len;i++)
				{
					int now1=vec[y][i].second,now2=vec[y][i].first;
					if(now1+dis[y]<dis[now2])
					{
						dis[now2]=now1+dis[y];
						qq.push({-dis[now2],now2});
					}
				}
			}
			printf("%lld\n",dis[v]+w[u]+w[v]);
		//cout<<dis[v]+w[u]+w[v]<<endl;
		}
		return 0;
	}
	return 0;
}

