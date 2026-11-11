#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010];
int dp[5010][5010];
int f[5010][5010];
int c,T,n,m;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=0,f[i][j]=0x3f3f3f;
		for(int i=1;i<=n;i++)
			dp[i][i]=1,f[i][i]=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int k=j;
				while(k>=i && a[j]-a[k]<=m)
					k--;
				k++;
				int minn=f[i][k]+1;
				f[i][j]=minn;
				int l=k;
				while(l<=j && f[i][l]+1==minn)
					dp[i][j]+=dp[i][l],l++;
			}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dp[i][j]==2)  ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2

5 3

-2 -1 0 1 2

6 2

-4 -3 -2 -1 3 6

0 2

4 2

1 2 3 4

5 2

1 2 3 4 5
40pts
*/
