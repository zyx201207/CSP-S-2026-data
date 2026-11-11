#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[510],b,cc,f[510][500010],h[500010][30],cnt[500010];	
long long a[500010],g[510][510];
int main(){		
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);						
	cin>>c>>n>>m>>d>>q;									
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b>>cc;
			f[i][b]=cc;
			h[b][++cnt[b]]=i;
		}
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j){
				g[i][j]=0;
				continue;
			}
			for(int l=1;l<=m;l++)
				if(f[i][l]&&f[j][l]) g[i][j]=min(g[i][j],(long long)f[i][l]+f[j][l]);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j){
				g[i][j]=0;
				continue;
			}
			for(int l=1;l<=n;l++) g[i][j]=min(g[i][l]+g[j][l],g[i][j]);
		}
	while(q--){
		int x,y;
		long long ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++)
			for(int j=1;j<=cnt[y];j++) ans=min(ans,(long long)a[x]+f[h[x][i]][x]+f[h[y][j]][y]+a[y]+g[h[x][i]][h[y][j]]);
		cout<<ans<<endl;
	}
	return 0;
}