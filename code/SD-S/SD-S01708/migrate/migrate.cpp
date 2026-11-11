#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long a[N];
long long f[N][N];//从i-j的最短路径有多长
long long dp[N][N];//最短路的方法数量
long long n,d;
void fix(int l,int r){//求最短路 
	for(int k=l;k<=r;++k){
		//l-i -> l-r
		if(a[r]-a[k]<=d){
			if(f[l][r]==0)f[l][r]=f[l][k]+1;
			else f[l][r]=min(f[l][r],f[l][k]+1);
		}

	}
	return ;
} 
bool fix2(int l,int r){
	for(int k=l;k<=r;++k){
		//l-i -> l-r
		if(a[r]-a[k]<=d){
			if(f[l][k]+1==f[l][r]){
				dp[l][r]+=(dp[l][k]);
			}
		}
	}
	return dp[l][r]==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(dp,0,sizeof(dp));
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			dp[i][i]=1;
		}
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				fix(i,j);
				if(fix2(i,j)){
					ans++;
				}
			//	cout<<i<<" "<<j<<": 最短："<<f[i][j]<<" 方法："<<dp[i][j]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
