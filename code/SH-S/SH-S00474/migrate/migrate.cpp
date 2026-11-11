#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> PII;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		vector<long long> pos(n+1);
		for(int i=1;i<=n;i++){
			cin>>pos[i];
		}
		vector<vector<PII> > dp(n+1,vector<PII>(n+1,{INF,1}));
		for(int i=1;i<=n-1;i++){
			if(pos[i+1]-pos[i]<=d) dp[i][i+1]={1,1};
		}
		for(int len=3;len<=n;len++){
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				if(pos[r]-pos[l]<=d){
					dp[l][r]={1,1};
					continue;
				}
				for(int k=l+1;k<=r-1;k++){
					if(dp[l][k].first==INF||dp[k][r].first==INF) continue;
					if(dp[l][k].first+dp[k][r].first<dp[l][r].first){
						dp[l][r]={dp[l][k].first+dp[k][r].first,1};
					}
					else if(dp[l][k].first+dp[k][r].first==dp[l][r].first){
						dp[l][r].second++;
					}
				}
			}
		}
		
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(j<=n&&dp[i][j].second==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
