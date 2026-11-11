#include<bits/stdc++.h>
#define LL long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i++)
using namespace std;
const int M=5e5+5,N=505;
const LL inf=1e18;
int c,n,m,d,q;
int w[M];
vector< pair<int,int> > a[N];
LL dis[301][301];
void solve1()
{
	rep(i,1,m) rep(j,1,m) dis[i][j]=((i!=j)?inf:0);
	rep(i,1,n)
	{
		rep(j,0,a[i].size()-1)
		  rep(k,j+1,a[i].size()-1)
		    dis[a[i][j].first][a[i][k].first]=
		    dis[a[i][k].first][a[i][j].first]=
			1ll*a[i][j].second+a[i][k].second;
	}
	rep(k,1,m)
	  rep(i,1,m)
	    rep(j,1,m)
		  dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int x,y;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",dis[x][y]+w[x]+w[y]);
	}
}
vector<pair<int,LL> > e[1005];
LL find(int u,int fa,int mb)
{
	if(u==mb) return 1;
	for(auto i:e[u])
	{
		if(i.first==fa) continue;
		LL Find=find(i.first,u,mb);
		if(Find) return Find+i.second;
	}
	return 0;
}
void solve2()
{
	rep(i,1,n)
	{
		if(a[i].size()==1) continue;
		e[a[i][0].first].push_back({a[i][1].first,1ll*a[i][0].second+a[i][1].second});
		e[a[i][1].first].push_back({a[i][0].first,1ll*a[i][0].second+a[i][1].second});
	}
	int x,y;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",find(x,0,y)-1+w[x]+w[y]);
	}
}
LL t[3][M];
void solve3()
{
	rep(i,1,m) t[1][i]=t[2][i]=inf;
	rep(i,1,2)
	  rep(j,0,a[i].size()-1)
		t[i][a[i][j].first]=a[i][j].second;
	LL hm=inf;
	rep(i,1,n) hm=min(hm,t[1][i]+t[2][i]);
	cout<<hm<<endl;
	int x,y;
	while(q--)
	{
		scanf("%d%d",&x,&y);
//		cout<<t[1][x]<<" "<<t[1][y]<<" "<<t[2][x]<<" "<<t[2][y]<<endl;
		if(n==1) printf("%lld\n",1ll*t[1][x]+t[1][y]+w[x]+w[y]);
		else printf("%lld\n",min(min(t[1][x]+t[1][y],t[2][x]+t[2][y]),min(t[1][x]+t[2][y],t[1][x]+t[2][y])+hm)+w[x]+w[y]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	rep(i,1,m) scanf("%d",&w[i]);
	int k,zhan,ti;
	rep(i,1,n)
	{
		scanf("%d",&k);
		rep(j,1,k)
		{
			scanf("%d%d",&zhan,&ti);
			a[i].push_back({zhan,ti});
		}
	}
	if(c<=6) solve1();
	if(7<=c&&c<=11) solve2();
	if(c==20||c==21) solve3();
//	solve2();
	return 0;
}