#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],nxt[500002],dp[500002];
int vis[300002],cnt[300002];
int main(){
	ifstream cin("card.in");
	ofstream cout("card.out");
	cin>>n>>m;
	for(int i=0;i<n+2;i++)dp[i]=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--){
		if(vis[a[i]]==0){
			vis[a[i]]=i;
			nxt[i]=-1;
		}else{
			nxt[i]=vis[a[i]];
		}
	}
	for(int i=0;i<n;i++){
		if(nxt[i]!=-1){
			dp[nxt[i]]+=dp[i];
		}else{
			cnt[a[i]]=dp[i];
			dp[i+1]+=dp[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
