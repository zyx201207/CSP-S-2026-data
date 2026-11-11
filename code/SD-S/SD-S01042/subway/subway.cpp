#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
inline ll read(){
	ll f=1,w=0;
	char ch=getchar();
	for(;ch>'9' or ch<'0';ch=getchar())if(ch=='-') f=-1;
	for(;ch>='0' and ch<='9';ch=getchar()) w=w*10+ch-'0';
	return f*w;
}
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10),x%=10;
	putchar(x+'0');
}
ll c,n,m,d,q,w[N],k[505],ans;
struct node{
	ll x,y;
};
struct node2{
	ll x,y,z;
	bool operator < (const node2 &Y) const{
		return z>Y.z;
	}
};
vector<node> to[505];
vector<ll> dis[505];
vector<bool> vis[505];
vector<node> e[N];
inline void diji(ll qi,ll zh){
	priority_queue<node2> q;
	ans=1e18;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k[i];j++){
			dis[i][j]=1e18;
			vis[i][j]=false;
		}
	}
	for(node x: e[qi]){
		q.push({x.x,x.y,to[x.x][x.y].y});
	}
	while(!q.empty()){
		node2 x=q.top();
		q.pop();
		if(dis[x.x][x.y]<x.z or vis[x.x][x.y]) continue;
		vis[x.x][x.y]=true;
		dis[x.x][x.y]=x.z;
//		write(x.x),putchar(' '),write(x.y),putchar(' ');
//		write(x.z),putchar('\n');
		if(x.y+1<=k[x.x]){
			if(vis[x.x][x.y+1] or dis[x.x][x.y+1]<x.z);
			else{
				q.push({x.x,x.y+1,x.z});
			}
		}else{
			if(vis[x.x][1] or dis[x.x][1]<x.z);
			else q.push({x.x,1,x.z});
		}
		for(node y: e[to[x.x][x.y].x]){
			ll z=x.z+to[y.x][y.y].y+to[x.x][x.y].y;
			if(vis[y.x][y.y] or dis[y.x][y.y]<z) continue;
			q.push({y.x,y.y,z});
		}
	}
	for(node x: e[zh]){
//		write(x.x),putchar(' '),write(x.y),putchar('\n');
		ans=min(ans,dis[x.x][x.y]+to[x.x][x.y].y);
//		write(ans),putchar(' '),write(dis[x.x][x.y]+to[x.x][x.y].y);
//		putchar('\n');
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1;i<=n;i++){
		k[i]=read();
		to[i].push_back({0,0});
		vis[i].resize(k[i]+1);
		dis[i].resize(k[i]+1);
		for(ll j=1;j<=k[i];j++){
			ll a=read(),b=read();
			to[i].push_back({a,b});
			e[a].push_back({i,j});
		}
	}
	while(q--){
		ll x=read(),y=read();
		diji(x,y);
		ans+=(w[x]+w[y]);
		write(ans),putchar('\n');
	}
	return 0;
}
