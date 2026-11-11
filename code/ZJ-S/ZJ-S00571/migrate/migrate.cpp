#include <bits/stdc++.h>
#define endl '\n'
#define LAB
//#define DEBUG
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int,int>;
using pli = pair<ll,int>;
const int N = 3e2+10;

int CASE;
ll dp[N][N][N],pre[N][N][N];

void Solve() {
	ll n,d;
	ll ans=0;
	cin>>n>>d;
	vector<ll> x(n+10);
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			for(int k=0;k<=n;k++) {
				dp[i][j][k]=pre[i][j][k]=0;
			}
		}
	}
	for(int i=1;i<=n;i++) dp[i][0][i]=1;
	for(int i=1;i<=n;i++) {
		int ix;
		for(int k=1;k<=n;k++) {
			ix=1;
			for(int j=1;j<=n;j++) 
				pre[i][k-1][j]=pre[i][k-1][j-1]+dp[i][k-1][j];
			for(int j=i+k;j<=n;j++) {
				while(x[j]-x[ix]>d) ix++;
				dp[i][k][j]=pre[i][k-1][j]-pre[i][k-1][ix-1];
			}
		}
	} 
	#ifdef DEBUG
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			for(int k=0;k<=n;k++) {
				cerr<<"dp["<<i<<"]["<<k<<"]["<<j<<"]="<<pre[i][k][j]<<endl;
			}
		}
	}
	#endif
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			int mink=0;
			while(dp[i][mink][j]==0) mink++;
			if(dp[i][mink][j]==2) {
				ans++;
				#ifdef DEBUG
				cerr<<i<<' '<<j<<' '<<mink<<endl;
				#endif
			}
		}
	} 
	cout<<ans<<endl;
}

int main() {
	#ifdef LAB
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	#endif
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>CASE;
	
	int T; cin>>T; while(T--) Solve();
	
	return 0;
}


