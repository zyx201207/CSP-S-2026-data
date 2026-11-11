#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
int bian,n,m,d,q,a,b,l;
long long x,y;
vector<vector<long long>> ans;
vector<vector<pair<int,long long>>> v;
vector<long long> dis;
vector<int> jin;
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> p;
void dij(int from)
{
	dis[from]=0;
	jin[from]=1;
	p.push(make_pair(0,from));
	while(!p.empty())
	{
		int f=p.top().second;
		p.pop();
		ans[from][f]=dis[f];
		ans[f][from]=dis[f];
		for(auto i:v[f])
		{
			if(dis[i.first]>dis[f]+i.second)
			{
				dis[i.first]=dis[f]+i.second;
				if(!jin[i.first])
				{
					p.push(make_pair(dis[i.first],i.first));
					jin[i.first]=1;
				}
			}
		}
	}
	for(int i=0;i<2*m+n;i++)
	{
		dis[i]=1e18;
		jin[i]=0;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>bian>>n>>m>>d>>q;
	v.resize(2*m+n);
	ans.resize(2*m+n,vector<long long>(2*m+n,1e18));
	for(int i=0;i<m;i++)
	{
		cin>>x;
		v[2*i].push_back(make_pair(2*i+1,x));
		v[2*i+1].push_back(make_pair(2*i,x));
	}
	for(int i=0;i<n;i++)
	{
		cin>>l;
		for(int j=0;j<l;j++)
		{
			cin>>x>>y;
			v[2*x-1].push_back(make_pair(2*m+i,y));
			v[2*m+i].push_back(make_pair(2*x-1,y));
		}
	}
	dis.resize(2*m+n,1e18);
	jin.resize(2*m+n,0);
	while(q--)
	{
		cin>>a>>b;
		if(ans[2*(a-1)][2*(b-1)]>5e17) dij(2*(a-1));
		cout<<ans[2*(a-1)][2*(b-1)]<<'\n';
	}
	return 0;
}
