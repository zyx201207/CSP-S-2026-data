#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int c,n,m,d,q,x,y;
int w[N],k[505];
int a[N][505],t[N][505],dp[N][N];
vector <int> node[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	memset(dp,0x3f3f3f3f,sizeof dp);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			for(int l=1;l<j;l++)dp[a[i][l]][a[i][j]]=dp[a[i][j]][a[i][l]]=min(dp[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			
		}
	}
	while(q--){
		cin>>x>>y;
	}
	return 0;
}

