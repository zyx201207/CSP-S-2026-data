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

const int N=1e6+10;
const int M=1e4+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll n,d,ans,a[N];
vector<ll>g[N];
ll cnt[M][M];
ll dis[N];
bool vis[N];

inline void DJ(ll s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});dis[s]=0;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int y:g[x]){
			if(dis[x]+1<dis[y]){
				dis[y]=dis[x]+1;
				cnt[s][y]=1;
				if(!vis[y])q.push({dis[y],y});
			}else
			if(dis[x]+1==dis[y]){
				cnt[s][y]++;
				if(!vis[y])q.push({dis[y],y});
			}
		}
	}
	return;
}

inline void solve(){
	n=read<ll>();d=read<ll>();ans=0ll;
	for(ll i=1;i<=n;i++)g[i].clear();
	memset(cnt,0,sizeof(cnt));
	for(ll i=1;i<=n;i++)a[i]=read<ll>();
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			if(a[i]-a[j]<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for(ll i=1;i<=n;i++)DJ(i);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			if(cnt[j][i]==2){
				ans++;
			}
		}
	}write<ll>(ans);
	putchar('\n');
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll C,T;C=read<ll>();T=read<ll>();
	while(T--)solve();
	return 0;
}