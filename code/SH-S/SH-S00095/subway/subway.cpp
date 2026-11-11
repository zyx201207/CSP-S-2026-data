#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(n) for(int i=1;i<=(n);i++)
#define V vector
#define pb push_back
#define endl '\n'
#define sc if(debug)cerr
constexpr bool debug=0;
constexpr int _=1000005,mod=998244353,INF=1000000000000000009ll;
const string FLNM="subway";
int CCC,n,m,dddd,q;
int w[_];
constexpr int N=505;
V<pair<int,int> >z[_];
//ith zhanting 
//to jth metro && the weight
//im qu idont know english
//freopen is good
int d[N][N];
#define X first
#define Y second
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	(void)!freopen((FLNM+".in").c_str(),"r",stdin);
	(void)!freopen((FLNM+".out").c_str(),"w",stdout);
	if(debug)(void)!freopen((FLNM+".err").c_str(),"w",stderr);
	cin>>CCC>>n>>m>>dddd>>q;
	FOR(m)cin>>w[i];
	FOR(n){
		int k;cin>>k;
		while(k--){
			int aa,tt;
			cin>>aa>>tt;
			z[aa].pb({i,tt});
		}
	}
	FOR(n)for(int j=1;j<=n;j++)d[i][j]=INF;
	FOR(n)d[i][i]=0;
	FOR(m){
		if(z[i].size()<=1)continue;
		for(int a1=0;a1<(int)(z[i].size());a1++){
			for(int a2=a1+1;a2<(int)(z[i].size());a2++){
				int m1=z[i][a1].X,m2=z[i][a2].X;
				int w1=z[i][a1].Y,w2=z[i][a2].Y;
				d[m1][m2]=min(d[m1][m2],w1+w2);
				d[m2][m1]=min(d[m2][m1],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		FOR(n){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=INF;
		for(int a1=0;a1<(int)(z[u].size());a1++){
			for(int a2=0;a2<(int)(z[v].size());a2++){
				int m1=z[u][a1].X,m2=z[v][a2].X;
				int w1=z[u][a1].Y,w2=z[v][a2].Y;
				ans=min(ans,d[m1][m2]+w1+w2);
			}
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	// FOR(n)for(int j=1;j<=n;j++)cout<<d[i][j]<<endl;
}
