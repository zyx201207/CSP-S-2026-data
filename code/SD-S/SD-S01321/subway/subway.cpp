#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define popcount(x) __builtin_popcountll(x)
#define pii pair<int,ll>
#define fi first
#define se second
#define inf 1000000000
#define infll 1000000000000000000ll
#define lowbit(x) (x&-x)
using namespace std;
ll qpow(ll a,ll n){ll res=1;while(n){if(n&1)res=res*a;a=a*a;n>>=1;}return res;}
ll qpow(ll a,ll n,ll p){ll res=1;while(n){if(n&1){res=res*a%p;}a=a*a%p;n>>=1;}return res;}
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const int N=510,M=5e5+10;
int c,n,m,d,q;
ll w[M];
vector<pii>e[N];//way
vector<pii>v[M];//all sets u in
ll f[N][N];//cost
void calc(int x){
	for(auto i:e[x]){
		int u=i.fi;
		ll w1=i.se;
		for(auto p:v[u]){
			int j=p.fi;
			ll w2=p.se;
			if(j==x)continue;
			f[x][j]=min(f[x][j],w1+w2);
			f[j][x]=min(f[j][x],w1+w2);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fst;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		while(k--){
			int u=0;ll w=0;
			cin>>u>>w;
			e[i].push_back({u,w});
			v[u].push_back({i,w});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		calc(i);
	}
	for(int k=1;k<=n;k++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
			}
		}
	}
	while(q--){
		int x=0,y=0;
		cin>>x>>y;
		ll res=infll;
		for(auto i:v[x]){
			int u=i.fi;
			ll w1=i.se;
			for(auto j:v[y]){
				int v=j.fi;
				ll w2=j.se;
				res=min(res,f[u][v]+w1+w2);
			}
		}
		cout<<res+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
