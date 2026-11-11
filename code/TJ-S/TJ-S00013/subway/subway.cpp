#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
long long w[500001];
int k[501];
long long a[501][50001],t[501][50001];
bool f[501][500001];
int p[501][500001];
bool vis[501];
long long sum=0,ans=1e18;
long long ok(int i,int j){
	long long z=1e18;
	for(int b=1;b<=k[i];++b){
		for(int e=1;e<=k[j];++e){
			if(a[i][b]==a[j][e]){
				z=min(z,t[i][b]+t[j][e]);
			}
		}
	}
	return z;
}
void dfs(int i){
	if(f[i][y]){
		ans=min(ans,sum+t[i][p[i][y]]);
		return;
	}
	for(int j=1;j<=n;++j){
		long long z=ok(i,j);
		if(!vis[j]&&z!=1e18){
			vis[j]=1;
			sum+=z;
			dfs(j);
			sum-=z;
			vis[j]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
			f[i][a[i][j]]=true;
			p[i][a[i][j]]=j;
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		ans=1e18;
		for(int i=1;i<=n;++i){
			if(f[i][x]){
				sum=w[x]+t[i][p[i][x]]+w[y];
				vis[i]=1;
				dfs(i);
				vis[i]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
