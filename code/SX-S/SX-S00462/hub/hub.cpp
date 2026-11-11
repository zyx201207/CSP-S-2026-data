#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int C,_,n,K,cnt,dep[100005],fa[100005][30],ans;
bool is[100005];
vector<int>v[100005];
void qwq(int x,int f){
	cnt+=(is[x]&&!is[f]);
	for(auto y:v[x]) if(y!=f) qwq(y,x);
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=25;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto y:v[x]) if(y!=f) dfs(y,x);
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=25;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=25;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>_;
	while(_--){
		cin>>n>>K;ans=inf;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		if(K==2){
			for(int x=1;x<=n;x++)
				for(int y=1;y<=n;y++){
					if(x==y) continue;
					int ma=0;
					for(int i=1;i<=n;i++)
						ma=max(ma,min(dep[x]+dep[i]-2*dep[lca(x,i)],dep[y]+dep[i]-2*dep[lca(y,i)]));
					ans=min(ans,ma);
				}
		}
		else{
			for(int i=1;i<1<<n;i++){
				if(__builtin_popcount(i)!=K) continue;
				vector<int>tmp;
				for(int j=1;j<=n;j++) is[j]=0;
				for(int j=1;j<=n;j++) if(i>>j-1&1) is[j]=1,tmp.push_back(j);
				cnt=0;
				qwq(1,0);
				if(cnt>2) continue;
				int ma=0;
				for(int i=1;i<=n;i++){
					int mi=1e18;
					for(auto j:tmp) mi=min(mi,dep[i]+dep[j]-2*dep[lca(i,j)]);
					ma=max(ma,mi);
				}
				ans=min(ans,ma);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}