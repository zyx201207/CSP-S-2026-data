#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5;
const int N=5e3+5;
struct edge{
	int to,val;
};
int c,n,m,d,q,w[M];
vector<edge> a[M],t[M];
ll ans;
void dfs(int p,int ennd,int type,ll res)
{
	// assert(0);
	if(p==ennd)
	{
		res+=t[type][p].val;
		ans=min(ans,res);
		// cout<<res<<endl;
		return;
	}
	for(edge x:a[p])
	{
		if(x.val!=type) res+=t[type][p].val+t[x.val][p].val;
		dfs(x.to,ennd,x.val,res);
		if(x.val!=type) res-=t[type][p].val+t[x.val][p].val;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int A1,T,A2;
			cin>>A2>>T;
			if(j!=1)
			{
				a[A1].push_back({A2,i});
				t[A2].push_back({i,T});
			}
			A1=A2;
		}
	}
	while(q--)
	{
		int b,e;
		cin>>b>>e;
		ans=1e18;
		for(edge x:a[b])
		{
			// assert(0);
			dfs(b,e,x.val,w[b]+w[e]+t[x.val][b].val);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/