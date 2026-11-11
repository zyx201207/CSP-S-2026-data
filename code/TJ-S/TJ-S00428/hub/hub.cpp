#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
int c,t,n,k;
vector<int>g[N];
int d[N];
int a[N],f[N];
vector<int> se[N];
void dfs(int num,int x,int fa){
	f[x]=fa;
	se[num].push_back(x);
	for(auto u:g[x]){
		if(u==fa){
			continue;
		}
		++a[num+1];
		dfs(num+1,u,x);
	}
}
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		g[i].clear();
		se[i].clear();
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		++d[u],++d[v];
	}
	int ma=0,p=0;
	for(int i=1;i<=n;++i){
		if(d[i]>ma){
			ma=d[i];
			p=i;
		}
	}
	a[1]=1;
	dfs(1,p,-1);
	int tot=0;
	for(int i=2;i<=n;++i){
		a[i]+=a[i-1];
		if(k<=a[i]){
			tot=i;
			break;
		}
	}
	int ans=k-1;
	for(int i=tot;i>=2;--i){
		for(int j=1;j<se[i].size();++j){
			if(f[j]!=f[j-1]){
				ans=min(2*(tot-1),ans);
				cout<<ans<<"\n";
				return;
			}
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		Solve();
	}
	return 0;
} 
