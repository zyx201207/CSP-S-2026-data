#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[510][510],k[510],a[1010][22],cnt[1010],e[1010],op[22][1010];
int v[510][510];
int dp[510][510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			w[i][j]=1e9;
			if(i==j)w[i][j]=0;
			for(int k=0;k<=n;k++){
				if(i==j)dp[i][j][k]=0;
				else dp[i][j][k]=1e9;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>e[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int p;
			cin>>p;
			a[p][++cnt[p]]=i;
			cin>>op[cnt[p]][p];
		}
	}
	for(int p=1;p<=m;p++){
		for(int i=1;i<=cnt[p];i++){
			for(int j=1;j<=cnt[p];j++){
				if(i==j)continue;
				int idd1=a[p][i];
				int idd2=a[p][j];
				w[idd1][idd2]=min(w[idd1][idd2],op[i][p]+op[j][p]);
				dp[idd1][idd2][0]=w[idd1][idd2];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][j][k]=min(dp[i][j][k-1],dp[i][k][k-1]+dp[k][j][k-1]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		int mn=1e9;
		for(int i=1;i<=cnt[u];i++){
			for(int j=1;j<=cnt[v];j++){
				int idd1=a[u][i];
				int idd2=a[v][j];
				mn=min(mn,dp[idd1][idd2][n]+op[i][u]+op[j][v]);
			}
		}
		cout<<mn+e[u]+e[v]<<'\n';
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/