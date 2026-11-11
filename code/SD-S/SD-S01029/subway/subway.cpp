#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y,w[500007],k[507],aa,tt,f[507][507],ans,a[500007][22],bh[500007][22],cnt[500007];//1-index
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	d=min(n,d);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		f[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>aa>>tt;
			a[aa][++cnt[aa]]=tt;
			bh[aa][cnt[aa]]=i;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=cnt[i];++j){
			for(int l=j+1;l<=cnt[i];++l){
				f[bh[i][l]][bh[i][j]]=f[bh[i][j]][bh[i][l]]=min(f[bh[i][j]][bh[i][l]],a[i][j]+a[i][l]);
			}
		}
	}
	for(int kk=1;kk<=n;++kk){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3fll;
		for(int i=1;i<=cnt[x];++i){
			for(int j=1;j<=cnt[y];++j){
				ans=min(ans,a[x][i]+f[bh[x][i]][bh[y][j]]+a[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;//ίχ 
}//16:49
