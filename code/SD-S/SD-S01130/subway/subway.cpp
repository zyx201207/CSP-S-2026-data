#include<bits/stdc++.h>
using namespace std;
struct wh
{
	int node,value;
	bool operator<(const wh& other) const
	{
		return value>other.value;
	}
};
int c,n,m,d,q,x,y;
int w[500005];
bool flag[500505];
vector<vector<wh> > v;
int ans=0,len=0;

inline int getSub(int x)
{
	return x;
}
inline int getLine(int x)
{
	return x+m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	v.resize(m+n+1);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			v[getSub(a)].push_back({getLine(i),t});
			v[getLine(i)].push_back({getSub(a),t});
		}
	}
	while(q--)
	{
		priority_queue<wh> p;
		memset(flag,0,sizeof(flag));
		cin>>x>>y;
		p.push({x,0});
		int ans=-1;
		while(!p.empty())
		{
			wh pp;
			pp=p.top();
			p.pop();
			if(pp.node==y)
			{
				if(ans==-1)
					ans=pp.value;
				ans=min(pp.value,ans);
				break;
			}
			flag[pp.node]=true;
			for(auto nxt:v[pp.node])
			{
				if(flag[nxt.node])
					continue;
				p.push({nxt.node,pp.value+nxt.value});
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 
1 5 
2 7 
4 6

3 2 3 3 4 5 7
1 3
1 2
*/
