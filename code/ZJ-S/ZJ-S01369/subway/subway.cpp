#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],cnt[500010];
long long f[510][510];
struct nm{
	long long v,w;
}mp[22][500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;cin>>v>>w;
			mp[++cnt[v]][v]={i,w};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=1e18;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<cnt[i];j++){
			for(int x=j+1;x<=cnt[i];x++){
				f[mp[j][i].v][mp[x][i].v]=min(f[mp[j][i].v][mp[x][i].v],mp[j][i].w+mp[x][i].w);
				f[mp[x][i].v][mp[j][i].v]=f[mp[j][i].v][mp[x][i].v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					f[i][j]=0;
					continue;
				}
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int l,r;cin>>l>>r;
		long long ans=1e18;
		for(int i=1;i<=cnt[l];i++){
			for(int j=1;j<=cnt[r];j++){
				ans=min(ans,mp[i][l].w+mp[j][r].w+f[mp[i][l].v][mp[j][r].v]);
			}
		}
		cout<<ans+w[l]+w[r]<<"\n";
	}
	return 0;
}