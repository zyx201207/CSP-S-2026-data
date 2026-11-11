#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N=5e2,M=5e5,Q=1e5,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,_[M+5],w[M+5],dp[N+5][N+5],len[N+5][Q+5];
pii qry[Q+5];
vector<pii> v[N+5],e[M+5];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dp,0x3f,sizeof dp);
	memset(len,0x3f,sizeof len);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(;k--;){
			int a,t;
			cin>>a>>t;
			v[i].push_back({a,t});
			e[a].push_back({i,t});
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(pii j:e[i]){
			for(pii k:e[i]){
				dp[j.fi][k.fi]=min(dp[j.fi][k.fi],j.se+k.se);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qry[i].fi>>qry[i].se;
		_[qry[i].se]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!_[j]) continue;
			for(pii k:e[j]){
				len[i][_[j]]=min(len[i][_[j]],dp[i][k.fi]+k.se);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x=qry[i].fi,y=qry[i].se,ans=inf;
		for(pii j:e[x]){
			ans=min(ans,j.se+len[j.fi][_[y]]);
		}
		cout<<w[x]+ans+w[y]<<"\n";
	}
	return 0;
}
