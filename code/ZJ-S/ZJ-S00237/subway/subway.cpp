#include<bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5e2+10;
int c,n,m,d,q;
int w[N*N*2];
long long f[N][N];
vector<int> vis[N*N*2];
int W[N*N*2][21];
signed main(){
	FIO
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) {
		int s;cin>>s;
		for(int j=1;j<=s;j++){
			int a,t;cin>>a>>t;
			for(int z=0;z<vis[a].size();z++){
				f[vis[a][z]][i]=min(f[vis[a][z]][i],(long long)(W[a][z]+t));
				f[i][vis[a][z]]=min(f[i][vis[a][z]],(long long)(W[a][z]+t));
			}
			W[a][vis[a].size()]=t;
			vis[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int z=1;z<=n;z++)
				f[j][z]=min(f[j][z],f[j][i]+f[i][z]);
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=LLONG_MAX;
		int w_x=0,w_y=0;
		for(int i=0;i<vis[x].size();i++)
			for(int j=0;j<vis[y].size();j++)
				if(ans>f[vis[x][i]][vis[y][i]])
					ans=f[vis[x][i]][vis[y][i]],w_x=W[x][i],w_y=W[y][j];
		cout<<ans+w[x]+w[y]+w_x+w_y<<'\n';
	}
	return 0;
}