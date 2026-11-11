#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
struct tok
{
	int nex,v;
};
const int maxn=505;
const int maxm=500005;
int w[maxm];
int c,n,m,d,q;
int sp[maxm];
vector<tok>have[maxn];
vector<tok>to[maxm];
queue<int>spfa;
vector<int>ans;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		int k,u1,u2;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>u1>>u2;
			have[i].push_back((tok){u1,u2});
			to[u1].push_back((tok){i,u2});
		}
	}
	for(int o=1;o<=q;o++)
	{
		while(!spfa.empty())
		{
			spfa.pop();
		}
		for(int j=0;j<=maxm;j++)
		{
			sp[j]=1e18;
		}
		int x,y;
		cin>>x>>y;
		sp[x]=0;
		spfa.push(x);
		while(!spfa.empty())
		{
			int u4=spfa.front();
			spfa.pop();
			for(int i=0;i<to[u4].size();i++)
			{
				for(int j=0;j<have[to[u4][i].nex].size();j++)
				{
					if(i==have[to[u4][i].nex][j].nex)
					{
						continue;
					}
					if(sp[have[to[u4][i].nex][j].nex]>to[u4][i].v+have[to[u4][i].nex][j].v+sp[u4])
				    {
					    sp[have[to[u4][i].nex][j].nex]=to[u4][i].v+have[to[u4][i].nex][j].v+sp[u4];
					    spfa.push(have[to[u4][i].nex][j].nex);
				    }
				}
				
			}
		}
		ans.push_back(sp[y]+w[x]+w[y]);
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}
