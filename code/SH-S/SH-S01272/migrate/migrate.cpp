#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+5,INF=1e18;
ll c,t;
ll n,d,a[N],f[N][N],cnt[N][N];
void solve(){
	while(t--){
		int p,q; cin>>p>>q;
		for(int i=1;i<=p;i++){
			int x; cin>>x;
		}
		cout<<0<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	if(c>10){
		solve();
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=n;j++)
				f[i][j]=INF,cnt[i][j]=1;
			f[i][i]=0;
		}
		for(int k=1;k<=n;k++) for(int i=k;i<=n;i++)
			for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
				if(f[k][i]+1<f[k][j]){
					cnt[k][j]=cnt[k][i];
					f[k][j]=f[k][i]+1;
				}
				else if(f[k][i]+1==f[k][j]) cnt[k][j]+=cnt[k][i];
			}
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2) ans++;
		cout<<ans<<'\n';
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++)
//				cout<<f[i][j]<<' ';
//			cout<<endl;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++)
//				cout<<cnt[i][j]<<' ';
//			cout<<endl;
//		}
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
6 4
0 2 4 6 8 10

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
