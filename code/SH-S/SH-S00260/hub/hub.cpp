#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=12;
const int inf=1e9;
int n,k,t,S;
vector<int> a[N];
bool vis[N];
void dfs(int u,int fa){
	vis[u]=true;
	for(auto v:a[u]){
		if(v==fa) continue;
		if((S>>(v-1))&1) dfs(v,u);
	}
}
void solve(int u,int fa,int x){
	if((S>>(u-1))&1){
		t=min(t,x);
		return;
	}
	for(auto v:a[u])
		if(v!=fa) solve(v,u,x+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			a[i].clear();
		int u,v;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int ans=inf;
		for(S=0;S<(1<<n);S++){
			if(__builtin_popcount(S)!=k) continue;
			int cnt=0;
			memset(vis,false,sizeof(vis));
			for(int i=1;i<=n;i++)
				if(((S>>(i-1))&1)&&!vis[i])
					dfs(i,0),cnt++;
			if(cnt>2) continue;
			int ret=0;
			for(int i=1;i<=n;i++){
				t=inf;
				solve(i,0,0);
				ret=max(ret,t);
			}
			ans=min(ans,ret);	
		}
		cout<<ans<<endl;
	}

	return 0;
}

