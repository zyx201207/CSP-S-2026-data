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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}

namespace BRUTE{
	const int maxn=5005;
	int n;
	ll d,x[maxn];
	int nxt[maxn];// i 的下一个点 
	int dis[maxn][maxn];// 最短路 
	int prv[maxn];// 最早的 j 使得 dis[j][i]=1
	bool weiyi[maxn][maxn];// s->t 路径是否唯一 
	bool ans[maxn][maxn];
	void clear(){
		FOR(i,0,n+1){
			nxt[i]=0;
			prv[i]=0;
			FOR(j,0,n+1){
				weiyi[i][j]=ans[i][j]=0;
			}
		}
	}
	void solve(int testid){
		read(n);
		read(d);
		FOR(i,1,n){
			read(x[i]);
		}
		{
			FOR(i,1,n){
				nxt[i]=max(i,nxt[i-1]);
				while(nxt[i]<n&&x[nxt[i]+1]-x[i]<=d){
					nxt[i]++;
				}
			}
		}
		{
			FOR(i,1,n)FOR(j,1,n)dis[i][j]=1e9;
			FOR(s,1,n){
				dis[s][s]=0;
				int t=nxt[s];
				int lsted=s;
				int _dis=0;
				while(t!=lsted){
					_dis++;
					FOR(i,lsted+1,t){
						dis[s][i]=_dis;
					}
					lsted=t;
					t=nxt[t];
				}
			}
		}
		{
			FOR(i,1,n){
				prv[i]=prv[i-1];
				ckmx(prv[i],1);
				while(x[i]-x[prv[i]]>d)prv[i]++;
			}
		}
		{
			FOR(s,1,n){
				weiyi[s][s]=1;
				FOR(t,s+1,n){
					if(dis[s][t]>1e8)break;
					if(dis[s][t]==1){
						weiyi[s][t]=1;
						continue;
					}
					int x=max(s,prv[t]);
					int mndis=dis[s][x];
					int cntmndis=0;
					FOR(i,x,min(t,x+1)){
						cntmndis+=(dis[s][i]==mndis);
					}
					weiyi[s][t]=(cntmndis==1&&weiyi[s][x]);
				}
			}
		}
		FOR(s,1,n){
			FOR(t,s+1,n){
				if(dis[s][t]==1)continue;
				if(dis[s][t]>1e8)break;
				int x=max(s,prv[t]);
				int mndis=dis[s][x];
				int cntmndis=0;
				FOR(i,x,min(t,x+2)){
					cntmndis+=(dis[s][i]==mndis);
				}
				if(cntmndis>=3)continue;
				if(cntmndis==2){
					if(weiyi[s][x]&&weiyi[s][x+1]){
						ans[s][t]=1;
					}
					continue;
				}
				// cntmndis==1
				ans[s][t]=ans[s][x];
			}
		}
		int out=0;
		FOR(s,1,n){
			FOR(t,s+1,n){
				out+=ans[s][t];
			}
		}
		printf("%d\n",out);
		// clear
		clear();
	}
}

namespace SPE_A{
	const int maxn=2e6+5;
	int n;
	ll d,x[maxn];
	void solve(){
		read(n);
		read(d);
		FOR(i,1,n){
			read(x[i]);
		}
		if(n==1){
			puts("0");
			return;
		}
		int sgjump=min(ll(n),d/(x[2]-x[1]));// 单次跳多少个 
		if(sgjump<=1){
			puts("0");
			return;
		}
		int ans=0;
		FOR(s,1,n){
			int t=s+2*sgjump;
			t--;
			if(t<=n){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}

int main(){
	io();
	int c;
	read(c); 
	int T;
	read(T);
	FOR(_,1,T){
		if(c<=10){
			BRUTE::solve(c);
		}else{
			SPE_A::solve();
		}
	}
	return 0;
}

