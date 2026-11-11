#include<bits/stdc++.h>
#define int long long
using namespace std;
const int xx=5e5+5e2;
const int inf=1e18+7;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int c,n,m,d,q;
int w[xx];
vector<int> a[505],t[505];
int dist[505][505];
vector<pair<int,int> > way[xx];
void solve(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
		way[i].push_back({0,0});
	}
	for(int i=1;i<=n;++i){
		int k=read();
		a[i].push_back(0),t[i].push_back(0);
		for(int j=1;j<=k;++j){
			int aa=read(),tt=read();
			a[i].push_back(aa),t[i].push_back(tt);
			way[aa].push_back({i,j});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dist[i][j]=inf;
		}
	}
	for(int i=1;i<=n;++i) dist[i][i]=0;
	for(int i=1;i<=m;++i){
		int now=way[i].size()-1;
		for(int j=1;j<=now;++j){
			int p1=way[i][j].first;
			int now1=t[p1][way[i][j].second];
			for(int k=1;k<=now;++k){
				//if(j==k) continue;
				int p2=way[i][k].first;
				int now2=t[p2][way[i][k].second];
				dist[p1][p2]=dist[p2][p1]=min(dist[p1][p2],now1+now2);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	//cout<<dist[1][2]<<'\n';
	for(int i=1;i<=q;++i){
		int x=read(),y=read();
		int ans=inf;
		int now1=way[x].size()-1,now2=way[y].size()-1;
		for(int j=1;j<=now1;++j){
			int p1=way[x][j].first;
			int now1=t[p1][way[x][j].second];
			for(int k=1;k<=now2;++k){
				//if(j==k) continue;
				int p2=way[y][k].first;
				int now2=t[p2][way[y][k].second];
				//cout<<now1<<' '<<now2<<'\n';
				ans=min(ans,dist[p1][p2]+now1+now2);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
}

