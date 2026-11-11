#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[100010],dp[5001][5001],num[5001][5001];
void dfs(int u,int st,int cnt,int l,int n){
	dp[u][st]=dp[st][u];
	if(cnt>dp[st][u])return;
	if(dp[st][u]>cnt)dp[st][u]=cnt,num[st][u]=0;dp[u][u]=1;num[st][u]++;
	
	if(u>=n)return;
	int j=u;
	while(abs(a[j+1]-a[u])<=l&&j+1<=n){j++;
		dfs(j,st,cnt+1,l,n);
	}return;
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
	memset(num,0,sizeof num);
		int n,l;
		cin>>n>>l;
//		a[0]=-5e18;
		memset(dp,0x3f,sizeof dp);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++)dfs(i,i,0,l,n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(num[i][j]==2)ans++;
			}
		}
	cout<<ans<<'\n';
	
	}
		 
	return 0;
}


