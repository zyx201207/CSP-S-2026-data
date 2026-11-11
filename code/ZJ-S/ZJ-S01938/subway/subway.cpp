#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sc(n) scanf("%lld",&n)
#define scan(n,m) scanf("%lld%lld",&n,&m)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define print(ans) printf("%lld ",ans)
#define put(ans) printf("%lld\n",ans)
#define ed puts("")
#define pb(x) push_back(x)
const int inf=1e18;
const int M=5e5+100;
const int N=505;
int a[M];

unordered_map<int,int> d[N];
int n,m,k,t,ans,cnt,tmp,x,y;
vector<int> g[M];
int dp[N][N];
int q;


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	sc(n);
	sc(n);sc(m);
	sc(q),sc(q);
	rep(i,1,m){
		sc(a[i]);
	}
	rep(i,1,n){
		rep(j,1,n) dp[i][j]=inf;
		dp[i][i]=0;
	}
	
	rep(i,1,n){
		sc(cnt);
		rep(j,1,cnt){
			scan(x,y);
			d[i][x]=y;
			for(auto v:g[x]){
				dp[v][i]=min(dp[v][i],d[v][x]+d[i][x]);
				dp[i][v]=dp[v][i];
				
			}
			g[x].pb(i);
			
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	
	
	
	
	
	rep(i,1,q){
		scan(x,y);
		ans=1e17;
		for(auto u:g[x]){
			for(auto v:g[y]){
				ans=min(ans,dp[u][v]+d[u][x]+d[v][y]);
			}
		}
		ans+=a[x]+a[y];
		put(ans);
		
		
		
	}
	
	
	
	
	return 0;
}
