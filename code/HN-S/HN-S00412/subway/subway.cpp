#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,q,tmp,z[M],p[M][21],g[M][21],s[M];
ll f[N][N],ans;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>tmp>>q;
	for(int i=1;i<=m;++i)cin>>z[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int d;
			cin>>d;
			p[d][++s[d]]=i;
			cin>>g[d][s[d]];
		}
		for(int j=1;j<=n;++j)f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<s[i];++j){
			for(int k=j+1;k<=s[i];++k){
				f[p[i][j]][p[i][k]]=f[p[i][k]][p[i][j]]=min(f[p[i][j]][p[i][k]],(ll)g[i][j]+g[i][k]);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(int j=1;j<=s[x];++j){
			for(int k=1;k<=s[y];++k){
				ans=min(ans,f[p[x][j]][p[y][k]]+g[x][j]+g[y][k]+z[x]+z[y]);
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}
