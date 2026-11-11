#include<bits/stdc++.h>
using namespace std;
int dp[200010],n,m,a[200010];
int vis[200010];
int Max=-1e9;
void dfs(int d,int now){
//	cout<<d<<' '<<now<<' '<<endl;
/*	for (int i=1;i<=n;++i)
		cout<<vis[i]<<" ";
	cout<<endl<<endl;*/
	if (d==m){
		Max=max(now,Max);
		return;
	}
	for (int i=1;i<=n;i++){
		if (d==0) {
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
		else if (!vis[i]){
			vis[i]=1;
			dfs(d+1,now&a[i]);		
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	if (m==n) {
		int ans=a[1];
		for (int i=2;i<=n;++i){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if (m==1) {
		sort(a+1,a+1+n,greater<int>());
		cout<<a[1];
		return 0;	
	}
	if (m<20) {
		dfs(0,0);
		cout<<Max;
		return 0;
	}
	if (m==n-1){
		int ans=0;
		for (int i=1;i<=n;i++){
			int now;
			if (i==1) {
				now=a[2];
			}
			else {
				now=a[1];
			}
			for (int j=1;j<=n;j++){
				if (i==j) continue;
				now=now&a[j];
			}
			//cout<<now<<endl;
			ans=max(ans,now);
		}
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;++i){
		for (int j=m;j>=1;j--){
			if (j!=1) dp[j]=max(dp[j],(dp[j-1]&a[i]));
			else dp[1]=max(dp[1],a[i]);	
		}
	}
	cout<<dp[m];
	return 0;
}
