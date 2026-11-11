#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5000,L=505;
int c,n,m,d,q,w[N];ll f[L][L];
int a[N][21],t[N][21],cnt[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1,k,aa,tt;i<=n;++i){
		cin>>k;
		while(k--){
			cin>>aa>>tt;
			cnt[aa]++;
			a[aa][cnt[aa]]=i;
			t[aa][cnt[aa]]=tt;
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=cnt[i];++j)
			for(int k=j+1;k<=cnt[i];++k)
				f[a[i][j]][a[i][k]]=f[a[i][k]][a[i][j]]=
				min(f[a[i][j]][a[i][k]],1ll*t[i][j]+t[i][k]);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)if(i!=k)
			for(int j=1;j<=n;++j)if(j!=k&&j!=i)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)printf("%d %d %lld\n",i,j,f[i][j]);
//	}
	while(q--){
		int u,v;ll res=1e18;
		cin>>u>>v;
		for(int i=1;i<=cnt[u];++i)
			for(int j=1;j<=cnt[v];++j)
				res=min(res,t[u][i]+t[v][j]+f[a[u][i]][a[v][j]]);
		cout<<res+w[u]+w[v]<<'\n';
	}
	return 0;
}
//O(nm)大概是2e8，希望能过吧，应该是76~100，只能相信ccf的数据强度了