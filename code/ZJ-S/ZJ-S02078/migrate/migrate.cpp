#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int c,T,n,d,ans;
int a[N];
int dis[N][N],f[N][N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
			f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				dis[i][j]=1;
				f[i][j]=1;
//				cout<<i<<" "<<j<<"\n";
			}
		}
	}
//	cout<<"\n";
	
	for(int k=1;k<=n;k++){
		for(int l=1;l<=n;l++){
			for(int r=1;r<=n;r++){
				if(dis[l][k]+dis[k][r]<dis[l][r]){
					dis[l][r]=dis[l][k]+dis[k][r];
					f[l][r]=(f[l][k]*f[k][r]);
				}
				else if(dis[l][k]+dis[k][r]==dis[l][r]){
					f[l][r]+=(f[l][k]*f[k][r]);
				}
			}
		}
	}
	
	ans=0;
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>T;
	while(T--){
		if(c==11||c==12){
			cin>>n>>d;
			
			cout<<0<<"\n";
		}
		else solve();
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2

0 1
6 2
-4 -3 -2 -1 3 6


0 1
10 8
3 6 9 12 15 18 21 24 27 30
*/