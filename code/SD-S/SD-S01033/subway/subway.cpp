#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=5e5+10;
const int M=5e2+10;
/*====================*/
const long long INF=0x3f3f3f3f3f3f3f3f;
/*====================*/
int n,m,d,q;
long long w[N];
long long dis[M][M];
int a[N][25][2],cnt[N];
/*====================*/
void Solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int cntt;
		cin>>cntt;
		while(cntt--){
			int l,r;
			cin>>l>>r;
			a[l][++cnt[l]][0]=i;
			a[l][cnt[l]][1]=r;
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			int l=a[i][j][0],r=a[i][j][1];
			for(int k=1;k<=cnt[i];k++){
				int ll=a[i][k][0],rr=a[i][k][1];
				if(l==ll&&r==rr)continue;
				dis[l][ll]=dis[ll][l]=min(dis[l][ll],1ll*r+rr);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=INF;
		for(int i=1;i<=cnt[x];i++){
			int l=a[x][i][0];
			for(int j=1;j<=cnt[y];j++){
				int r=a[y][j][0];
				ans=min(ans,dis[l][r]+a[x][i][1]+a[y][j][1]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
/*====================*/
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin>>c;
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}



