#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long dp[N][N];
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=min(m,i);j>=1;j--){
			for(int z=1;z<=n;z++){
				if(z==i) continue;
				dp[j][i]=max(dp[j][i],(a[i]&dp[j-1][z]));
			}
		}
	}
	long long maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dp[m][i]);
	}
	cout<<maxn;
	return 0;
}