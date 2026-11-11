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
constexpr int inf=0x3f3f3f3f;
constexpr ll  Inf=0x3f3f3f3f3f3f3f3f;
constexpr int N=505,M=5e5+5;
int n,m,a[M];ll f[N][N];
vector<pii> s[M];
void solve(int){
//	cout<<"111\n";
	int _,q;
	read(n);read(m);read(_);read(q);
//	cout<<"111\n";
	for(int i=1;i<=m;i++)read(a[i]);
	for(int i=1;i<=n;i++){
		int k,x,y;read(k);
		while(k--){
			read(x),read(y);
			s[x].pb(i,y);
		}
	}
//	cout<<"111\n";
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=Inf;
	for(int i=1;i<=n;i++)f[i][i]=0;
//	cout<<"111\n";
	for(int c=1;c<=m;c++){
		int d=s[c].size();
//		cerr<<c<<"\n";
		for(int i=0;i<d;i++){
			int u=s[c][i].fi,w=s[c][i].se;
			for(int j=i+1;j<d;j++){
				int v=s[c][j].fi,w2=s[c][j].se;
//				cerr<<u<<" "<<v<<" "<<w<<" "<<f[u][v]<<"\n";
				if(f[u][v]>w+w2)f[u][v]=f[v][u]=w+w2;
			}
		}
	}
//	for(int i=1;i<=n;i++,cerr<<"\n")for(int j=1;j<=n;j++)cerr<<f[i][j]<<" ";
//	cerr<<"\n";
//	cout<<"111\n";
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				chmin(f[i][j],f[i][k]+f[k][j]);
			}
		}
//	for(int i=1;i<=n;i++,cerr<<"\n")for(int j=1;j<=n;j++)cerr<<f[i][j]<<" ";
//	cerr<<"\n";
	}
//	cout<<"111\n";
	while(q--){
		int u,v;read(u);read(v);
		ll ans=Inf;
		for(auto tu:s[u])for(auto tv:s[v])chmin(ans,f[tu.fi][tv.fi]+tu.se+tv.se);
		write(ans+a[u]+a[v]),pc('\n');
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	signed T=1,cid=0;
	read(cid);
//	read(T);
	while(T--){
		solve(cid);
	}
	return 0;
}

