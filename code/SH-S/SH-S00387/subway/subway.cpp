/*
 * 长夜雨慢慢流淌
 * 划过脸庞成两行
 * 能否再聚西窗下
 * 对坐共饮白月光
 * 长夜雨伴着泪光
 * 而你如今在何方
 * 此情一梦难以忘
 * 谁堪与我诉衷肠
 */

#include<bits/stdc++.h>
using namespace std;
#define N 504
#define M 500004
#define ll long long
#define INF 0x66ccffee000000ll
#define fi first
#define se second
inline int read(){
	static char c;
	static int r;r=0;
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return r;
}
int tid,n,m,D,q,k[N];ll w[M];
int head[M],nxt[M<<1],hc;
pair<int,ll> h[M<<1];
// vector<pair<int,ll> > v[M];
ll c[N][N],dis[N][N];
void rain(){
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		dis[i][j]=(i==j?0:c[i][j]);
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
ll snow(int x,int y){
	// int L=v[x].size(),R=v[y].size();
	ll res=INF;
	/*for(int i=0;i<L;++i)for(int j=0;j<R;++j)
		res=min(res,dis[v[x][i].fi][v[y][j].fi]+v[x][i].se+v[y][j].se);*/
	for(int i=head[x];i;i=nxt[i])for(int j=head[y];j;j=nxt[j])
		res=min(res,dis[h[i].fi][h[j].fi]+h[i].se+h[j].se);
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	tid=read(),n=read(),m=read(),D=read(),q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	hc=0;
	for(int i=1;i<=m;++i)head[i]=0;
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j){
			int id;ll t;
			id=read(),t=read();
			++hc;
			nxt[hc]=head[id];
			h[hc]=make_pair(i,t);
			head[id]=hc;
			// v[id].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		c[i][j]=(i==j?0:INF);
	for(int i=1;i<=m;++i){
		// int L=v[i].size();
		int uu,vv;ll dd;
		/* for(int j=0;j<L;++j)for(int k=0;k<j;++k){
			uu=v[i][j].fi,vv=v[i][k].fi;
			dd=v[i][j].se+v[i][k].se;
			c[uu][vv]=min(c[uu][vv],dd);
			c[vv][uu]=min(c[vv][uu],dd);
		} */
		for(int j=head[i];j;j=nxt[j])for(int k=head[i];k!=j;k=nxt[k]){
			uu=h[j].fi,vv=h[k].fi;
			dd=h[j].se+h[k].se;
			c[uu][vv]=min(c[uu][vv],dd);
			c[vv][uu]=min(c[vv][uu],dd);
		}
	}
	rain();
	while(q--){
		int x,y;
		x=read(),y=read();
		printf("%lld\n",snow(x,y)+w[x]+w[y]);
	}
	return 0;
}
