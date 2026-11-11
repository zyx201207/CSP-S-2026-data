#include<bits/stdc++.h>
using namespace std;
int ans[300005];
int dp[500005];
int a[500005];
int b[300005];
int n,m,x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=i;
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		dp[b[a[i]]+1]+=dp[i];
		ans[a[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}