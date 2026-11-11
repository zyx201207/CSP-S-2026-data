#include<bits/stdc++.h>
using namespace std;

#define int long long
using P =pair<int,int>;
const int N=2e3+5;

int w[N];
int c,n,m,d,q;
int k[N];
int dp[N][N];
vector<int>a[N],t[N];
vector<P>D[N];
void b_e(int ui,int vi,int wi){
	D[ui].push_back({wi,vi});
	D[vi].push_back({wi,ui});
}

void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
//		cin>>k[i];
		scanf("%lld",&k[i]);
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int aij,tij;
//			cin>>aij>>tij;
			scanf("%lld%lld",&aij,&tij);
			a[i].push_back(aij);
			t[i].push_back(tij);
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=(i!=j)*INT_MAX;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int ii=1;ii<k[i];ii++){
			for(int jj=ii+1;jj<=k[i];jj++){
				int u=a[i][ii];
				int v=a[i][jj];
				dp[v][u]=dp[u][v]=min(dp[u][v],t[i][ii]+t[i][jj]);
			}
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}

	while(q--){
		int si,ti;
		cin>>si>>ti;
		printf("%lld\n",dp[si][ti]+w[si]+w[ti]);
//		cout<<<<"\n";
	}
}

int t_;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	t_=1;
//	cin>>t_;
	
	while(t_--){
		solve();
	}
	
	cout.flush();
	
	return 0;
}
