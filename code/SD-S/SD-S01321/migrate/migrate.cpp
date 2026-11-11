#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define popcount(x) __builtin_popcountll(x)
#define pii pair<int,int>
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
const int N=2e6+10,M=5005;
int n;
ll d;
ll x[N];
namespace __Lavender__{
	int f[M][M];
	int cnt[M];
	bitset<M>vis;
	void dfs(int st,int u,int dis){
		if(dis>f[st][u])return;
		cnt[u]++;
		vis[u]=1;
		for(int i=1;i<=n;i++){
			if(abs(x[i]-x[u])<=d&&!vis[i])dfs(st,i,dis+1);
		}
		vis[u]=0;
	}
	void unnewbie(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=inf;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d)f[i][j]=1;
			} 
		}
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2)ans++;
				cnt[j]=0;
			}
		}
		cout<<ans/2<<endl;
	}
}
void solve(int c){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	__Lavender__::unnewbie();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	fst;
	int c,T;
	cin>>c>>T;
	while(T--){
		solve(c);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
