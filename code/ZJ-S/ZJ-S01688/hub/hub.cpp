#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,k,col[N],d[N],bl,a[N],ans;
bool vis[N],used[N];
queue<int> q;
vector<int> g[N];
void dfs(){
	for(int i=1;i<=n;i++)d[i]=1e18;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			d[i]=0;
			q.push(i);
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int v:g[u]){
					if(!vis[v]&&d[u]+1<d[v]){
						d[v]=d[u]+1;
						q.push(v);
					}
				}
			}
		}
	}
}
void check(){
	for(int i=1;i<=n;i++)col[i]=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&!col[i]){
			col[i]=++bl;
			q.push(i);
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int v:g[u]){
					if(vis[v]&&!col[v]){
						col[v]=col[u];
						q.push(v);
					}
				}
			}
		}
	}
}
void pailie(int x){
	if(x>k){
		for(int i=1;i<=k;i++){
			vis[a[i]]=1;
		}
		bl=0;
		check();
		dfs();
		for(int i=1;i<=k;i++)vis[a[i]]=0;
		if(bl>2)return ;
		int cnt=0;
		for(int i=1;i<=n;i++)cnt=max(cnt,d[i]);
		ans=min(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			a[x]=i;
			used[i]=1;
			pailie(x+1);
			used[i]=0;
		}
	}
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=1e18;
	pailie(1);
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//18:05 gei D pan gao zha le dian nao bei po chong qi xi xi xi  
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
