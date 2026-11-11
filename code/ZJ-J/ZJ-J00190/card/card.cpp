#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[500005],to[500005],dp[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		lst[a[i]]=i;
		dp[i]=1;
	}
	for(int i=1;i<=n;++i){
		to[i]=lst[a[i]]+1;
	}
	for(int i=1;i<=n;++i){
		ans[a[i]]+=dp[i];
		dp[to[i]]+=dp[i];
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}