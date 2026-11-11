#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
typedef long long ll;
const long long INF=1e17+114514;
inline ll read()
{
	ll x=0; char ch;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-'0', ch=getchar();
	return x;
}

ll n,m,mx_sub,q,tim_k[500009],mntim[509][509];
bool vis[509];
struct _EDGE {ll to,w;};
vector<_EDGE> nod[500009];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll cas=read(); n=read(), m=read(), mx_sub=read(), q=read();
	FOR(i,1,n) FOR(j,1,n) mntim[i][j]=INF;
	FOR(i,1,m) tim_k[i]=read();
	FOR(p,1,n)
	{
		ll k=read();
		FOR(i,1,k)
		{
			ll a=read(),t=read();
			nod[a].push_back((_EDGE){p,t});
		}
	}
	FOR(i,1,m)
	{
		for(_EDGE nx:nod[i])
			for(_EDGE ny:nod[i])
			{
				mntim[nx.to][ny.to]=min(mntim[nx.to][ny.to],nx.w+ny.w);
				mntim[ny.to][nx.to]=min(mntim[ny.to][nx.to],nx.w+ny.w);
			}
	}
	FOR(i,1,n) mntim[i][i]=0;
	FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) mntim[i][j]=min(mntim[i][j],mntim[i][k]+mntim[k][j]); // floyd
	FOR(Q,1,q)
	{
		ll st=read(),ed=read(),ans=INF;
		for(_EDGE ste:nod[st]) for(_EDGE ede:nod[ed])
			ans=min(ans,ste.w+ede.w+tim_k[st]+tim_k[ed]+mntim[ste.to][ede.to]);
		printf("%lld\n",ans);
	}
	return 0;
}

// 100pts!!!

// RP++
