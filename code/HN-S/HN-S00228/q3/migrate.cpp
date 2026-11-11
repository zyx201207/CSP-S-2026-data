#include<bits/stdc++.h>
using namespace std;
const int N = 2e4;
int dp[N][N],x[N], y[N];
int c, t, n, d,maxx;
int change(int f){
	return x[n]-f;
}
int bestL(int f){
	int  res = lower_bound(x+1, x+1+n, x[f]-d)-x;
	if(res!=n+1 && x[res]<=x[f]+d){
		return res;
	}
	return 0;
}
int bestR(int f){
	int target = x[f]+d;
	int l = f,r = n, mid = 1;
	while(l<r){
		mid = (l+r)>>1;
		if(x[mid]<=target){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	mid = (l+r)>>1;
	if(x[f]<=x[mid]&&x[mid]<=target) return mid;
	return 0;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate1.in","r", stdin);
	//freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			cin>>x[i];
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 1;i <= n;i++) dp[i][i] = 0;//先计算步数 
		for(int i = 1;i <= n;i++){
			for(int j = bestL(i);j <= bestR(i);j++){
				dp[i][j]=1;
			}
		}
		for(int len = 2;len<=n;len++){
			for(int i = 1;i<= len-i+1;i++){
				for(int j = i+1;j <= i+len-1;j++){
					if(x[j]-x!=) dp[i][j] = dp[i][j]+dp[j][i+len-1]+;
				}
			} 
		}
		/*
		for(int i = 1;i <= n;i++){
			for(int j =  1;j <= n;j++)
				dp[i][j] = 1;
		}
		for(int i = 1;i <= n;i++){
			int l = , r = bestR(i);
			if(i-l>=2){
				dp[i][l] = 0;
				dp[l][i] = 0;
			}
			if(r-i>=2){
				dp[i][r] = 0;
				dp[r][i] = 0;
			}
		}*/
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				ans+=(dp[i][j]==2)*(i!=j);
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
} 
