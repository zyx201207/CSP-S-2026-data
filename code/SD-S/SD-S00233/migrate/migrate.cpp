#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
const int N=5e3+10;
int c,t,a[N],d[N][N],n,dd,s[N][N];
void dfs(int k,int u,int sm){
	d[k][u]=min(d[k][u],sm);
	int l=u+1,r=n;
	for(int i=u+1;i<=n;++i){
		if(a[i]-a[u]>dd)break;
		dfs(k,i,sm+1);
	}
}
void dfs_2(int k,int u,int sm){
	if(sm==d[k][u])s[k][u]++;
	int l=u+1,r=n;
	for(int i=u+1;i<=n;++i){
		if(a[i]-a[u]>dd)break;
		dfs_2(k,i,sm+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--){
		n,d;cin>>n>>dd;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)d[i][i]=0;
				else d[i][j]=INF;
				s[i][j]=0;
			}
		}
		for(int i=1;i<=n;++i)dfs(i,i,0);
		for(int i=1;i<=n;++i)dfs_2	(i,i,0);
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j&&s[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
