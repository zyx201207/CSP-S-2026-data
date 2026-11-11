#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5005;
int n;
int m;
int a[N];
int dp[N][N];
int ans;
inline void dfs(int now,int cnt,int res){
	if(res<ans)return;
	if(cnt==m){
		ans=max(ans,res);
		return;
	}
	if(now>n)return;
	for(int i=now+1;i<=n;i++){
//		cout<<res<<' ';
		dfs(i,cnt+1,res&a[i]);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(0,0,2147483647);
		cout<<ans;
	}
	else if(m==2){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	else if(n<=5005){
		for(int i=1;i<=n;i++)dp[i][1]=a[i];
	for(int i=2;i<=n;i++){
		for(int k=2;k<=min(i,m);k++){
			for(int j=1;j<i;j++){
				dp[i][k]=max(dp[i][k],dp[j][k-1]&a[i]);
		//		cout<<dp[i][k]<<' ';
			}
	//		cout<<endl;
		}
//		cout<<endl;
	}
	for(int i=1;i<=n;i++)ans=max(ans,dp[i][m]);
	cout<<ans;
	}
	else{
		sort(a+1,a+1+n);
		ans=a[1];
		for(int i=2;i<=m;i++)ans&=a[i];
		cout<<ans;
	}
	return 0;
}
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/
