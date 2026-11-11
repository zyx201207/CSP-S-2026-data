#include<bits/stdc++.h>
using namespace std;
int w[500009],a[509][509],t[509][509],dp[509][509];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k; cin>>k;
		for(int j = 1;j<=n;j++){
			cin>>a[i][j]>>t[i][j];
			t[i][j] = t[j][i];
		}
	}
	for(int i = 1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		cout<<dp[x][y]<<endl;
	}
	
	return 0;
}
