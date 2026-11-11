#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int min(int x,int y){
	return (x<y)?x:y;
}
int max(int x,int y){
	return (x>y)?x:y;
}
const int N=5e5+5,M=500+5,inf=1e18;
int C;
int n,m,d,q;
int nd[N];
vector<int>v[M],t[M];
vector<pii>g[N];
int dis[M][M];
void sl(){
	for(int i=1;i<=M-5;i++){
		for(int j=1;j<=M-5;j++)dis[i][j]=inf;
	}
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		nd[i]=read();
	}
	for(int i=1;i<=n;i++){
		int len=read();
		v[i].resize(len);
		t[i].resize(len);
		for(int j=0;j<len;j++){
			v[i][j]=read();
			t[i][j]=read();
			g[v[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				dis[g[i][j].fi][g[i][k].fi]=min(dis[g[i][j].fi][g[i][k].fi],g[i][j].se+g[i][k].se);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=1;j<=n;j++){
			dis[i][j]=min(dis[i][j],dis[j][i]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		int ans=inf;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				ans=min(ans,g[x][i].se+g[y][j].se+dis[g[x][i].fi][g[y][j].fi]);
			}
		}
		cout<<ans+nd[x]+nd[y]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	sl();
	return 0;
}

