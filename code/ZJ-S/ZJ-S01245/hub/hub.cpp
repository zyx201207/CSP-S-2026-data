#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e6+10;
int C,T,n,k,ans;
vector<int> e[N];

int dep[1000];
bool tag[1000],vis[1000];
inline void dfs(int u,int fa,bool st){
	if(st==0&&!tag[u]) st=1;
	if(st==1&&tag[u]) return;
	if(st==0) vis[u]=1,dep[u]=0;
	else dep[u]=min(dep[u],dep[fa]+1);
	for(int v:e[u]){
		if(v==fa||vis[v]) continue;
		dfs(v,u,st);
	}
	return;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		for(int i=1;i<=n;++i) e[i].clear();
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		if(C<=3){
			ans=1000;
			for(int msk=0;msk<(1<<n);++msk){
				if(__builtin_popcount(msk)!=k) continue;
				for(int i=1;i<=n;++i) vis[i]=0,dep[i]=1000;
				for(int i=1;i<=n;++i) tag[i]=(msk>>(i-1)&1);
				int cnt=0;
				for(int i=1;i<=n;++i){
					if(tag[i]&&!vis[i]){
						++cnt;
						if(cnt>2) break;
						dfs(i,0,0);
					}
				}
				if(cnt>2) continue;
				int maxn=0;
				for(int i=1;i<=n;++i) maxn=max(maxn,dep[i]);
				ans=min(ans,maxn);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(k==n-1||k==n-2){
			cout<<1<<'\n';
			continue;
		}
		int m=n/2;
		cout<<ans<<'\n';
	}
	return 0;
}

