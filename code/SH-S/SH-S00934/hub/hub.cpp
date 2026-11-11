#include<bits/stdc++.h>
#define INF 1e18
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define gc getchar()
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=gc;
	}
	return x*f;
}
int n,k;
int ch[1000009];
int d[1000009];
int mn[1000009];
int p[100009];
vector<int> e[1000009];
int ans=INF;
bool vst[1000009];
void bfs(int x){
	queue<int> q;
	memset(d,0x3f,sizeof d);
	d[x]=0;
	q.push(x);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:e[u]){
			if(d[v]>=INF){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}
int getrt(int x){
	if(p[x]==x) return x;
	return p[x]=getrt(p[x]);
}
int getans(){
	if(k!=2){
		rep(i,1,k) p[ch[i]]=ch[i];
		rep(i,1,k){
			int u=ch[i];
			for(int v:e[u]){
				if(!vst[v]) continue;
				int nu=getrt(u),nv=getrt(v);
				if(nu==nv) continue;
				p[nu]=nv;
			}
		}
		set<int> st;
		rep(i,1,k){
			st.insert(getrt(ch[i]));
		}
		if(st.size()>2) return INF;
	}
	memset(mn,0x3f,sizeof mn);
	rep(i,1,k){
		bfs(ch[i]);
		rep(j,1,n) mn[j]=min(mn[j],d[j]);
	}
	int mx=0;
	rep(i,1,n){
	//	cout<<mn[i]<<" ";
		mx=max(mx,mn[i]);
	}
	//cout<<endl;
	return mx;
}
void dfs(int ly){
	if(ly==k+1){
		 ans=min(ans,getans());
		 return;
	}
	rep(i,ch[ly-1]+1,n){
		ch[ly]=i;
		vst[i]=1;
		dfs(ly+1);
		vst[i]=0;
	}
}
void solve(){
	ans=INF;
	n=read(),k=read();
	rep(i,1,n) e[i]=vector<int>();
	rep(i,1,n-1){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--) solve();
	return 0;
}

