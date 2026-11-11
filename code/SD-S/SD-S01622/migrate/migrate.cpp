#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int c,t,n,d,x[N],cnt[N][N],dis[N][N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		int ans=0;
		cin>>n>>d;
		memset(dis,0x3f,sizeof d);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++) {
			cin>>x[i];
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(abs(x[i]-x[j])<=d) dis[i][j]=abs(x[i]-x[j]);
				cnt[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++) {
			for(int i=1;i<=n;i++) {
				for(int j=i+1;j<=n;j++) {
					if(dis[i][j]==dis[i][k]+dis[k][j]) {
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
					else if(dis[i][k]+dis[k][j]<dis[i][j]) {
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
//				cout<<cnt[i][j]<<' ';
				if(cnt[i][j]==2) {
					ans++;
				}
			}
		}
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
*/
