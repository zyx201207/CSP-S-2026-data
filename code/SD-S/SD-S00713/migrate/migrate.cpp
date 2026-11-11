/*
走了那么久，难道又回头吗 ——《依·抱》
All for myself, not anyone else.
*/
/*
前6个测试点n^3能过，floyd可得 
前10个测试点需要n^2，暂时还想不到 
先写着部分分
24pts got
性质是个什么玩意 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define TERRY_MC
#define endl '\n'
const int N=310;
int c,n,t;
ll d,dis[N][N],cnt[N][N],x[N];
void solve() {
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	cin>>n>>d;
	for(int i=1;i<=n;i++) {
		cin>>x[i];
		dis[i][i]=0;
		cnt[i][i]=1;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<i;j++) {
			dis[i][j]=dis[j][i]=(abs(x[i]-x[j])<=d)?1:0x3f3f3f3f3f3f3f3f;
			cnt[i][j]=cnt[j][i]=(abs(x[i]-x[j])<=d)?1:0;
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i==k||i==j||j==k) continue;
				if(dis[i][j]==dis[i][k]+dis[k][j])
					cnt[i][j]++;
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<i;j++) {
			if(cnt[j][i]==2) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main() {
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#ifndef TERRY_MC
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	cin>>c>>t;
	while(t--) {
		solve();
	}
	return 0;
}

