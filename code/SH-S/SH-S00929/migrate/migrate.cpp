#include <bits/stdc++.h>
using namespace std;
const int MAXN=400;
int n;
long long d,pos[MAXN];
int dis[MAXN][MAXN],f[MAXN][MAXN];
void init(){
	for(int i=0;i<MAXN;++i) pos[i]=0;
	for(int i=0;i<MAXN;++i) for(int j=0;j<MAXN;++j) dis[i][j]=1e9;
	for(int i=0;i<MAXN;++i) for(int j=0;j<MAXN;++j) f[i][j]=-1;
}
int dfs(int l,int r){
	if(l>=r) return 0;
	if(f[l][r]>=0) return f[l][r];
	if(dis[l][r]==1){
		f[l][r]=1;
		return 1;
	}
	if(dis[l][r]==1e9){
		f[l][r]=0;
		return 0;
	}
	f[l][r]=0;
	for(int k=l+1;k<=r-1;++k){
		if(dis[l][k]+dis[k][r]==dis[l][r]){
			f[l][r]+=dfs(l,k)*dfs(k,r);
		}
	}
	if(f[l][r]>=5) f[l][r]=5;
	return f[l][r];
}
void solve(){
	cin >> n >> d;
	int ans=0;
	for(int i=1;i<=n;++i) cin >> pos[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(abs(pos[i]-pos[j])<=d) dis[i][j]=1;
			else dis[i][j]=1e9;
		} 
		dis[i][i]=0;
	}

	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	
	for(int k=0;k<=n;++k){
		for(int i=1;i+k<=n;++i){
			if(dfs(i,i+k)==2){
				ans++;
			}
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	for(int i=1;i<=t;++i){
		init();
		solve();
	}
	
	return 0;
} 
