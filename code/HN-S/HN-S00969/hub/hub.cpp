#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=1e6+5,INF=0x3f3f3f3f;
int c,_,n,k,f[N];
bool vs[N];
void solA(){
	while(_--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
		} 
		int t=n/2;
		if(k==n){
			cout<<0<<endl;
			continue;
		}
		if(k>=t){
			cout<<1<<endl;
			continue;
		}
		if(k==t-1||k==t-2){
			cout<<2<<endl;
			continue;
		}
		int x=k/2,y=(t-k)/3;
		for(int i=1;i<=t;i++) vs[i]=0,f[i]=INF;
		for(int i=y+1;i<=y+x;i++) vs[i]=1;
		for(int i=y+x+y+1;i<=2*(y+x);i++) vs[i]=1;
		if(k%2) vs[2*(y+x)+1]=1;
		int lt=0;
		for(int i=1;i<=t;i++){
			if(vs[i]) lt=i;
			if(lt) f[i]=min(f[i],i-lt+1); 
		} 
		int rt=0,an=-INF;
		for(int i=t;i>=1;i--){
			if(vs[i]) rt=i;
			if(rt) f[i]=min(f[i],rt-i+1);
			an=max(an,f[i]);
		}
		cout<<an<<endl;
	}
}
int fa[N],dep[N];
vector<int> e[N];
void dfs(int u,int ff){
	fa[u]=ff;
	dep[u]=dep[ff]+1; 
	for(int v:e[u]) if(v!=ff) dfs(v,u);
}
int dis(int u,int v){
	int rt=0;
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]) u=fa[u],rt++;
	if(u==v) return rt;
	while(u!=v){
		if(u==v) break;
		u=fa[u],v=fa[v],rt+=2;
	}
	return rt;
} 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>_;
	if(c==13||c==14){
		solA();
		return 0;
	}
	while(_--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			e[u].pb(v);
			e[v].pb(u);
		}
		dfs(1,0);
		int an=INF;
		for(int i=0;i<(1<<n);i++){
			int ma=0;
			for(int j=1;j<=n;j++) if((i>>j-1)&1){
				for(int u=1;u<=n;u++){
					ma=max(ma,dis(u,j));
				}
			}
			an=min(an,ma);
		}
		cout<<an<<endl;
	}
	return 0;
}/*
Oct31==Dec25?

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/

