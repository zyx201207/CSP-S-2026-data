#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define ptc putchar
#define gtc getchar
using namespace std;
ll read(){
	ll x=0,f=1; char ch=gtc();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=gtc(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gtc();
	return x*f;
}
void write(ll x){
	if(x<0) ptc('-'),x=-x;
	if(x>9) write(x/10);
	ptc(x%10+'0');
}
inline void printsp(ll x){ write(x),ptc(' '); }
inline void println(ll x){ write(x),ptc('\n'); }
const int maxn=2e5+5,inf=1e9;
int n,k,rk[maxn],d[maxn],vis[maxn],ans=inf;
vector<int> g[maxn];

void dfs0(int nd,int fa,int dep){
	d[nd]=min(d[nd],dep);
	for(auto u:g[nd]){
		if(u==fa) continue;
		dfs0(u,nd,dep+1);
	}
}

void go(int nd){
	vis[nd]=1;
	for(auto u:g[nd]){
		if(vis[u]||!rk[u]) continue;
		go(u);	
	}
}
void bao(int dep,int sum){
	if(sum+(n-dep+1)<k) return;
	if(dep==n+1){
		if(sum!=k) return ;
		for(int i=0;i<=n+1;i++) d[i]=inf,vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(rk[i]){
				dfs0(i,0,0);
				if(!vis[i]) go(i),cnt++;
			}
		}
		if(cnt!=2) return ;
//		for(int i=1;i<=n;i++) cout<<rk[i]<<" ";
//		cout<<" rk\n";
		int res=0;
		for(int i=1;i<=n;i++) res=max(res,d[i]);
//		cout<<res<<" res\n";
		ans=min(ans,res);
		return ;
	}
	rk[dep]=0,bao(dep+1,sum);
	rk[dep]=1,bao(dep+1,sum+1),rk[dep]=0;
}

void init(){
	ans=inf;
	for(int i=0;i<=n+2;i++){
		g[i].clear(),rk[i]=d[i]=0;
	}
}
void solve(){
	n=read(),k=read();
	init();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);		
	}
	bao(1,0);
	println(ans);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--) solve();
	return 0;
}
