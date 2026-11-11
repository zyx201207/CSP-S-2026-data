#include<bits/stdc++.h>
#define ll long long
#define ac read()
#define N 2000006
#define M 5050
using namespace std;
inline ll read() {
	ll x=0,f=1;
	ll c=getchar();
	while(!isdigit(c)) {
		f=(c=='-')?-1:1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
ll c,T,n,d;
ll x[N];
struct node {
	ll nex,to;
} e[M*M];
ll head[N],tot;
inline void add(ll u,ll v) {
	e[++tot].nex=head[u];
	e[tot].to=v;
	head[u]=tot;
}
ll dis[M][M],vis[M][M],shu[M][M];
ll Jul[M][M];
struct Num {
	ll id,num;
};
bool operator < (Num a,Num b) {
	a.num>b.num;
}
inline void Dijs(ll s) {
	priority_queue<Num> q;
	q.push({s,0});
	dis[s][s]=0;
	vis[s][s]=1;
	while(!q.empty()) {
		Num t=q.top();
		q.pop();
		ll u=t.id;
		ll num=t.num;
		for(ll i=head[u]; i!=-1; i=e[i].nex) {
			ll to=e[i].to;
			if(!vis[s][to]&&dis[s][to]>dis[s][u]+1) {
				dis[s][to]=dis[s][u]+1;
				q.push({to,dis[s][to]});
				vis[s][to]=1;
			}
		}
	}
}
ll flag[M];
inline void bfs(ll s) {
	shu[s][s]=1;
	for(ll i=1; i<=n; ++i) flag[i]=0;
	queue<ll> q;
	q.push(s);
	flag[s]=1;
	while(!q.empty()) {
		ll u=q.front();
		q.pop();
		for(ll i=head[u]; i!=-1; i=e[i].nex) {
			ll to=e[i].to;
			if(Jul[s][u]==dis[s][to]-1) {
				shu[s][to]+=shu[s][u];
				Jul[s][to]=dis[s][to];
				if(!flag[to]) {
					q.push(to);
					flag[to]=1;
				}
			}
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=ac,T=ac;
	while(T--) {
		n=ac,d=ac;
		tot=0;
		for(ll i=0; i<=n; ++i) {
			head[i]=-1;
		}
		for(ll i=0; i<=n; ++i) {
			for(ll j=0; j<=n; ++j) {
				dis[i][j]=1e18;
				vis[i][j]=0;
				shu[i][j]=0;
				Jul[i][j]=0;
			}
		}
		for(ll i=1; i<=n; ++i) {
			x[i]=ac;
		}
		for(ll i=1; i<=n; ++i) {
			for(ll j=i+1; j<=n; ++j) {
				if(x[j]-x[i]>d) break;
				add(i,j);
				add(j,i);
			}
		}
		for(ll i=1; i<=n; ++i) {
			Dijs(i);
		}
		ll ans=0;
		for(ll i=1; i<=n; ++i) {
			bfs(i);
			for(ll j=1; j<=n; ++j) {
				if(shu[i][j]==2) {
					++ans;
				}
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}

