#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9;
const int M=509;
const int D=29;
const ll INF=1e18;
ll c,n,m,d,q,w[N],dst[M][M];
//n:线路 m:站台 
ll a[N][D],t[N][D];//每一个站台的线路和时间
ll cnt[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;cin>>k;
		while(k--){
			ll x,y;cin>>x>>y;
			cnt[x]++;
			a[x][cnt[x]]=i,t[x][cnt[x]]=y;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dst[i][j]=INF;
	for(int i=1;i<=n;i++)dst[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++)
			for(int k=j+1;k<=cnt[i];k++)
				dst[a[i][j]][a[i][k]]=dst[a[i][k]][a[i][j]]=min(dst[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
	while(q--){
		ll x,y;cin>>x>>y;
		ll ans=INF;
		for(int i=1;i<=cnt[x];i++)
			for(int j=1;j<=cnt[y];j++)
				ans=min(ans,dst[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 
