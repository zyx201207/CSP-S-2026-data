#include<bits/stdc++.h>
using namespace std;

int n,m;
long long dp[2005][2005],a[200005];

long long dfs(int x,int y){
	if(y==0)
		return (1<<30)-1;
	if(x==n+1)
		return 0;
	if(dp[x][y])
		return dp[x][y];
	long long ans=dfs(x+1,y);
	ans=max(ans,dfs(x+1,y-1)&a[x]);
	dp[x][y]=ans;
	return ans;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n<=2000)
		printf("%lld",dfs(1,m));
	else{
		sort(a+1,a+n+1);
		printf("%lld",a[n-m+1]);
	}
	return 0;
}