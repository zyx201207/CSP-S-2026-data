#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
int c,n,m,d,q,f[N][N],w[M],k[N];
vector<int>a[N],t[N],g[M];
unordered_map<int,int>mp[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i],a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			g[x].push_back(i);
			mp[i][x]=y;
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int x=1;x<=n;x++){
		for(int j=1;j<=k[x];j++){
			int y=a[x][j];
			for(int z:g[y]){
				if(z==x)continue;
				f[x][z]=min(f[x][z],mp[x][y]+mp[z][y]);
				f[z][x]=f[x][z];
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y,re=1e18;cin>>x>>y;
		for(int i:g[x])for(int j:g[y])
			re=min(re,mp[i][x]+mp[j][y]+f[i][j]);
		cout<<re+w[x]+w[y]<<'\n';
	}
	return 0;
}