#include<bits/stdc++.h>
using namespace std;

namespace IO{
	template<class T>inline T read(){
		T x=0;int f=1;char c=getchar();
		while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
		while('0'<=c && c<='9'){x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	template<class T>inline void write(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+'0');
		return;
	}
}using namespace IO;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>

const int N=1e5+10;
const int M=5e2+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll c,n,m,d,q;
ll w[N];
vector<pii>g[N+M];
vector<ll>a[N];//a[站台]:路线
ll t[M][N];
ll dis[M][N+M];
bool vis[N+M];

inline void DJ(ll s){
	memset(vis,0,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});dis[s][s]=0;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(pii i:g[x]){
			ll y=i.first;
			ll w=i.second;
			if(dis[s][x]+w<dis[s][y]){
				dis[s][y]=dis[s][x]+w;
				if(!vis[y])q.push({dis[s][y],y});
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read<ll>();
	n=read<ll>();
	m=read<ll>();
	d=read<ll>();
	q=read<ll>();
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=m;i++)w[i]=read<ll>();
	for(ll x=1;x<=n;x++){
		ll k=read<ll>();
		for(ll i=1;i<=k;i++){
			ll y=read<ll>();
			ll w=read<ll>();
			g[x+m].push_back({y,w});
			g[y].push_back({x+m,w});
			a[y].push_back(x);
			t[x+m][y]=w;
		}
	}
	for(int i=1;i<=n;i++)DJ(i+m);
	for(ll i=1,x,y,ans;i<=q;i++){
		ans=1e18;
		x=read<ll>();y=read<ll>();
		for(ll u:a[x]){
			for(ll v:a[y]){
				ans=min({ans,dis[u+m][v+m]+t[u+m][x]+t[v+m][y]});
			}
		}
		write<ll>(ans+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}