#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(auto i=(a);i<=(b);i++)
#define REP(i,a,b) for(auto i=(a);i>=(b);i--)
#define FORK(i,a,b,k) for(auto i=(a);i<=(b);i+=(k))
#define REPK(i,a,b,k) for(auto i=(a);i>=(b);i-=(k))
#define fi first
#define se second
#define gc getchar()
#define pc putchar
#define pln pc(10);
#define eb emplace_back
#define pb push_back
#define mkpr make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
template<class T>
void ckmx(T& a,T b){
	a=max(a,b);
}
template<class T>
void ckmn(T& a,T b){
	a=min(a,b);
}
template<class T>
void read(T& x){
	x=0;
	int f=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc;
	}
	x*=f;
}
void io(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
const int maxn=505,maxm=5e5+5;
int n,m,d,q;
vector<pair<int,ll> > rem[maxm];
ll dis[maxn][maxn];
ll w[maxm];
void solve(int testid){
	FOR(i,1,m){
		read(w[i]);
	}
//	puts("wtf");
	FOR(i,1,n){
		int k;
		read(k);
		FOR(_,1,k){
			int id;
			ll tim;
			read(id);
			read(tim);
			rem[id].eb(mkpr(i,tim));
		}
	}
//	puts("wtf");
	memset(dis,0x3f,sizeof dis);
	FOR(i,1,n)dis[i][i]=0;
	FOR(i,1,m){
		for(auto v1:rem[i]){
			for(auto v2:rem[i]){
				ckmn(dis[v1.fi][v2.fi],v1.se+v2.se);
			}
		}
	}
	{
		FOR(mid,1,n){
			FOR(u,1,n){
				FOR(v,1,n){
					ckmn(dis[u][v],dis[u][mid]+dis[mid][v]);
				}
			}
		}
	}
	FOR(_,1,q){
		int s,t;
		read(s);
		read(t);
		ll ans=1e18;
		for(auto vs:rem[s]){
			for(auto vt:rem[t]){
				ckmn(ans,dis[vs.fi][vt.fi]+vs.se+vt.se);
			}
		}
		ans+=w[s]+w[t];
		printf("%lld\n",ans);
	}
}
int main(){
//	freopen("subway5.in","r",stdin);
	io();
	int c;
	read(c);
	read(n);
	read(m);
	read(d);
	read(q);
	int T=1;
	FOR(_,1,T){
		solve(c);
	}
	return 0;
}

