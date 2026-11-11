#include<bits/stdc++.h>
using namespace std;
const int N = 505,M = 405;
long long w[M],a[N][M],t[N][M],len[N],dp[505][505];
bool vis[N];
vector<int>e[505];
int  c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			
		}
		len[i] = k;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i!=j)dp[i][j] = 1e18;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=len[i];j++){
			for(int g = 1;g<=len[i];g++){
				if(j==g)continue;
				dp[a[i][j]][a[i][g]] = t[i][j]+t[i][g];
				dp[a[i][g]][a[i][j]] = t[i][j]+t[i][g];
				e[a[i][j]].push_back(a[i][g]);
				e[a[i][g]].push_back(a[i][j]);
			}
			
		}
	} 
	for(int h = 1;h<=2*n;h++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					if(dp[k][j]!=1e18&&dp[k][i]!=1e18){
						if(dp[i][j]!=2e18)dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j]);
						else dp[i][j] = dp[i][k]+dp[i][j];
					}
					
				}
			}

		}
	}
	for(int h = 1;h<=2*n;h++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					if(dp[k][j]!=1e18&&dp[k][i]!=1e18){
						if(dp[i][j]!=2e18)dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j]);
						else dp[i][j] = dp[i][k]+dp[i][j];
					}
					
				}
			}

		}
	}
	for(int h = 1;h<=2*n;h++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					if(dp[k][j]!=1e18&&dp[k][i]!=1e18){
						if(dp[i][j]!=2e18)dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j]);
						else dp[i][j] = dp[i][k]+dp[i][j];
					}
					
				}
			}

		}
	}
	for(int h = 1;h<=2*n;h++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					if(dp[k][j]!=1e18&&dp[k][i]!=1e18){
						if(dp[i][j]!=2e18)dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j]);
						else dp[i][j] = dp[i][k]+dp[i][j];
					}
					
				}
			}

		}
	}	
	for(int h = 1;h<=2*n;h++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					if(dp[k][j]!=1e18&&dp[k][i]!=1e18){
						if(dp[i][j]!=2e18)dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j]);
						else dp[i][j] = dp[i][k]+dp[i][j];
					}
					
				}
			}

		}
	}	
	
	for(int h = 1;h<=2*n;h++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					if(dp[k][j]!=1e18&&dp[k][i]!=1e18){
						if(dp[i][j]!=2e18)dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j]);
						else dp[i][j] = dp[i][k]+dp[i][j];
					}
					
				}
			}

		}
	}	
	for(int h = 1;h<=2*n;h++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					if(dp[k][j]!=1e18&&dp[k][i]!=1e18){
						if(dp[i][j]!=2e18)dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j]);
						else dp[i][j] = dp[i][k]+dp[i][j];
					}
					
				}
			}

		}
	}	
	for(int h = 1;h<=2*n;h++){
		for(int i = 1;i<=n;i++){
			for(int k = 1;k<=n;k++){
				for(int j = 1;j<=n;j++){
					if(dp[k][j]!=1e18&&dp[k][i]!=1e18){
						if(dp[i][j]!=2e18)dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j]);
						else dp[i][j] = dp[i][k]+dp[i][j];
					}
					
				}
			}

		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		long long ans = w[l]+w[r];
		ans+=dp[l][r];
		cout<<ans<<endl;
	}
	return 0;
}
