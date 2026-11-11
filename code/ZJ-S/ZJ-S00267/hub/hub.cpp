#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		if(f) x=-x;
	}
	
	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>=10) print(x/10);
		putchar(x%10+'0');
	}
}

using namespace quick_io;

#define int long long

const int INF=1e15;
const int N=2e6+10;
vector<int> v[N];

int c[N];

bool vis[N];
int dis[N];
void dfs1(int u){
//	cout<<u<<" ";
	vis[u]=1;
	for(auto x:v[u]){
//		cout<<x<<" "<<vis[x]<<endl;
		if(vis[x]) continue;
		dis[x]=dis[u]+1;
		dfs1(x);
	}
}

int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void dfs3(int u){
	vis[u]=1;
	for(auto x:v[u]){
		if(vis[x]) continue;
		if(c[u]&&c[x]) fa[find(u)]=find(x);
		dfs3(x);
	}
}

int n,k;

int ans;
//int CNT;
void dfs2(int u,int d){
	if(d<0) return;
	if(u==n+1){
		if(d) return;
//		CNT++;
		int RES=0;
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=1;j<=n;j++) fa[j]=j;
		dfs3(1);
		int ronava=0;
		for(int j=1;j<=n;j++)
			if(c[j]&&fa[j]==j)
				ronava++;
		if(ronava>2) return;
		for(int i=1;i<=n;i++){
//			cout<<c[i]<<endl;
			if(c[i]) continue;
			for(int j=1;j<=n;j++) vis[j]=0;
			dis[i]=0;
			dfs1(i);
//			cout<<endl;
			int res=INF;
//			for(int j=1;j<=n;j++) if(c[j]) cout<<dis[j]<<" ";
//			cout<<endl;
			for(int j=1;j<=n;j++) if(c[j]) res=min(res,dis[j]);
			RES=max(RES,res);
//			cout<<res<<" ";
//			if(i==n) cout<<RES<<" ";
		}
//		cout<<endl;
//		if(RES==1){
//			for(int i=1;i<=n;i++) cout<<c[i]<<" ";
//			cout<<endl;
//		}
		ans=min(ans,RES);
		return;
	}
	if(n-u+1<d) return;
	c[u]=1;
	dfs2(u+1,d-1);
	c[u]=0;
	dfs2(u+1,d);
}

void solve(){
	input(n);
	input(k);
	ans=INF;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<n;i++){
		int u,x;
		input(u);
		input(x);
		v[u].push_back(x);
		v[x].push_back(u);
	}
//	CNT=0;
	dfs2(1,k);
	print(ans);
	putchar('\n');
//	cout<<" "<<CNT<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	input(C);
	input(T);
	while(T--) solve();
}