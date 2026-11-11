#include<bits/stdc++.h>
using namespace std;
//long long dp[20005][2005]={};
long long l[200005]={};
long long n,m,mx=0,aaa=LLONG_MAX,sm;
//void dfs(long long start,long long num,long long a){
//	if(a>=m){
//		num=aaa;
//	}
//	if(a==0){
//		mx=max(mx,num);
//		return;
//	}
//	if(dp[
//	else{
//		cout<<l[start]<<'&'<<num<<' ';
//		cout<<'\n';
//		dp[start][a]=max(num,dp[start][a]);
//		dfs(start+1,(l[start]&num),a+1);
//		if(start+a<=m){
//			dfs(start+1,num,a+1);start][a]!=0 and 0){
//		mx=max(mx,(num&dp[start][a]));
//	}
//		}
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&l[i]);
	}
	do{
		sm=l[1];
		for(long long i=2;i<=m;i++){
			sm&=l[i];
		}
		mx=max(mx,sm);
	}while(next_permutation(l+1,l+n+1));
	//sort(l+1,l+n+1);
	//dfs(1,aaa,0);
	cout<<mx;
	return 0;
}
