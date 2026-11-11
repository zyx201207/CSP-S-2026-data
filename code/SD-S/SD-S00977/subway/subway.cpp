#include<bits/stdc++.h>
using namespace std;
long long c,m,n,o,q,w[500005],a[500005],b[500005],d[500005];
struct abc
{
	int u,v;
	bool operator <(const abc &oth) const
	{
		return v>oth.v;	
	}	
};
vector<abc>es[500005];
void di(long long s)
{
	memset(d,0x3f,sizeof(d));
	priority_queue<abc>p;
	p.push(abc{s,0});
	while(p.size())
	{
		long long u=p.top().u;
		long long v=p.top().v;
		p.pop();
		if(v<d[u])
		{
			d[u]=v;
			for(auto nxt:es[u])
			{
				long long h=nxt.u;
				if(d[u]+nxt.v<d[h])
				{
					p.push(abc{h,d[u]+nxt.v});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>o>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	while(m--)
	{
		long long k,h=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>b[j];
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<i;j++)
			{
				es[a[i]].push_back(abc{a[j],b[i]+b[j]});
				es[a[j]].push_back(abc{a[i],b[i]+b[j]});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long x,y;
		cin>>x>>y;
		di(x);
		cout<<d[y]+w[x]+w[y]<<endl;
	}
	return 0;
}

