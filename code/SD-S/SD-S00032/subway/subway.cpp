#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
int a[505][50005],t[505][50005];
int dp[505][505];
int ans;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k*2;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		ans=0;
		ans+=w[s];
		ans+=w[e];
		for(int i=1;i<=e;i++){
			ans+=t[i][i]+t[i][i+1];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
