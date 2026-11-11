#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],son[500005][25],top[500005],k,x,y,we[500005][25];
long long f[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			top[x]++;
			son[x][top[x]]=i;
			we[x][top[x]]=y;
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=top[i];j++){
			f[son[i][j]][son[i][j]]=0;
			for(int kk=j+1;kk<=top[i];kk++){
				f[son[i][j]][son[i][kk]]=min(f[son[i][j]][son[i][kk]],1ll*we[i][j]+we[i][kk]);
				f[son[i][kk]][son[i][j]]=min(f[son[i][kk]][son[i][j]],1ll*we[i][j]+we[i][kk]);
			}
		}
	}
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		long long ans=1e18;
		for(int j=1;j<=top[x];j++){
			for(int kk=1;kk<=top[y];kk++){
				ans=min(ans,1ll*we[x][j]+we[y][kk]+f[son[x][j]][son[y][kk]]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

