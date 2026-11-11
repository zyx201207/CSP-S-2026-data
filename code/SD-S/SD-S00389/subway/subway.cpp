#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=550; 
ll c,n,m,d,q,w[N],k,f[N][25],dis[N][25],dp[N][N],s,e;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof dp);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>f[j][i];
			cin>>dis[f[j][i]][i];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				dp[f[j][i]][f[l][i]]=dis[f[j][i]][i]+dis[f[l][i]][i];
				dp[f[l][i]][f[j][i]]=dis[f[j][i]][i]+dis[f[l][i]][i];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dp[i][j]>dp[i][k]+dp[k][j]&&dp[i][k]!=0&&dp[k][j]!=0){
					dp[i][j]=dp[i][k]+dp[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		cout<<w[s]+w[e]+dp[s][e]<<"\n"	;
	}	
	return 0;
}

