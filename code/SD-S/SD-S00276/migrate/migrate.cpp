#include<bits/stdc++.h>
//#define cerr int
#define int long long
using namespace std;

const int N=2e6+10;
int a[N];
int n, m, ans, ID, D;

void fastio(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
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
namespace bf1{
	const int Max=3e2+10, INF=1e18;
	int g[Max][Max], cnt[Max][Max];
	void main(){
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				g[i][j]=INF, cnt[i][j]=0;
		for(int i=0; i<=n; i++) g[i][i]=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<i; j++){
				if(abs(a[i]-a[j])<=D)
					g[i][j]=g[j][i]=1, cnt[i][j]=cnt[j][i]=1;
			}
		}
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(g[i][k]+g[k][j]<g[i][j]){
						g[i][j]=g[i][k]+g[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
						if(cnt[i][j]>2) cnt[i][j]=1000;
					}
					else if(g[i][k]+g[k][j]==g[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
						if(cnt[i][j]>2) cnt[i][j]=1000;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<i; j++){
				if(cnt[i][j]==2) ans++;
//				cerr<<i<<" "<<j<<" : "<<g[i][j]<<" "<<cnt[i][j]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}
inline void Init(){ans=0;}
void solve(){
	cin>>n>>D;
	Init();
	for(int i=1; i<=n; i++) cin>>a[i];
	return bf1::main();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	fastio();
	int t; cin>>ID>>t;
	while(t--) solve();
	return 0;
}
