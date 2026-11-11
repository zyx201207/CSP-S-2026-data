#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N=507,M=5e5+7,inf=1e18+7; 
int c,n,m,d,q,w[M],k,id,t,dis[N][N],x,y,ans;
vector<pair<int,int> > a[M];
//(line,time)

void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') 
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;++i) read(w[i]);
	for(int i=1;i<=n;++i){
		read(k);
		for(int j=1;j<=k;++j){
			read(id),read(t);
			a[id].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) dis[i][j]=inf;
	for(int i=1;i<=m;++i)
		for(auto x:a[i])
			for(auto y:a[i])
				dis[x.fi][y.fi]=dis[y.fi][x.fi]=min(dis[y.fi][x.fi],x.se+y.se);
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		ans=inf;
		read(x),read(y);
		for(auto i:a[x])
			for(auto j:a[y]) ans=min(ans,dis[i.fi][j.fi]+i.se+j.se);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
