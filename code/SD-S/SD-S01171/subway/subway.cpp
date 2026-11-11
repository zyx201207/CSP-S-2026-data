#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int c,n,m,d,q;
const int N=5e5+10;
map<int,int> x[505];
map<int,ll> v[505];
map<int,int> kkk[505];
ll w[N];
int k[505];
vector<int> g[N];
map<int,bool> mp[N],mp2[N];
//struct node
//{
//	ll ww;
//	int y;
//	int xianlu;
////	bool operator<(const node& jj,const node& kk)  const
////	{
////		return jj.ww<kk.ww;
////	}
//};
ll find(int st,int ed)
{
	for(int i=1;i<=n;i++)
		for(auto x:mp[i])
			mp[i][x.first]=0;
	priority_queue<array<ll,3>,vector<array<ll,3> > ,greater<array<ll,3> > >pq;
	for(int now:g[st])
	{
		pq.push({v[now][st],now,st});
	}
	while(!pq.empty())
	{
		ll ww=pq.top()[0];
		ll xianlu=pq.top()[1];
		ll y=pq.top()[2];
		pq.pop();
		if(mp[xianlu][y]) continue;
		mp[xianlu][y]=1;
		if(y==ed) 
		{
			return ww+v[xianlu][y];
		}
		if(x[xianlu][y]-1>0)
		{
			ll pre=kkk[xianlu][x[xianlu][y]-1];
			if(mp[xianlu][pre]==0)
			{
			pq.push({ww,xianlu,pre});
			}
			
		}
		if(x[xianlu][y]+1<=k[xianlu])
		{
			ll nxt=kkk[xianlu][x[xianlu][y]+1];
			if(mp[xianlu][nxt]==0)
			{
				pq.push({ww,xianlu,nxt});
			}
			
		}
		for(int o:g[y])
		{
			if(o!=xianlu)
			{
				pq.push({ww+v[xianlu][y]+v[xianlu][o],o,y});
			}
		}
		
	}
	return -1;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int val;
			cin>>val;
			x[i][val]=j;
			kkk[i][j]=val;
			mp2[val][i]=1;
			ll z;
			cin>>z;
			v[i][val]=z;
			g[val].push_back(i);
		}
	}
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		cout<<find(st,ed)+w[st]+w[ed]<<"\n";
	}
	return 0;
}
/*
	0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 */
