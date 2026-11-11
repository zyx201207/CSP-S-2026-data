#include<bits/stdc++.h>
using namespace std;
int died[500005],dist[500005],c,n,m,d,q,w[500005],di[21][1000005],zt[21][1000005];
struct node
{
	int v,w,nd;
	bool operator<(node b)const{
		return w>b.w;
	}
};
vector<node>a[500005];
map<pair<int,int>,int>mp;
vector<int>kk2[500005];
void dij(int st,int ed)
{
	memset(dist,0x3f,sizeof dist);
	priority_queue<node>qu;
	for(auto it:kk2[st])
	{
		qu.push({st,w[it],it});
	}
	while(!qu.empty())
	{
		node now=qu.top();
		qu.pop();
		for(auto it:a[now.v])
		{
			if(it.nd!=now.nd)
			{
				if(now.w+mp[{it.nd,now.v}]+mp[{now.nd,now.v}]<dist[it.v])
				{
					dist[it.v]=now.w+mp[{it.nd,now.v}]+mp[{now.nd,now.v}];
					died[it.v]=it.nd;
					qu.push({it.v,dist[it.v],it.nd});
				}
			}
			else
			{
				if(now.w+it.w<dist[it.v])
				{
					dist[it.v]=now.w+it.w;
					died[it.v]=it.nd;
					qu.push({it.v,dist[it.v],it.nd});
				}
			}
		}
	}
//	int ans=INT_MAX;
//	for(auto it:kk2[ed])
//	{
//		ans=min(ans,mp[{it,ed}]);
//	}
//	cout<<dist[ed]<<endl;
//	cout<<ans<<endl;
//	cout<<w[ed]<<endl;
	cout<<dist[ed]+w[ed]+mp[{died[ed],ed}]<<endl;
	return ;	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	cout<<1;
//	cout<<c<<endl<<n<<endl<<m<<endl<<d<<endl<<q<<endl;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	//cout<<1;
	for(int i=1;i<=n;i++)
	{
		int kk;
		cin>>kk;
		for(int j=1;j<=kk;j++)
		{
			cin>>di[i][j]>>zt[i][j];
		}
		//cout<<1;
		for(int j=1;j<=kk;j++)
		{
			for(int k=j+1;k<=kk;k++)
			{
				a[di[i][j]].push_back({di[i][k],zt[i][j],i});
				a[di[i][k]].push_back({di[i][j],zt[i][k],i});
				mp[{i,di[i][j]}]=zt[i][j];
				kk2[di[i][j]].push_back(i);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dij(x,y);
	}
	return 0;
} 
