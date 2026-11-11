#include<bits/stdc++.h>
#define maxn 200010
typedef unsigned int uint;
using namespace std;
uint n,m,dfsans;
uint a[maxn],maxer;
uint dp[maxn];
void dfs(uint i,uint aas,bool st,uint cnt){
	if(i>n){
		if(cnt==m&&st)
			dfsans=max(dfsans,aas);
		return;
	}
	if(!st){
		dfs(i+1u,a[i],1u,1u);
		dfs(i+1u,aas,0u,0u);
	}else{
		dfs(i+1u,aas&a[i],st,cnt+1u);
		dfs(i+1u,aas,st,cnt);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%u%u",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%u",&a[i]);
		maxer=max(maxer,a[i]);
	}
	if(m==1){
		printf("%u",maxer);
		return 0;
	}
	if(n<=10){
		dfs(1u,0u,0u,0u);
		printf("%u",dfsans);
		return 0;
	}
	dp[0]=UINT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	printf("%d",dp[m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
