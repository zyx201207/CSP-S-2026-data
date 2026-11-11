#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){int x = 0,zt = 1;char ch = getchar();while(ch<48||ch>57){if(ch==45)zt = -1;ch = getchar();}while(48<=ch&&ch<=57){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}return x*zt;}
const int N = 5e2 + 10,M = 5e5 + 10;
int n,m,ans,sum,w[M],f[N][N];
vector<pair<int,int>>v[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();n = read();m = read();read();int q = read();
	for(int i=1;i<=m;i++)w[i] = read();
	memset(f,63,sizeof f);
	for(int i=1;i<=n;i++){
		f[i][i] = 0;
		int x = read();
		for(int j=1;j<=x;j++){
			int y = read(),z = read();
			v[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<v[i].size();j++)
			for(int k=j+1;k<v[i].size();k++){
				auto&[x,z1] = v[i][j];
				auto&[y,z2] = v[i][k];
				f[x][y] = f[y][x] = min(f[x][y],z1+z2);
			}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x = read(),y = read(),ans = 1e18;
		for(auto&[i,j]:v[x])for(auto&[q,p]:v[y])
			ans = min(ans,f[i][q]+j+p+w[x]+w[y]);
		cout<<ans<<'\n';
	}
	return 0;
}