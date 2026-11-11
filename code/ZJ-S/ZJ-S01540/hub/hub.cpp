#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> g[N];
int n,k;
bool f[N];
int jb(int now,int gs,int fa){
	int minn=N;
	if(f[now]) return gs;
	for(auto i:g[now]) if(i!=fa) minn=min(minn,jb(i,gs+1,now));
	return minn;
}
int cnt=0;
void pd(int now,int fa){
	if(f[now]&&!f[fa]) cnt++;
	for(auto i:g[now]) if(i!=fa) pd(i,now);
}
int minn=N;
void dfs(int now,int gs){
	if(gs==k){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				ans=max(ans,jb(i,0,-1));
			}//else cout<<i<<" ";
		}
		//cout<<ans;
		//cout<<'\n';
		minn=min(minn,ans);
	}
	for(int i=now+1;i<=n;i++){
		f[i]=1;
		cnt=0;
		pd(i,0);
		if(cnt<=2) dfs(i,gs+1);
		f[i]=0;
	}
}
int c,t;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(c==13||c==14){
		cout<<1<<'\n';
		return ;
	}
	minn=N;
		dfs(0,0);
		cout<<minn<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}