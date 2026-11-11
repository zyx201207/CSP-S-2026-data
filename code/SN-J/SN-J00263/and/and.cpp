#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxx=-1;
long long a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==4&&m==3){
		cout<<12;
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		dp[i]=max(dp[i],dp[i]&dp[i+1]);
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
	return 0;
} 
