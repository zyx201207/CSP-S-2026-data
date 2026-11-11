#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,d;
long long w[20004],k[505],x,y;
vector<long long> sub[20004];
long long t[20004][505];
long long dp[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f3f3f3f,sizeof dp);
	for(int i=0;i<=500;i++){
		dp[i][i]=0;
	}
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long z;cin>>z;
			cin>>t[z][i];
			sub[z].push_back(i);
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<sub[i].size();j++){
			for(long long l=0;l<sub[i].size();l++){
				dp[sub[i][j]][sub[i][l]]=min(dp[sub[i][j]][sub[i][l]],t[i][sub[i][j]]+t[i][sub[i][l]]);
				dp[sub[i][l]][sub[i][j]]=dp[sub[i][j]][sub[i][l]];
			}
		}
	}
	for(long long o=1;o<=1;o++){
		for(long long i=1;i<n;i++){
			for(long long j=1;j<=n;j++){
				for(long long l=1;l<=n;l++){
					if(l==i||l==j||i==j) continue;
					dp[i][j]=min(dp[i][j],dp[i][l]+dp[j][l]);
					dp[j][i]=min(dp[j][i],dp[i][l]+dp[j][l]);
				}
			}
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;
		long long min1=1e18;
		for(long long j=0;j<sub[x].size();j++){
			for(long long l=0;l<sub[y].size();l++){
				min1=min(min1,w[x]+w[y]+dp[sub[x][j]][sub[y][l]]+t[x][sub[x][j]]+t[y][sub[y][l]]);
			}
		}
		cout<<min1<<endl;
	}
	return 0;
}

