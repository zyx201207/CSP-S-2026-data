#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5005,M=305;
int n,d;
int x[N];
vector<int> g[N];
int dist[N],sum[N];
int e[M][M],cnt[M][M];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=1e18;
			cnt[i][j]=0;
		}
	}
}
void floyed(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(e[i][k]+e[k][j]<e[i][j])
					e[i][j]=e[i][k]+e[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
				else if(e[i][k]+e[k][j]==e[i][j])
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
			}
				
}
void solve(){
	cin>>n>>d;
	init();
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				e[i][j]=1,cnt[i][j]=1;
				e[j][i]=1,cnt[j][i]=1;
			}
		}
	}
	floyed();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<'\n';	
				
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
