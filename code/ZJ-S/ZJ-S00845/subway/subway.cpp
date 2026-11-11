#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq,k,u,v;
long long x,y;
#define pai pair<long long,int>
priority_queue<pai,vector<pai>,greater<pai>>q;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>qq;
	//i:zhan dian
	//i+n:da ting
	//i+2*n: di tei xian lu
	vector<pair<int,long long> > a[3*n+5];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		a[i].push_back({i+n,x});
		a[i+n].push_back({i,x});
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&u,&v);
			a[u+n].push_back({i+2*n,v});
			a[i+2*n].push_back({u+n,v});
		}
	}
	long long f[n+5][3*n+5];
	for(int o=1;o<=n;o++)
	{
		for(int i=1;i<=3*n;i++)f[o][i]=1e18;
		f[o][o]=0;
		q.push({0,o});
		while(!q.empty())
		{
			long long x=q.top().first;
			int u=q.top().second;
			q.pop();
			if(f[o][u]!=x)continue;
			for(auto it:a[u])
			{
				if(f[o][it.first]>x+it.second)
				{
					f[o][it.first]=x+it.second;
					q.push({f[o][it.first],it.first});
				}
			}
		}	
	}
	while(qq--)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",f[x][y]);
	}
	return 0;
}
