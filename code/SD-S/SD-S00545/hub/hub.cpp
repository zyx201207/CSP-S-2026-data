#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
inline int read(){
	register int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48),c=getchar();
	return res*f;
}
const int N=29;
struct edge{
	int next,to;
}e[N<<1];
int head[N],cnt;
inline void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int n,k,q,a[N];
inline int num(int p){
	int res=0;
	while(p){
		res+=(p&1);
		p>>=1;
	}
	return res;
}
bitset<20> vis;
void dfs(int u,int fa,int p){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa) continue;
		if((p>>v-1)&1) dfs(v,u,p);
	}
}
bool check(int p){
	vis.reset();
	int cnt=0;
	for(int i=1;i<=n;i++){
		if((p>>i-1)&1){
			if(!vis[i]){
				dfs(i,i,p);
				cnt++;
			}
		}
	}
	if(cnt>2) return 0;
	return 1;
}
int res=0;
int val[20];
void dfss(int u,int fa,int p){
	if((p>>u-1)&1){
		val[u]=0;
	}else{
		val[u]=min(val[u],val[fa]+1);
	}
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa) continue;
		if(val[v]>val[u]+1){
			dfss(v,u,p);
		}
	}
}
void solve(){
	cnt=0;
	memset(head,0,sizeof(head));
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	int ans=INF;
	for(int i=1;i<(1<<n);i++){
		if(num(i)!=k) continue;
		if(check(i)){
			res=0;
			memset(val,INF,sizeof(val));
			for(int j=1;j<=n;j++){
				if((i>>i-1)&1){
					dfs(j,j,i);
					break;
				}
			}
			for(int j=1;j<=n;j++){
				res=max(res,val[i]);
			}
			ans=min(ans,res);
		}
	}
	cout<<ans<<'\n';
}
void solve1(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	int m=(n-1)/2;
	if(k==n){
		cout<<0<<'\n';
	}else if(k>=m-1){
		cout<<1<<'\n';
	}else{
		cout<<(m+1-k)/4+1<<'\n';
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;
	cin>>c>>T;
	if(c==13||c==14){
		while(T--) solve1();
		return 0;
	}
	while(T--){
		solve();
	}
	return 0;
}

