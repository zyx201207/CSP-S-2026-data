#include<bits/stdc++.h>
#define int long long
#define si signed
#define endl '\n'
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fp(s) string ssss=s;freopen((ssss+".in").c_str(),"r",stdin);freopen((ssss+".out").c_str(),"w",stdout);
#define rep(i,x,y) for(int i=x;i<=(y);++i)
#define inl inline
#define INF 1e18
#define eb emplace_back
using namespace std;
const int N=505,M=5e5+5;
int a[M],f[N][N];
struct pr{
	int id,w;
	inl pr(){
		id=w=0;
	}
	inl pr(int id,int w):id(id),w(w){}
};
vector<pr >g[M];
si main(){
	fp("subway");
	fst;
	int p,n,m,q;
	cin>>p>>n>>m>>p>>q;
	rep(i,1,m) cin>>a[i];
	rep(i,1,n){
		int k;
		cin>>k;
		rep(j,1,k){
			int x,t;
			cin>>x>>t;
			g[x].eb(i,t);
		}
	}
	rep(i,0,n+1)
		rep(j,0,n+1) f[i][j]=INF;
	rep(i,1,n) f[i][i]=0;
	rep(i,1,m)
		rep(j,0,(int)g[i].size()-1)
			rep(k,j+1,(int)g[i].size()-1) f[g[i][j].id][g[i][k].id]=f[g[i][k].id][g[i][j].id]=min(f[g[i][j].id][g[i][k].id],g[i][j].w+g[i][k].w);
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	rep(i,1,n){
//		rep(j,1,n) cout<<f[i][j]<<' ';
//		cout<<endl; 
//	}
	rep(i,1,q){
		int u,v,ans=INF;
		cin>>u>>v;
		rep(j,0,(int)g[u].size()-1)
			rep(k,0,(int)g[v].size()-1) ans=min(ans,a[u]+a[v]+g[u][j].w+g[v][k].w+f[g[u][j].id][g[v][k].id]);
		cout<<ans<<endl;
	}
	return 0;
} 
