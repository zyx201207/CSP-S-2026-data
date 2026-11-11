#include<bits/stdc++.h>
using namespace std;
long long n,m;
unsigned long long a[200007],dp[200007];
bool vis[200007] ;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		dp[0]=(unsigned long long)2e31;
	}
//	cout<<dp[0]<<endl; 2
	int pos=0,npos=0;
	for(int j=1; j<=m; j++) {
		for(int i=n; i>=1; i--) {
			if(vis[i]==1) {
				continue;
			}
			if((dp[j-1]&a[i])>=dp[j]) {
				dp[j]=dp[j-1]&a[i];
				pos=i;
			}
		}
		vis[pos]=1;
	}
	cout<<dp[m];
	return 0;
}
