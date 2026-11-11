#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[200005][200005];
long long n,m,mx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[1][0]=pow(2,9)-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i][j]=max(sum[i-1][j],sum[i-1][j-1]^sum[i-1][j]);
		}
	}
	cout<<sum[n][m];
	return 0;
}

