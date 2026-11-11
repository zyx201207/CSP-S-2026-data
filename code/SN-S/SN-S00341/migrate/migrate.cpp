// 袁梓焜 西安交通大学附属中学 SN-S00341
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int dis[N][N];
int n,d;
int a[N];

inline void sol() {
	cin>>n>>d;
	for(int i=1; i<=n; i++) cin>>a[i];
	memset(dis,0,sizeof dis);
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			int k=i;
			while(a[j]-a[k]>d) k++;
			dis[i][j]=dis[i][k]+1;
		}
	}
	int ans=0;
//	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<dis[i][j]<<" \n"[j==n];
	for(int i=1; i<=n; i++) {
		for(int j=i+2,cnt=0; j<=n; j++,cnt=0) {
			for(int k=i+1; k<j; k++) {
				if(dis[i][k]&&dis[k][j]&&dis[i][j]&&dis[i][j]==dis[i][k]+dis[k][j]) cnt++;
			}
			if(cnt==dis[i][j]) ans++;
		}
	}
	cout<<ans<<'\n';
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) sol();
}
/*
0 1
8 3
0 1 2 4 8 10 11 13

*/
