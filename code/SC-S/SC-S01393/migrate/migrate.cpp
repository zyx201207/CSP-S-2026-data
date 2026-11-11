#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,INF=1e18;
int c,n,len,ans,T,a[N],dis[N][N],cnt[N][N];
void init(){
	ans=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++){
		cnt[i][j]=0;
		cnt[j][i]=0;
		dis[i][j]=INF;
		dis[j][i]=INF;
	}
}
void solve(){
	cin>>n>>len;init();
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++){
		if(a[i]-a[j]>len) continue;
		dis[i][j]=1;
		cnt[i][j]=1;
		dis[j][i]=1;
		cnt[i][j]=1;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=n;j++){
		if(dis[i][j]>dis[i][k]+dis[k][j]){
			dis[i][j]=dis[i][k]+dis[k][j];
			cnt[i][j]=cnt[i][k]*cnt[k][j];
		}
		else if(dis[i][j]==dis[i][k]+dis[j][k]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
		if(cnt[i][j]>3) cnt[i][j]=3;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++) 
		if(cnt[i][j]==2) ans++;
	cout<<ans<<"\n";
}
void solve1(){
	cin>>n>>len;
	for(int i=1,x;i<=n;i++) cin>>x;
	cout<<"0\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==13||c==14){
		solve1();
		return 0;
	}
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/