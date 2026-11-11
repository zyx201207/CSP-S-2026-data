#include<bits/stdc++.h>
using namespace std;
int n,d;
int dp[10][10][10000];
int mi[10][10];
int a[10];
int s;
void dfs(int id,int step){
	if(id!=s){
		dp[s][id][step]++;
		mi[s][id]=min(step,mi[s][id]);
	}
	for(int i=id+1;i<=n;i++){
		if((a[i]-a[id])<=d){
			dfs(i,step+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++){
				mi[i][j]=10000000;
			}
		}
		for(s=1;s<=n;s++){
			dfs(s,0);
			for(int j=s+1;j<=n;j++){
				if(dp[s][j][mi[s][j]]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}