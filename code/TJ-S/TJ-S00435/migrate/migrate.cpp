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
#define ep emplace
using pii=pair<int,int>;
typedef long long ll;
template<typename T>il T& read(T &s){
	s=0;int c=gc(),fg=0;while(!isdigit(c))fg|=(c=='-'),c=gc();
	while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=gc();(fg&&(s=-s));return s;
}
template<typename T>il void write(T s){
	if(s<0)pc('-'),s=-s;if(s>9)write(s/10);pc((s%10)^48);
}
constexpr int N=2e6+5;
int n;ll d,pos[N];
namespace Solve1{
	ll ans=0;
	void bfs(int s){
//		cout<<"================\n";
		queue<int> q;
		vector<int> vis(n+1),dis(n+1),cnt(n+1);
		q.ep(s);vis[s]=1;cnt[s]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
//			cerr<<u<<" "<<dis[u]<<" "<<cnt[u]<<"\n";
			if(cnt[u]==2)ans++;
			for(int v=s;v<=n;v++){
//				cout<<u<<" "<<v<<" "<<abs(pos[v]-pos[u])<<" "<<d<<"\n";
				if(abs(pos[v]-pos[u])>d)continue;
				if(!vis[v])dis[v]=dis[u]+1,cnt[v]=cnt[u],vis[v]=1,q.ep(v);
				else if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
			}
		}
	}
	void solve(){
		ans=0;
		for(int i=1;i<=n;i++)bfs(i);
		write(ans),pc('\n');
	}
}
void solve(int cid){
	read(n);read(d);
	for(int i=1;i<=n;i++)read(pos[i]);
	Solve1::solve();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	signed T=1,cid=0;
	read(cid);
	read(T);
	while(T--){
		solve(cid);
	}
	return 0;
}

