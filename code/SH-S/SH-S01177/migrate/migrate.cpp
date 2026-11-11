#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
typedef long long ll;
const long long INF=1e17+114514;
inline ll read()
{
	ll x=0,f=1; char ch;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') f=-1, ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-'0', ch=getchar();
	return x*f;
}

ll cas,t,n,l,x[200009],d[200009],js[200009];
vector<ll> es[200009];

void dijkstra(ll s)
{
	priority_queue<pair<ll,ll> > q;
	fill(d,d+n+2,INF);
	fill(js,js+n+2,1ll);
	d[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		pair<ll,ll> nw=q.top(); q.pop();
//		if(!vis[nw]) vis[nw]=true;
//		else continue;
		for(auto x:es[nw.second])
		{
//			if(vis[x]) continue;
			if(d[x]==d[nw.second]+1) js[x]+=js[nw.second];
			if(d[x]>d[nw.second]+1)
			{
				d[x]=d[nw.second]+1,js[x]=js[nw.second];
				q.push({-d[x],x});
			}
		}
	}
	return;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cas=read(),t=read();
	while(t--)
	{
		ll ans=0; n=read(),l=read();
		FOR(i,1,n) x[i]=read();
		FOR(i,1,n)
		{
			ll mxlng=x[i]+l;
			ll pos=upper_bound(x+1,x+n+1,mxlng)-x-1;
//			FOR(j,i+1,pos) es[i].push_back(j); 
			for(int j=pos;j>i&&j>=pos-2;j--) es[i].push_back(j);
		}
		FOR(i,1,n)
		{
			dijkstra(i);
			FOR(j,i+1,n) if(js[j]==2) ans++;
		}
		printf("%lld\n",ans);
		FOR(i,1,n) es[i].clear();
	}
	return 0;
}

// 40pts~

// RP++
