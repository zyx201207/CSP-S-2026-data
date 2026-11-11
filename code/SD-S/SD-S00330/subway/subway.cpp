#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,gm,q;
int w[500005];
ll d[505][505];
int t[500005];
int dt[500005][21];
int id[500005][21];
int vis[505];
inline int read(){
	int k=0,k2=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') k2=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*k2;
}
void dj(int x){
	priority_queue<pair<ll,int> ,vector<pair<ll,int> > ,greater<pair<ll,int> > >p;
	for(int i=1;i<=n;i++) vis[i]=0;
	d[x][x]=0;
	p.push(make_pair(0ll,x));
	while(!p.empty()){
		int u=p.top().second;
		p.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v=1;v<=n;v++){
			if(v==u) continue;
			if(d[x][v]>=d[x][u]+d[u][v]){
				d[x][v]=d[x][u]+d[u][v];
				p.push(make_pair(d[x][v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),gm=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int x,y;
			x=read(),y=read();
			t[x]++;
			dt[x][t[x]]=y;
			id[x][t[x]]=i;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	d[i][j]=1e18;
	for(int i=1;i<=m;i++)
	for(int l=1;l<=t[i];l++)
	for(int r=l+1;r<=t[i];r++){
		int x=id[i][l],y=id[i][r];
		d[y][x]=d[x][y]=min(d[x][y],(ll)(dt[i][l]+dt[i][r]));
	}
	for(int i=1;i<=n;i++) dj(i);
	while(q--){
		int x,y;
		ll ans=1e18;
		x=read(),y=read();
		for(int l=1;l<=t[x];l++)
		for(int r=1;r<=t[y];r++){
			int u=id[x][l],v=id[y][r];
			ans=min(ans,(ll)(dt[x][l]+dt[y][r])+d[u][v]);
		}
		ans+=(ll)(w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
