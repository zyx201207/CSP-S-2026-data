#include<bits/stdc++.h>
using namespace std;
int dp[301][301];
int a[10001],n,k,xx;
void dfs(int x,int y,int cnt){
	dp[cnt][x]=a[y];
	if(y>=n-1){
		xx=x;
		return;
	}
	for(int i=y+1;i<n;i++){
		if(a[i]-a[y]>k)return;
		dfs(x+i-y,i,0+i-y);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,ccc;
	cin>>ccc>>t;
	while(t--){
		int ans=0;
		cin>>n>>k;
		for(int i=0;i<n;i++)cin>>a[i];
		int cnt=0;
		dfs(0,0,cnt);
		for(int i=0;i<xx;i++){
			map<int,int> mp;
			for(int j=0;j<n;j++){
				if(mp[dp[i][j]]==0)mp[dp[i][j]]++;
				else{
					if(dp[i][j])ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
