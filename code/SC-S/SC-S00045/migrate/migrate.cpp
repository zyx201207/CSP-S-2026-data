#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<vector<int>> dist(n,vector<int>(n,INF));
		for(int i=0;i<n;i++)dist[i][i]=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[j]-a[i]<=d){
					dist[i][j]=min(dist[i][j],1ll); 
				}
			}
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<=k;i++){
				for(int j=k;j<n;j++){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		vector<vector<int>> dp(n,vector<int>(n,0));
		for(int k=0;k<n;k++){
			for(int i=0;i<k;i++){
				for(int j=k;j<n;j++){
					if(dist[i][j]>=INF/2)continue;
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
						if(dist[i][j]==dist[i][k]+dist[k][j]){
							dp[i][j]++;
						}
					}
				}
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
//				cout<<dist[i][j]<<' ';
				if(dp[i][j]==2)cnt++;
			}
//			cout<<'\n';
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
