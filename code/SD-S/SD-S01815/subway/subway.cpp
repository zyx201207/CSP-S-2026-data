#include<bits/stdc++.h>
using namespace std;
#define N 500007
#define M 507
#define ll long long
#define rnt register int
#define A first
#define B second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
int c,n,m,d,q,t[N][M];
ll w[N],cst[M][M],dp[M][M];
vector<int> ls[N];
void floyD(){
	for(rnt i=1;i<=n;++i) cst[i][i]=0;
	for(rnt i=1;i<=n;++i) for(rnt j=1;j<=n;++j) dp[i][j]=cst[i][j];
	for(rnt i=1;i<=n;++i) for(rnt j=1;j<=n;++j) for(rnt k=1;k<=n;++k)
		dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
}
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(cst,0x3f,sizeof cst);
	for(rnt i=1;i<=m;++i) cin>>w[i];
	for(rnt k,i=1;i<=n;++i){
		cin>>k;
		for(rnt a,iN,j=1;j<=k;++j){
			cin>>a>>iN;
			t[a][i]=iN;ls[a].pb(i);
		}
	}for(rnt i=1;i<=m;++i) for(auto j:ls[i]) for(auto k:ls[i])
		cst[j][k]=min(cst[j][k],0ll+t[i][j]+t[i][k]);
	floyD();
	while(q--){
		int l,r;cin>>l>>r;
		ll ans=4e18;
		for(auto i:ls[l]) for(auto j:ls[r])
			ans=min(ans,t[l][i]+t[r][j]+min(dp[i][j],dp[j][i]));
		cout<<ans+w[l]+w[r]<<'\n';
	}
}
