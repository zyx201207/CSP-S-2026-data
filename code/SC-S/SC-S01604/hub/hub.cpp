#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,inf=1e18;
int c,T,n,k,fa[N],dist[N];
vector<int> g[N];
void dfs(int x,int f){
	for(int y : g[x]){
		if(y==f) continue;
		fa[y]=x;
		dfs(y,x);
	}
}
struct dui{
	int x,val;
	bool operator<(const dui &op)const{
		return val>op.val;
	}
};
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			u--,v--;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		dfs(0,-1);
		int res=inf;
		for(int s=0;s<(1ll<<n);s++){
			if(__builtin_popcount(s)!=k) continue;
			int cnt=0;
			for(int i=0;i<n;i++){
				if((s&(1ll<<i))==(1ll<<i)){
					if(i==0||((s&(1ll<<fa[i]))!=(1ll<<fa[i]))) cnt++;
				}
			}
			if(cnt>2) continue;
			priority_queue<dui> p;
			for(int i=0;i<n;i++){
				if((s&(1ll<<i))==(1ll<<i)){
					dist[i]=0;
					p.emplace((dui){i,0});
				}
				else dist[i]=inf;
			}
			while(!p.empty()){
				auto t=p.top();p.pop();
				int x=t.x;
				for(int y : g[x]){
					if(dist[y]>dist[x]+1){
						dist[y]=dist[x]+1;
						p.emplace((dui){y,dist[y]});
					}
				}
			}
			int now=0;
			for(int i=0;i<n;i++) now=max(now,dist[i]);
			res=min(res,now);
//			cout<<"s:"<<s<<'\n';
		}
		cout<<res<<'\n';
		for(int i=0;i<n;i++){
			fa[i]=0;
			g[i].clear();
		}
	}
	return 0;
}