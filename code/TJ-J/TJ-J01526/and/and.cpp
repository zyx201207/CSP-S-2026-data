#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],dp[200005],ans=0;
void dfs(int num,int step){
	if(step==m+1){
		int res=0x7fffffff;
		for(int i=1;i<=m;i++)res&=a[b[i]];
		ans=max(ans,res);
	}
	for(int i=num+1;i<=n;i++){
		b[step]=i;
		dfs(i,step+1);
		b[step]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,1);
	cout<<ans;
	return 0;
} 
