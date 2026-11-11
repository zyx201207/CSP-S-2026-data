#include<bits/stdc++.h>
using namespace std;
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
#define fi first
#define se second
#define mkp make_pair
#define il inline
#define chmax(x,y) ((x<y)&&(x=y))
#define chmin(x,y) ((x>y)&&(x=y))
#define pb emplace_back
using pii=pair<int,int>;
typedef long long ll;
template<typename T>il T& read(T &s){
	s=0;int c=gc(),fg=0;while(!isdigit(c))fg|=(c=='-'),c=gc();
	while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=gc();(fg&&(s=-s));return s;
}
template<typename T>il void write(T s){
	if(s<0)pc('-'),s=-s;if(s>9)write(s/10);pc((s%10)^48);
}
constexpr int N=1e6+5;
int n,k;
vector<int> eg[N];
void solve(int){
	for(int i=1;i<=n;i++)eg[i].clear();
	read(n);read(k);
	for(int i=1,u,v;i<n;i++)read(u)--,read(v)--,eg[u].pb(v),eg[v].pb(u);
	int res=n;
	for(int S=0;S<(1<<n);S++){
		if(__builtin_popcount(S)!=k)continue;
		queue<int> p;vector<int> vv(n);int cnt=0;
		for(int i=0;i<n;i++){
			if(!(S>>i&1)||vv[i])continue;
			vv[i]=1;cnt++;p.emplace(i);
			while(!p.empty()){
				int u=p.front();p.pop();
				for(int v:eg[u])if(!vv[v]&&(S>>v&1))p.emplace(v),vv[v]=1;
			}
		}
		if(cnt>2)continue;
		queue<pii> q;vector<int> vis(n);
		for(int i=0;i<n;i++)if(S>>i&1)q.emplace(i,0),vis[i]=1;
		int ans=0;
		while(!q.empty()){
			auto f=q.front();q.pop();
			int u=f.fi,d=f.se;
			chmax(ans,d);
			for(int v:eg[u])if(!vis[v])vis[v]=1,q.emplace(v,d+1);
		}
		chmin(res,ans);
	}
	write(res),pc('\n');
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	signed T=1,cid=0;
	read(cid);
	read(T);
	while(T--){
		solve(cid);
	}
	return 0;
}

