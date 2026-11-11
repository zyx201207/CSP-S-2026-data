#include<bits/stdc++.h>
using namespace std; 
const int N=1e6+5;
vector<int> v[N];
int n,k;
int cnt;
int dis[N];
bool vis[N];
int dep[N];
void dfs2(int p,int fa){
	dep[p]=dep[fa]+1;
	dis[p]=min(dis[p],dep[p]);
	for(int nxt:v[p]){
		if(nxt!=fa){
			dfs2(nxt,p);
		}
	}
}
bool check(){-
	int cnt=k;
	for(int i=1;i<=n;i++){
		for(int nxt:v[i]){
			if(vis[nxt]&&vis[i]&&i<nxt){
				cnt--;
			}
		}
	}
	if(cnt<=2)
		return 1;
	else
	    return 0;
}
int mn=INT_MAX;
void dfs(int p){
//	cout<<p<<" ";
	if(p==n+1){
		if(cnt==k){
			if(check()){
				for(int i=1;i<=n;i++){
					dis[i]=INT_MAX;
				} 
				dep[0]=-1;
				for(int i=1;i<=n;i++){
					if(vis[i]==1){
						dfs2(i,0); 
					} 
				}
				int mx=0;
				for(int i=1;i<=n;i++){
					mx=max(mx,dis[i]);
				}
				mn=min(mn,mx);
			}
		}
		return ;
	} 
	if(cnt!=k){
		vis[p]=1;
		cnt++;
		dfs(p+1);
		cnt--;
		vis[p]=0;
	}
	dfs(p+1);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		v[i].clear();
		dis[i]=INT_MAX;
	} 
	mn=INT_MAX;
	for(int i=1;i<n;i++){
		int s,e;
		cin>>s>>e; 
		v[s].push_back(e);
		v[e].push_back(s);
	}
	dfs(1);
	cout<<mn<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t; 
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}

