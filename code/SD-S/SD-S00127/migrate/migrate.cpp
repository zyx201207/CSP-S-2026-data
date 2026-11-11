#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
const int N=1e5+5,MAX=1e18,MIN=-1e18,mod=998244353;
int dist[1005][1005],cnt[1005][1005];
int a[N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt[i][j]=0;
			dist[i][j]=MAX;
		}
		dist[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				dist[i][j]=dist[j][i]=1;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=k+1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					cnt[i][j]=1;
					dist[i][j]=dist[i][k]+dist[k][j];
				}else if(dist[i][j]==dist[i][k]+dist[k][j]){
					cnt[i][j]++;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	IOS
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

