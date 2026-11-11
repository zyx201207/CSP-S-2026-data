#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],n,m;
int last[M],ans[M],pre[N],cnt[M];
int dp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i]=last[a[i]];
	}
	for(int k=1;k<=n;k++){
		int i=k;
		while(i<=n){
			ans[a[i]]++;
			if(dp[i]==0)i++;
			else i=dp[i]+1;
		}
		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	
}
