#include<bits/stdc++.h>
using namespace std;

struct cmpp
{
	long long z;
	long long t;
};

struct cmppp
{
	long long z11;

	long long t11;
};

long long c,n,m,d,q;
long long zhan[20007];
vector<cmpp> a[507];
vector<cmpp> tai[57];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>zhan[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long x=0;
		cin>>x;
		for(long long j=1;j<=x;j++)
		{
			cmpp e;
			cin>>e.z>>e.t;
			a[i].push_back(e);
			tai[e.z].push_back({i,e.t});
		}
	}
	for(long long i=1;i<=q;i++)
	{
		long long x,y,ans=0,ans1=0;
		long long vis[57];
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		queue<cmppp> q1;
		q1.push({x,0});
		while(q1.size()!=0)
		{
			
			cmppp w=q1.front();
			q1.pop();
			long long x_z=w.z11;
		
			long long x_t=w.t11;
			vis[x_z]=1;
			if(x_z==y)
			{
				ans=x_t;
				break;
				
			}
			for(cmpp v:tai[x_z])
			{
				for(cmpp j:a[v.z])
				{
					if(vis[j.z]!=1)
					{
						int y_t=x_t+v.t+j.t;
						q1.push({j.z,y_t});
					
					}
					
					
				}
			}
		}
		cout<<ans+zhan[x]+zhan[y]<<endl;
	}
	return 0;
}
