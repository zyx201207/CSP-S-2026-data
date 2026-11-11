#include<bits/stdc++.h>
using namespace std;

const int MAXPaiNe=5e5+14,MAXN=514,MAXD=20,MAXQ=1e5+14;
const long long inf=1e9+144;
int c,n,m,d,q,t;
struct graph
{
	vector<long long>linj,weigh;
}oliver[MAXPaiNe+514];
long long ent[MAXPaiNe],searched[MAXPaiNe+514],ans[MAXPaiNe+514];
int code=1,tc;
int k[MAXN];

void dijkstra(int root)
{
	for(int i=0;i<MAXPaiNe;i++)
	{
		ans[i]=inf;
		searched[i]=0;
	}
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
	q.push({0,root});
	ans[root]=0;
	while(q.empty()==false)
	{
		long long val=q.top().first,code=q.top().second;
		q.pop();
		if(searched[code]==1) continue;
		searched[code]=1;
		int lenee=oliver[code].linj.size();
		/*for(int i=0;i<=lenee;i++)
		{
			int searching=oliver[code].linj[i];
			long long distan=val+oliver[code].weigh[i];
			if(distan<=ans[searching])
			{
				ans[searching]=distan;
				q.push({ans[searching],searching});
			}
		}*/
	}
}

int main()
{
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{	
		cin>>t;
		ent[i]=t;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int i=1;i<=k[i];i++)
		{
			cin>>t;
			int last_t;
			if(i%2==1)
			{	
				last_t=t;
				oliver[t].linj.push_back(MAXPaiNe+code);
				oliver[MAXPaiNe+code].linj.push_back(t);
			}
			else if(i%2==0)
			{
				oliver[last_t].weigh.push_back(t);
				oliver[MAXPaiNe+code].weigh.push_back(t);
			}
		}
		code++;
	}
	int st,ed;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<oliver[i].linj.size();j++)
		{
			cout<<oliver[i].linj[j]<<' ';
		}
		cout<<endl;
	}
	for(int i=0;i<q;i++)
	{
		cin>>st>>ed;
		dijkstra(st);
		cout<<ans[ed]+ent[st]+ent[ed];
	}
	return 0;
}
