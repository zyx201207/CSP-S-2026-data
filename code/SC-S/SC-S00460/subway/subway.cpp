#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[500005],c[500005],t[500005];
int dp[5005][5005];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _,n,m,d,q;
	cin>>_>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<5005;i++){
		for(int j=0;j<5005;j++){
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>c[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				dp[c[j]][c[l]]=dp[c[l]][c[j]]=t[j]+t[l];
			}
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(dp[i][k]==1e18)continue;
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<a[x]+a[y]+dp[x][y]<<endl;
	}
	
	return 0;
}