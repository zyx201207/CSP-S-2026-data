#include<bits/stdc++.h>
# define N 500005
# define M 300005
using namespace std;
int n,m;
int a[N];
int dp[N];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int j=i+1;
		while(a[j]!=a[i]&&j<=n)j++;
		dp[i]=j;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dp[j]<=n)j=dp[j]-1;
			else{
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
	return 0;
}

