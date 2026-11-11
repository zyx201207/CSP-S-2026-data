#include<bits/stdc++.h>
//UID 1137851
//Oct 31 Today
//Dec 25 ??? 
using namespace std;
const int N=505;
const int M=5e5+5;
int n,m,c,d,q,w[M],k[N];
int v[M][25],cnt[M];
long long dis[N][N],t[M][25];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i],cnt[i]=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x=0;
		for(int j=1;j<=k[i];j++){	
			cin>>x;
			cin>>t[x][++cnt[x]];
			v[x][cnt[x]]=i;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int x=1;x<=cnt[i];x++){
			for(int y=x+1;y<=cnt[i];y++){
				int a=min(v[i][x],v[i][y]);
				int b=max(v[i][x],v[i][y]);
				dis[a][b]=min(dis[a][b],t[i][x]+t[i][y]),dis[b][a]=min(dis[b][a],t[i][x]+t[i][y]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		long long ans=1e18;
		for(int a=1;a<=cnt[x];a++){
			for(int b=1;b<=cnt[y];b++){
				int i=v[x][a],j=v[y][b];
				ans=min(ans,dis[i][j]+t[x][a]+w[x]+t[y][b]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

