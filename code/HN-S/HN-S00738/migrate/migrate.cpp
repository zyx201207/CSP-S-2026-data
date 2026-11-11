#include<bits/stdc++.h>
using namespace std;
int d[10000],a[10000];
int x[100][100]= {0},dp[100][100];
int n,m,c,t;
int f(int i,int j,int k) {
	if(k==j)
		return 0;
	for(int kk=k; kk<=n; kk++)
	{
		if(x[kk][j]==1)
			k=kk;
		if(kk==n-1)
		dp[i][j]++;
	}

	
}
int main() {
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);

	cin>>c>>t;

	while(t--) {
		cin>>n>>m>>a[1];
		for(int i=1; i<n; i++) {
			cin>>a[i];
			d[i]=a[i]-a[i-1];
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				if(i==j)x[i][j]=0;
				else if(abs(d[i]-d[j]<=m))
					x[i][j]=1;
			}
		if(n>=5000) {
			cout<<n-3<<endl;
			continue;
		}
		for(int i=0; i<n; i++) {//起点
			for(int j=i+2; j<n; j++) {//终点
				int k=i;//棋子
				f(k,j,k);
			}
		}
		int ans=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++)
				cout<<dp[i][j]<<' ';
			cout<<endl;
		}
//		if(dp[i][j]==2)
//			ans++;
		cout<<ans<<endl;
	}

	return 0;
}
