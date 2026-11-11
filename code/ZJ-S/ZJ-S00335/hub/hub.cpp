// code by Umbrella.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define mkp make_pair
namespace Umbrella{
	int n,k;
	vector<int> e[100005];
	int cho[100005],vis[100005];
	bool check(){
		int sum=0,c[10005];
		rep(i,1,n) c[i]=0;
		rep(i,1,k) if(!c[cho[i]]){
			sum++;
//			if(sum>2) break;
			queue<int> q;
			q.push(cho[i]);
			while(q.size()){
				int u=q.front(); q.pop();
				c[u]=1;
				for(auto v:e[u]){
					if(c[v]) continue;
					if(vis[v]) q.push(v);
				}
			}
		}
//		cout<<sum<<' ';
		return (sum>2?0:1);
	}
	int dep[10005],inc[22][100005];
	void dfs1(int u,int fa){
		dep[u]=dep[fa]+1;
		inc[0][u]=fa;
		rep(i,1,20){
			inc[i][u]=inc[i-1][inc[i-1][u]];
		}
		for(auto v:e[u]){
			if(v==fa) continue;
			dfs1(v,u);
		}
	}
	int LCA(int x,int y){
		if(dep[x]<dep[y]) swap(x,y);
		per(i,20,0){
			if(dep[inc[i][x]]>=dep[y]) x=inc[i][x];
		}
		if(x==y) return x;
		per(i,20,0){
			if(inc[i][x]!=inc[i][y]){
				x=inc[i][x],y=inc[i][y];
			}
		}
		return inc[0][x];
	}
	int ans=1e9;
	void dfs(int st){
		if(st>k){
			if(check()){
//				rep(i,1,k){
//					cout<<cho[i]<<" \n"[i==k];
//				}
//				ans++;
				int now=0;
				rep(i,1,n){
					if(!vis[i]){
						int w=1e9;
						rep(j,1,k){
							w=min(w,dep[i]+dep[cho[j]]-2*dep[LCA(i,cho[j])]);
						}
						now=max(w,now);
					}
				}
				ans=min(ans,now);
			}
			return ;
		}
		rep(i,cho[st-1]+1,n){
			if(vis[i]) continue;
			cho[st]=i;
			vis[i]=1;
			dfs(st+1);
			vis[i]=0;
		}
	}
	void solve(){
		cin>>n>>k;
		memset(dep,0,sizeof dep);
		memset(inc,0,sizeof inc);
		rep(i,1,n){
			e[i].clear();
		}
		rep(i,1,n-1){
			int u,v; cin>>u>>v;
			e[u].pb(v);
			e[v].pb(u);
		}
		ans=1e9;
		dfs1(1,0);
		dfs(1);
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,_T=1;
	cin>>c>>_T;
	while(_T--){
		Umbrella::solve();
	}
	return 0;
}
