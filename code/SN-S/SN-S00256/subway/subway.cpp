#include<iostream>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,cnt[N],w[N],num[N][25],t[N][25],f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=1e15;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		f[i][i]=0;
		for(int j=1,a,ti;j<=k;j++){
			cin>>a>>ti;
			num[a][++cnt[a]]=i;
			t[a][cnt[a]]=ti;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				int u=num[i][j],v=num[i][k];
				f[u][v]=f[v][u]=min(f[u][v],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		int ans=1e18;
		cin>>x>>y;
		for(int j=1;j<=cnt[x];j++){
			for(int k=1;k<=cnt[y];k++){
				int u=num[x][j],v=num[y][k];
				ans=min(ans,f[u][v]+t[x][j]+t[y][k]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
