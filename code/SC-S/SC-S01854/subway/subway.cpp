#include<bits/stdc++.h>
using namespace std;
long long n,m,i,a,x,y,c,q,d,t,k[520],j,s=0,w[500020];
struct tt
{
	long long a,b;
};
vector<tt>v[500020];
priority_queue<long long>o;
unordered_map<long long,long long>p;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			v[i+m].push_back({a,t});
			v[a].push_back({i+m,t});
		}
	}
	for(i=1;i<=q;i++)
	{
		for(j=1;j<=m+n;j++)p[j]=INT_MAX;
		cin>>x>>y;
		s=w[x]+w[y];
		o.push(x);
		p[x]=0;
		while(!o.empty())
		{
			long long u=o.top();
			o.pop();
			for(auto l:v[u])
			{
				if(p[l.a]>p[u]+l.b)
				{
					o.push(l.a);
					p[l.a]=p[u]+l.b;
				}
			}
		}
		cout<<s+p[y]<<endl;
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/