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

ll n,k,fa[N],cnt;
vector<ll>g[N];
inline ll find(ll x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(ll x,ll y){fa[find(x)]=find(y);return;}

inline ll cot(ll x){
	ll res=0;
	for(;x;x>>=1)
		if(x&1)res++;
	return res;
}

ll d[N],lg[N];
ll f[N][30];
inline void bfs(){
	queue<ll>q;q.push(1);
	d[1]=1;
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		for(ll y:g[x]){
			if(d[y])continue;
			d[y]=d[x]+1;
			f[y][0]=x;
			for(int i=1;i<=lg[n];i++)
				f[y][i]=f[f[y][i-1]][i-1];
			q.push(y);
		}
	}
}
inline ll lca(ll x,ll y){
	if(d[x]<d[y])swap(x,y);
	for(int i=lg[n];i>=0;i--)
		if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y)return x;
	for(int i=lg[n];i>=0;i--)
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}

ll ans=inf;

inline void solve(){
	n=read<ll>();k=read<ll>();lg[0]=-1;
	memset(d,0,sizeof(d));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)g[i].clear();
	for(ll i=1,x,y;i<=n;i++){
		x=read<ll>();
		y=read<ll>();
		g[x].push_back(y);
		g[y].push_back(x);
	}bfs();
	for(ll p=1;p<(1<<n);p++){
		if(cot(p)!=k)continue;
		cnt=k;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(ll x=1;x<=n;x++){
			if(p&(1<<(x-1ll))){
				for(ll y:g[x]){
					if(p&(1<<(y-1ll))){
						if(find(x)!=find(y)){
							merge(x,y);cnt--;
						}
					}
				}
			}
		}
		if(cnt>2)continue;
		ll sum=0;
		for(ll i=1;i<=n;i++){
			if(p&(1<<(i-1)))continue;
			ll res=0;
			for(ll j=1;j<=n;j++){
				if(p&(1<<(j-1))){
					ll dis=d[i]+d[j]-2*d[lca(i,j)];
					res=min(res,dis);
				}
			}sum=max(sum,res);
		}
		ans=min(ans,sum);
	}write<ll>(ans);
	putchar('\n');
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll C,T;C=read<ll>();T=read<ll>();
	while(T--)solve();
	return 0;
}