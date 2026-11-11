#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector <int> g[N];
int T, n, k, L, R, dis[N], d[N], m, tmp[N], pos[N], f[N], mn[N], ok[N], sum, xx, tt[N], par[N], son[N];
void clear(){
	for(int i=0; i<=n+2; i++)g[i].clear();
	for(int i=0; i<=n+2; i++){
		dis[i]=d[i]=tmp[i]=pos[i]=f[i]=mn[i]=ok[i]=sum=xx=tt[i]=par[i]=0;
	}
	// memset(dis,0,sizeof dis);
	// memset(d,0,sizeof d);
	// m=0;
	// memset(tmp,0,sizeof tmp);
	// memset(pos,0,sizeof pos);
	// memset(f,0,sizeof f);
	// memset(mn,0,sizeof mn);
	// memset(ok,0,sizeof ok);
}
void dfs(int x, int fa){
	for(auto y:g[x])if(y!=fa){
		dis[y]=dis[x]+1;
		dfs(y,x);
	}
}
void dfs2(int x, int fa){
	par[x]=fa;
	for(auto y:g[x])if(y!=fa&&!ok[y]){
		dfs2(y,x);
		f[x]=max(f[x],f[y]+1);
	}
}
void dfs3(int x, int fa){
	for(auto y:g[x])if(y!=fa&&!ok[y]){
		if(f[y]>=xx){
			dfs3(y,x);
			son[x]++;
		}
		else tt[x]=max(tt[x],f[y]+1);
	}
}
bool check(int lim){
	for(int i=0; i<=n+2; i++)son[i]=tt[i]=0;
	xx=lim;
	int mx=-1, ll=-1, rr=-1;
	for(int i=1; i<=m; i++){
		mx=max(f[d[i]],mx+1);
		if(mx>=lim){
			ll=i;break;
		}
	}
	mx=-1;
	for(int i=m; i; i--){
		mx=max(f[d[i]],mx+1);
		if(mx>=lim){
			rr=i;break;
		}
	}
	if(ll==-1||rr==-1||ll>=rr)return 1;
	// cout<<ll<<' '<<rr<<' '<<lim<<'\n';
	vector <int> v;
	v.push_back(ll);
	for(int i=ll+1; i<rr; i++)if(f[d[i]]>=lim)v.push_back(i);
	v.push_back(rr);
	int res=0, anss=rr-ll+1;
	for(int i=1; i<=n; i++)if(!ok[i])res+=(f[i]>=lim);
	anss+=res;
	memset(mn,0x3f,sizeof mn);
	for(int i=0; i<v.size()-1; i++){
		int L=v[i], R=v[i+1];
		mn[R]=R;
		mn[L]=1e9;
		for(int j=L+1; j<R; j++){
			int t=lim-f[d[j]];
			if(j-t>L)mn[j-t-1]=min(mn[j-t-1],j+t);
		}
		for(int j=R-1; j>=L; j--)mn[j]=min(mn[j],mn[j+1]);
		for(int j=L; j<R; j++)anss=min(anss,res+j-ll+1+rr-mn[j]+1);
	}
	// cout<<lim<<' '<<anss<<' '<<ll<<' '<<rr<<' '<<res<<'\n';
	// for(auto y:v)cout<<y<<' ';
	// cout<<'\n';
	sum=res+rr-ll+1;
	for(int i=ll; i<=rr; i++){
		dfs3(d[i],0);
	}
	for(int i=1; i<=n; i++)if(son[i]!=1&&f[i]>=lim&&!ok[i]){
		vector <int> vv={i};
		int t=par[i];
		while(son[t]==1&&!ok[t]){
			vv.push_back(t);
			t=par[t];
		}
		vv.push_back(t);
		for(int i=0; i<vv.size(); i++)mn[i]=1e9;
		mn[vv.size()-1]=vv.size()-1;
		for(int i=1; i<vv.size()-1; i++){
			int t=lim-tt[vv[i]];
			if(i-t>0)mn[i-t-1]=min(mn[i-t-1],i+t);
		}
		for(int i=vv.size(); i>=0; i--)mn[i]=min(mn[i],mn[i+1]);
		for(int j=0; j<vv.size()-1; j++)anss=min(anss,sum-(mn[j]-j-1));
		// cout<<i<<' '<<sum<<' '<<anss<<'\n';
		// for(auto y:vv)cout<<y<<' ';
		// cout<<'\n';
	}
	// cout<<lim<<' '<<anss<<' '<<ll<<' '<<rr<<' '<<res<<'\n';
	return anss<=k;
}
void solve(){
	clear();
	cin>>n>>k;
	for(int i=1; i<n; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(k==n){
		cout<<"0\n";
		return;
	}
	dfs(1,0);
	L=R=1;
	for(int i=1; i<=n; i++)if(dis[i]>dis[L])L=i;
	memset(dis,0,sizeof dis);
	dfs(L,0);
	for(int i=1; i<=n; i++)if(dis[i]>dis[R])R=i;
	memcpy(tmp,dis,sizeof tmp);
	memset(dis,0,sizeof dis);
	dfs(R,0);
	for(int i=1; i<=n; i++)if(tmp[i]+dis[i]==dis[L])d[dis[i]+1]=i;
	m=dis[L]+1;
	for(int i=1; i<=m; i++)ok[d[i]]=i;
	for(int i=1; i<=m; i++)dfs2(d[i],0);
	// cout<<L<<' '<<R<<' '<<m<<' '<<n<<' '<<k<<'\n';
	int l=1, r=m-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
	// if(l==7)exit(0);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>T;
	while(T--)solve();
	return 0;
}