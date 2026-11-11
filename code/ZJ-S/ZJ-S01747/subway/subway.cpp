#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q,k,x,y,cnt[maxn],a[maxn][25];
long long dis[505][505],w[maxn],b[maxn][25],ans;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q ;
	for(int i=1;i<=m;i++) cin >> w[i] ;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		cin >> k ;
		while(k--) cin >> x >> y ,++cnt[x],a[x][cnt[x]]=i,b[x][cnt[x]]=y;
		dis[i][i]=0;
	}for(int i=1;i<=m;i++) for(int j=1;j<=cnt[i];j++) for(int k=1;k<=cnt[i];k++) dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],(long long)b[i][j]+b[i][k]);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin >> x >> y ;
		ans=dis[0][0];
		for(int i=1;i<=cnt[x];i++) for(int j=1;j<=cnt[y];j++){ans=min(ans,dis[a[x][i]][a[y][j]]+b[x][i]+b[y][j]+w[x]+w[y]);/*if(dis[a[x][i]][a[y][j]]+b[x][i]+b[y][j]+w[x]+w[y]==15) cout << i << " " << j << "\n" ;*/}
		cout << ans << "\n" ;
	}return 0;
}
/*
三百六十五里路呦~
越过春夏秋冬。
三百六十五里路呀~
岂能让它虚度。
三百六十五里路呀~
从故乡到异乡。
三百六十五里路呀~
从少年到白头。
*/