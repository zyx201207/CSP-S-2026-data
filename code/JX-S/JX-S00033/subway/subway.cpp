#include<bits/stdc++.h>
using namespace std;

const int N=550,M=5e5+10,INF=0x3f3f3f3f;

//subway force floyd

long long c,n,m,d,q;
long long gate[M];
long long dp[N][N];

void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=m;i++){
		cin>>gate[i];
	}
	int k,k1,k2,t1,t2;
	for(int i=1;i<=n;i++){
		cin>>k>>k1>>t1>>k2>>t2;
		dp[k1][k2]=t1+t2;
		dp[k2][k1]=t1+t2;
	}
	floyd();

	int s,t;
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		cout<<(dp[s][t]+gate[s]+gate[t])<<"\n";
	}

	return 0;
}