#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
const int inf=1e18;
int n,D;
int a[N];
int nxt[N];
int d[N][N];
void solve(){
	cin>>n>>D;
	for(int i=1;i<=n;i++) cin>>a[i];
	int r=1;
	for(int l=1;l<=n;l++){
		while(r<n&&a[r+1]-a[l]<=D) ++r;
		nxt[l]=r;
	}
	for(int l=1;l<=n;l++){
		if(nxt[l]==l){
			for(int r=l+1;r<=n;r++) d[l][r]=inf;
		}
		int dis=0;
		int R=l;
		for(int r=l+1;r<=n;r++){
			while(r>R){
				if(nxt[R]==R){
					dis=inf;
					break;
				}
				++dis,R=nxt[R];	
			}
			d[l][r]=dis;
		}
	}
	int ans=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cerr<<d[i][j]<<' ';
//		}
//		cerr<<'\n';
//	}
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			if(d[l][r]>=inf) break;
			int flg=0,lst=-1,dis=d[l][r];
			for(int k=l;k<=r;k++){
				if(d[l][k]+d[k][r]>dis) continue;
				if(d[l][k]==lst) ++flg;
				lst=d[l][k];
			}
			if(flg==1) ++ans;
		}
	}
	cout<<ans<<'\n';
}
void clear(){
	for(int i=1;i<=n;i++){
		a[i]=0,nxt[i]=0;
		for(int j=1;j<=n;j++){
			d[i][j]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Case;cin>>Case;
	int T;cin>>T;
	while(T--){
		solve();
		clear();
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/

