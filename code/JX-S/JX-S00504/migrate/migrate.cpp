//migrate
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define emdl '\n'
typedef long long ll;
const int MAXN=5e5+5;

void solve(){
	int n,d;
	cin>>n>>d;
	int x[n+5];
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	
	int cost[n+5][n+5];
	memset(cost,0x3f,sizeof cost);
	int sum[n+5][n+5];
	memset(sum,0,sizeof sum);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(x[j]-x[i]<=d){
				cost[i][j]=1;
				sum[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int p=i;p<=j;p++){
				if(i==p || p==j) continue;
				if(cost[i][p]+cost[p][j]<cost[i][j]){
					cost[i][j]=cost[i][p]+cost[p][j];
					sum[i][j]=1;
				}
				else if(cost[i][p]+cost[p][j]==cost[i][j]){
					sum[i][j]++;
				}
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(sum[i][j]==2) ans++;
		}
	}
	cout<<ans<<emdl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
/*
8129
*/
