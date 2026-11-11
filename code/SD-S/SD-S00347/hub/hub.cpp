#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int N=1e6+18;
int c,T,n,k;
struct node{
	int nxt,to;
}q[N*2];int head[N],ct;
int f[N],dep[N],d[N];
void dfs1(int x,int fa){
	f[x]=fa;
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=q[i].nxt){
		int dd=q[i].to;
		if(dd==fa) continue;
		dfs1(dd,x); 
	}
}
int dis(int x,int y){
	int res=0;
	while(x!=y){
		if(dep[x]<dep[y]){
			swap(x,y);
		}
		x=f[x];res++;
	}return res;
}
void add(int x,int y){
	q[++ct]=node{head[x],y};
	head[x]=ct;return;
}int vis[N],ch[N],tp,ans,fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void mer(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
void chk(){
	for(int i=1;i<=n;i++){
		if(vis[i]){
		//	cout << i << "** ";
			for(int dd=head[i];dd;dd=q[dd].nxt){
				if(vis[q[dd].to]) mer(dd,q[dd].to);
			}
		}
	}
	//cout << "\n";
	int tt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&fa[i]==i) tt++;
	}
	if(tt>2) return;
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(vis[j]){
				d[i]=min(d[i],dis(i,j));
			}
		}
	}
	for(int i=1;i<=n;i++){
		res=max(d[i],res);
	}
	//cout << mx << "()\n";
	ans=min(ans,res);
}
void dfs(int x){
//cout << ")))\n";
	if(x==k+1){
		
		for(int i=1;i<=n;i++){
			fa[i]=i;d[i]=1e14;
		}
		chk();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			//ch[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		} 
	}
}
void solve(){
	ans=1e14;ct=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	cin >> n >> k;
	//cout << n << ' ' << k << "((\n";
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		add(u,v);add(v,u);
	}dfs1(1,0);
	
	if(k==2){
		cout << 1<<'\n';
		return;
	}
	//cout << "111\n";
	dfs(1);
	cout << ans << '\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
}
// Oct31==Dec25?
/*
0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
*/
