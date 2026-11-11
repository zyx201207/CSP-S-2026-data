#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
const int nn=1e6+5;
// #define pii pair<int,int>
vector<int> e[nn];
#define pb push_back
int no;
int bfu[nn],bfv[nn];
int dis[nn],mx=-1,pos,now;
int dad[nn];
void dfs(int x,int fa){
	dad[x]=fa;
	for(int v:e[x]){
		if(v==fa) continue;
		if(v==now) continue;
		dis[v]=dis[x]+1;
		dfs(v,x);
	}
	if(dis[x]>mx){
		mx=dis[x];
		pos=x;
	}
}
int val[nn];
int tong[nn];
void dfsc(int x,int fa){
	val[x]=1;
	for(int v:e[x]){
		if(v==fa) continue;
		if(v==now) continue;
		dfsc(v,x);
		val[x]=max(val[x],val[v]+1);
	}
	if(x!=pos){
		tong[val[x]]++;
		// cout<<val[x]<<" "<<x<<endl;
	}
}
int ve[nn],cnt;
const int inf=1e9;
int ans=0,fl;
void solve(int x,int fa){
	now=fa;
	dis[x]=0;
	mx=-1;
	dfs(x,fa);
	mx=-1;
	int u=pos;
	dis[pos]=0;
	dfs(pos,0);
	int stp=dis[pos]/2;
	// cerr<<x<<" "<<fa<<endl;
	while(stp--){
		pos=dad[pos];
		// cout<<pos<<endl;
	}
	dfsc(pos,0);
	// cout<<x<<" "<<pos<<endl;
	if(fl==0){
		for(int i=0;i<=n;i++) ve[i]=0;
		cnt=0;
		for(int i=val[pos];i>=1;i--){
			while(tong[i]--) ve[++cnt]=i;
			tong[i]=0;
		}
		fl=1;
	}
	else{
		// cerr<<x<<' '<<fa<<endl;
		// cerr<<val[pos]<<endl;
		int gs=0;
		fl=0;
		for(int i=val[pos];i>=1;i--){
			while(tong[i]--){
				gs++;
				if(gs>=k) break;
				ans=min(ans,max(i,ve[k-gs]));
			}
			tong[i]=0;
		}
	}
}
inline int getdis(int x,int fa){
	now=fa;
	dis[x]=0;
	mx=-1;
	dfs(x,fa);
	mx=-1;
	int u=pos;
	dis[pos]=0;
	dfs(pos,0);
	return dis[pos];
}
int rt,mn;
bool vis[nn];
int sz[nn];
void pre(int x,int fa){
	sz[x]=1;
	for(int v:e[x]){
		if(vis[v]) continue;
		if(v==fa) continue;
		pre(v,x);
		sz[x]+=sz[v];
	}
}
void doit(int x,int fa,int tot){
	int maxx=0;
	for(int v:e[x]){
		if(vis[v]) continue;
		if(v==fa) continue;
		doit(v,x,tot);
		maxx=max(maxx,sz[v]);
	}
	maxx=max(maxx,tot-sz[x]);
	if(maxx<mn){
		mn=maxx;
		rt=x;
	}
}
void calc(int x){
	mn=INT_MAX;
	pre(x,0);
	doit(x,0,sz[x]);
	x=rt;
	vis[x]=1;
	int maxx=-1,to;
	for(int v:e[x]){
		if(vis[v]) continue;
		int now=getdis(v,x);
		if(now>maxx){
			maxx=now;
			to=v;
		}
	}
	if(maxx==-1) return ;
	solve(to,x);
	solve(x,to);
	calc(to);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;ans=inf;fl=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].pb(v),e[v].pb(u);
			// e[u].pb({v,i}),e[v].pb({u,i});
			bfu[i]=u,bfv[i]=v;
		}
		if(c>=13&&c<=14){
			int m=(n-1)/2;
			int l=m/2-4,r=m/2+4;
			l=max(l,1),r=min(r,n-1);
			for(int i=l;i<=r;i++){
				solve(bfu[i],bfv[i]);
				solve(bfv[i],bfu[i]);
			}
		}
		else if((c>=11&&c<=12)||(c>14)){
			for(int i=1;i<=n;i++) vis[i]=0;
			calc(1);
		}
		else{
			for(int i=1;i<n;i++){
				solve(bfu[i],bfv[i]);
				solve(bfv[i],bfu[i]);
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}