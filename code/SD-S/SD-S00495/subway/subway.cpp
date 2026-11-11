#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
#define c1(x) __builtin_popcountll(x)
#define ull unsigned long long
#define lowbit(x) x&-x
#define int long long
#define pb push_back
#define db double

using namespace std;

typedef pair<int,int> pii;
typedef pair<db,db> pdd;

const int N=510,M=5e5+10;
int c,n,m,d,q,w[M],k[N],g[N][N];
vector<pii> lines[M],p[N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IOS
	cin>>c>>n>>m>>d>>q; 
	rep(i,1,m) cin>>w[i];
	rep(i,1,n)
	{
		cin>>k[i];
		rep(j,1,k[i])
		{
			int x,tt;
			cin>>x>>tt;
			lines[x].pb({i,j-1});
			p[i].pb({x,tt});
		}
	}
//	cout<<q<<"\n";
	memset(g,0x3f,sizeof g);
	rep(i,1,n) g[i][i]=0;
	rep(i,1,n)
	{
		for(auto p1:p[i])
		{
			int x=p1.first,t=p1.second;
			for(auto p2:lines[x])
			{
				int j=p2.first,id=p2.second,tt=p[j][id].second;
				if(i==j) continue;
				g[i][j]=min(g[i][j],t+tt);
				g[j][i]=min(g[j][i],t+tt);
			} 
		}
	}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto px:lines[x])
			for(auto py:lines[y])
			{
				if(px.first==-114514) continue;
				if(py.first==-114514) continue; 
				int cost=p[px.first][px.second].second+p[py.first][py.second].second+g[px.first][py.first];
				ans=min(ans,cost);	
			} 
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*CSP-S 2026 AK RP++!
有没有写freopen?
数组是否开够？
有没有爆空间？
有没有交错代码？
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

