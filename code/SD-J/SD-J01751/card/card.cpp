#include<bits/stdc++.h>
using namespace std;
long long n,m,k,roundd;
long long a[50010];
long long p[50010];
long long f[50010];
long long num[15010][15010];//poker_round
long long ans[50010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long long r=n; r>=1; r--) {
		k=a[r];//now_poker
		for(long long i=1; i<=m; i++) {
			num[i][r]=num[i][r+1];
		}
		if(p[k]==0) {
			p[k]=r;
			num[k][r]=1;
		} else {
			roundd=p[k];//now_poker_firstround
			for(long long i=1; i<=m; i++) {
				num[i][r]=num[i][roundd];
			}
			num[k][r]=1;
		}
	}
	for(long long i=1; i<=m; i++) {
		for(long long j=1; j<=n; j++) {
			if(num[i][j]) {
				ans[i]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
