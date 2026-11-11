#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=510,M=5e5+10,D=110,Q=1e5+10;

int c,n,m,d,q;
int ans;
int dp[N][N];
int a[M];
int t[M];

void mark(int k){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			dp[a[i]][a[j]]=min(dp[a[i]][a[j]],t[j]);
		}
	}
}

signed main(){
//	freopen("C:\\Users\\stu\\Desktop\\csps-new\\down\\subway\\subway1.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	vector<int> w(m+10);
	vector<int> k(n+10);
	memset(dp,0x3f,sizeof dp);
	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
		mark(k[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[j][k]=min(dp[j][i]+dp[i][k],dp[j][k]);
			}
		}	
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(dp[x][y]==dp[N-1][N-1]) cout<<w[x]+w[y]<<"\n";
		else cout<<dp[x][y]+w[x]+w[y]<<"\n";
	}
	
	return 0;
}
