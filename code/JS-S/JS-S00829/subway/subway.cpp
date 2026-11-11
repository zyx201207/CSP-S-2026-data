#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define rept(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) rept(i,0,n)
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define il inline
#define re return
#define pb push_back
#define db double
#define ld long db
#define int long long
using namespace std;
template<typename T>void Mx(T&x,T y){if(x<y)x=y;}
template<typename T>void Mi(T&x,T y){if(x>y)x=y;}
const int MOD=998244353,INF=1000000000000000000;
void FIO(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int N=505,M=500005;
int n,m,d,q;
int dis[N][N],cd[M];
vector<pii>v[M];
void run(){
	cin>>n>>m>>d>>q;
	rep(i,m)cin>>cd[i];
	rep(i,n){
		int ck;cin>>ck;
		rep(_,ck){
			int x,y;cin>>x>>y;
			x--;
			v[x].pb({i,y});
		}
	}
	rep(i,n)rep(j,n)dis[i][j]=INF;
	rep(i,n)dis[i][i]=0;
	rep(i,m){
		for(pii x:v[i])for(pii y:v[i]){
			Mi(dis[x.F][y.F],x.S+y.S);
		}
	}
	rep(i,n)rep(j,n)rep(k,n)
		Mi(dis[j][k],dis[j][i]+dis[i][k]);
	rep(_,q){
		int s,t;
		cin>>s>>t;
		s--;t--;
		int ans=INF;
		for(pii x:v[s])for(pii y:v[t]){
			Mi(ans,cd[s]+cd[t]+dis[x.F][y.F]+x.S+y.S);
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	FIO("subway");
	int T=1;
	int _C;
	cin>>_C;
	// cin>>T;
	while(T--)
		run();
	re 0;
}