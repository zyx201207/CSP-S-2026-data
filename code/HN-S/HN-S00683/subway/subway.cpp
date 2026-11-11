#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define I using
#define AK namespace
#define IOI std;
I AK IOI
int C,n,m,d,q,st,en,mm[500005],ans[500005];
struct jt
{
	int v,len;
};
vector<jt>b[1000005];
void bfs()
{
	int mi=1e18;
	memset(ans,0x3f,sizeof(ans));
	queue<jt>q;
	q.push({st,0});
	ans[st]=0;
	while(q.size())
	{
		jt p=q.front();
		q.pop();
		if(p.v==en)mi=min(p.len+mm[st]+mm[en],mi);
		for(jt i:b[p.v])
		{
			if(ans[p.v]+i.len<ans[i.v])
			{
				ans[i.v]=ans[p.v]+i.len;
				q.push({i.v,ans[i.v]});
			}
		}
	}
	cout<<mi<<endl;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>mm[i];
	for(int i=1;i<=n;i++)
	{
		int k,lx,x,y;
		cin>>k;
		cin>>lx>>y;
		b[lx+m].push_back({lx,y});
		b[lx].push_back({lx+m,y});
		for(int j=2;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			b[lx+m].push_back({x,y});
			b[x].push_back({lx+m,y});
		}
	}
	while(q--)
	{
		cin>>st>>en;
		bfs();
	}
	return 0;
}

