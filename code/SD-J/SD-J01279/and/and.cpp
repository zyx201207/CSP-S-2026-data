#include<bits/stdc++.h>
using namespace std;

int a[200001];
int dp[200001];
bool vis[200001];
int n,m,mmax=0;

void dfs(int p){
	if(p>n){
		int cnt=0,sum=2147483647;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cnt++;
				sum&=a[i];
			}
		}
		if(cnt==m)mmax=max(mmax,sum);
		return;
	}
	dfs(p+1);
	vis[p]=1;
	dfs(p+1);
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=20){
		dfs(1);
		cout << mmax;
		return 0;
	}
	//memset(dp,-0x3f,sizeof(dp));
	dp[0]=2147483647;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout << dp[m];
	
	return 0;
} 
