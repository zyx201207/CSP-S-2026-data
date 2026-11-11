#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int csd,n,m,d,q,a[N],cnt[N],dis[1005][1005],f[N][2];
bool c[N][2];
struct node{
	int id,x;
}b[505][1005];
vector<node>g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>csd>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		cin>>a[i];
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			int id,x;
			cin>>id>>x;
			g[i].push_back((node){id,x});
			if(n<505&&m<1005) b[i][j]=(node){id,x};
			if(n<3) c[id][i-1]=x;
		}
	}
	if(n==2&&m>1004){
		int minn=9e18;
		for(int i=1;i<=n;i++){
			if(c[i][0]>0&&c[i][1]>0) minn=min(minn,c[i][1]+c[i][0]);
		}
		while(q--){
			int u,v,ans=9e18;
			cin>>u>>v;
			for(int i=0;i<2;i++){
				if(c[u][i]&&c[v][i]) ans=min(ans,c[u][i]+c[v][i]);
				if(c[u][i]&&c[v][1-i]) ans=min(c[u][i]+c[v][1-i]+minn,ans);
			}
			cout<<ans+a[u]+a[v]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++) dis[b[i][j].id][b[i][k].id]=dis[b[i][k].id][b[i][j].id]=b[i][j].x+b[i][k].x;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<a[l]+a[r]+min(dis[l][r],dis[r][l])<<'\n';
	}
	return 0;
}
