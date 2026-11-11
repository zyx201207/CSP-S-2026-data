#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=1e18;
int tp,n,m,D,Q,w[500005][25],cnt[500005],bl[500005][25];ll f[505][505];
signed main(){
	//system("fc subway.out subway7.ans");exit(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>tp>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>w[i][0];
	for(int i=1;i<=n;i++){
		int N;cin>>N;
		for(int j=1,x;j<=N;j++){
			cin>>x;cnt[x]++;bl[x][cnt[x]]=i;cin>>w[x][cnt[x]];
		}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)f[i][j]=f[j][i]=inf;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++)for(int k=j+1;k<=cnt[i];k++){
			f[bl[i][j]][bl[i][k]]=min(f[bl[i][j]][bl[i][k]],1ll*(w[i][j]+w[i][k]));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=f[j][i]=min(f[i][j],f[j][i]);
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	//for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';exit(0);
	while(Q--){
		int x,y;cin>>x>>y;ll ans=inf;
		for(int i=1;i<=cnt[x];i++)for(int j=1;j<=cnt[y];j++){
			ans=min(ans,1ll*(f[bl[x][i]][bl[y][j]]+w[x][i]+w[y][j]+w[x][0]+w[y][0]));
		}
		cout<<ans<<'\n';
	}
}