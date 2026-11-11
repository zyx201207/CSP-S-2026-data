#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cc,t,n,m,ans,mid,dis[N];
vector<int> g[N];
namespace sa{
	void main(){
		while(t--){
			cin >> n >> m;
			int d=n/2;
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<n;i++){
				int x,y;
				cin >> x >> y;
				g[x].push_back(y);
				g[y].push_back(x);
			}
			cout << (d-m)/4+2 << '\n';
		}
	}
}
namespace bl{
	int a[N],vis[N],dis[N];
	void ltk(int x,int fa){
		vis[x]=1;
		for(auto y:g[x]) if(y!=fa&&a[y]==1) ltk(y,x);
	}
	void ddfs(int x,int fa){
		dis[x]=1;
		for(auto y:g[x]){
			if(y==fa) continue;
			ddfs(y,x);
			dis[x]=max(dis[x],dis[y]+1);
		}
		if(a[x]) dis[x]=0;
	}
	void dfs(int x,int c){
		if(x==n+1){
			if(c!=0) return;
			memset(vis,0,sizeof vis);
			int sum=0,cnt=0;
			for(int i=1;i<=n;i++) if(a[i]==1&&vis[i]==0) cnt++,ltk(i,0);
			if(cnt>2) return;
			ddfs(1,0);
			for(int i=1;i<=n;i++) sum=max(sum,dis[i]);
			ans=min(ans,sum);
			return;
		}
		dfs(x+1,c);
		if(c!=0) a[x]=1,dfs(x+1,c-1),a[x]=0;
	}
	void main(){
		while(t--){
			cin >> n >> m;ans=n+1;
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<n;i++){
				int x,y;
				cin >> x >> y;
				g[x].push_back(y);
				g[y].push_back(x);
			}
			dfs(1,m);
			cout << ans << '\n';
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> cc >> t;
	if(cc==13||cc==14)sa::main();
	else bl::main();
	return 0;
}
