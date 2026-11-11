#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull signed long long
#define pi pair<int,int>
const int N=510;
const int M=5e5+10;
int dis[N][N];
int w[M];
int cnt[M],nxt[M][21],tim[M][21];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			++cnt[a];
			nxt[a][cnt[a]]=i;tim[a][cnt[a]]=t;
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int x=1;x<=cnt[i];x++){
			for(int y=1;y<=cnt[i];y++){
				if(x==y)continue;
				dis[nxt[i][x]][nxt[i][y]]=
				min(dis[nxt[i][x]][nxt[i][y]],tim[i][x]+tim[i][y]);
			}
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			for(int k=1;k<=n;k++){
				dis[x][y]=min(dis[x][y],dis[x][k]+dis[k][y]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;cin>>s>>t;
		int val=1e18;
		for(int j=1;j<=cnt[s];j++){
			for(int k=1;k<=cnt[t];k++){
				val=min(val,tim[s][j]+tim[t][k]+dis[nxt[s][j]][nxt[t][k]]);
			}
		}
		cout<<val+w[s]+w[t]<<"\n";
//		cout<<val<<" VAL\n";
	}
	return 0;
}