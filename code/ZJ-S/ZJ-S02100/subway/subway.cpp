#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define rep_(i,l,r) for(int i=(l); i>=(r); --i)
typedef long long lr;
constexpr lr inf64=0x3f3f3f3f3f3f3f3f;
constexpr int N=505,M=500500;
int c,n,m,d,q,w[M]; lr g[N][N];
int cnt[M],a[M][22],b[M][22];
void Solve()
{
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n)
	{
		int s; cin>>s;
		while(s--)
		{
			int x,y; cin>>x>>y;
			a[x][++cnt[x]]=i,b[x][cnt[x]]=y;
		}
	}
	rep(i,1,n) rep(j,1,n) g[i][j]=inf64;
	rep(i,1,n) g[i][i]=0;
	rep(i,1,m)
	{
		int *A=a[i],*B=b[i];
		rep(j,1,cnt[i])
		{
			lr *G=g[A[j]];
			rep(k,1,cnt[i]) G[A[k]]=min(G[A[k]],(lr)B[j]+B[k]);
		}
	}
	rep(k,1,n) rep(i,1,n) rep(j,1,n)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--)
	{
		int x,y; cin>>x>>y;
		lr ans=inf64;
		rep(i,1,cnt[x]) rep(j,1,cnt[y])
			ans=min(ans,b[x][i]+g[a[x][i]][a[y][j]]+b[y][j]);
		cout<<w[x]+ans+w[y]<<'\n';
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T=1;
	while(T--) Solve();
	return 0;
}