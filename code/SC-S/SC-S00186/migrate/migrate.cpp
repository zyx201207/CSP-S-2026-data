#include<bits/stdc++.h>
using namespace std;

const int N=2000; 
int n,d,x[N],ans;
int dp[N][N];

inline int check(int i,int j) {
	int res=0;
	if(x[j]-x[j-1]>d) return 0;
	for(int k=i+1;k<j;k++) {
		if(dp[i][k]+dp[k][j]==dp[i][j]) {
			++res;
		}
	}
	return res;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int C,T; cin>>C>>T;
	while(T--) {
		cin>>n>>d;
		bool fy[n+1][n+1];
		for(int i=1;i<=n;i++) {
			cin>>x[i];
			fy[i][i]=1;
		}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++) {
				if(x[j]-x[i]<=d) fy[i][j]=1,dp[i][j]=1;
				else fy[i][j]=0,dp[i][j]=j-i;
			}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=k;i++)
				for(int j=k;j<=n;j++) {
					if(fy[i][k]&&fy[k][j])
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++) {
				if(fy[i][j]||i==j) continue;
				if(check(i,j)==2)
					++ans;
			}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}