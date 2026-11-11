#include<bits/stdc++.h>
#define int long long
#define pair pair<int,int>
#define x first
#define y second
#define p 998244353
#define endl '\n'
using namespace std;
inline void read(int &x){
	x=0;
	char y=getchar();
	int z=1;
	while(y<'0'||y>'9'){
		if(y=='-'){
			z=-1;
		}
		y=getchar();
	}
	while(y>='0'&&y<='9'){
		x=(x<<1)+(x<<3)+y-'0';
		y=getchar();
	}
	x*=z;
}
int id,n,m,h,q,a[500005],zh[505][505],dp[505][505],vis[505];
vector<pair> b[500005];
void sol(int x){
	for(int i=1;i<=n;i++){
		dp[x][i]=(int)1e18;
		vis[i]=0;
	}
	dp[x][x]=0;
	dp[x][0]=(int)1e18;
	for(int i=2;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				continue;
			}
			if(dp[x][j]<=dp[x][u]){
				u=j;
			}
		}
		if(u==0){
			break;
		}
		vis[u]=1;
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				continue;
			}
			dp[x][j]=min(dp[x][j],dp[x][u]+zh[u][j]);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(id);
	read(n);
	read(m);
	read(h);
	read(q);
	for(int i=1;i<=m;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		int x;
		read(x);
		for(int j=1;j<=x;j++){
			int y,z;
			read(y);
			read(z);
			b[y].push_back({i,z});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			zh[i][j]=(int)1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=j+1;k<b[i].size();k++){
				pair u=b[i][j],v=b[i][k];
				int w=u.y+v.y;
				zh[u.x][v.x]=min(zh[u.x][v.x],w);
				zh[v.x][u.x]=min(zh[v.x][u.x],w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		sol(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		read(x);
		read(y);
		int ans=(int)1e18;
		for(pair j:b[x]){
			for(pair k:b[y]){
				ans=min(ans,a[x]+a[y]+j.y+k.y+dp[j.x][k.x]);
			}
		}
		cout<<ans<<endl;
	}
}
