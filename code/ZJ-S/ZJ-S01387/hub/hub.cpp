#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,k;
vector<int> G[N];
int dep[N],u1,u2;
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    for(auto v:G[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
    if(dep[u]>dep[u1]) u1=u;
}
int f[N],son[N];
void dfs2(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u]=fa;
    for(auto v:G[u]){
        if(v==fa) continue;
        dfs2(v,u);
    }
    if(dep[u]>dep[u2]) u2=u;
}
bool vis[N];
int mx[N],mmx;
void dfs3(int u,int dep){
	mmx=max(mmx,dep);
	vis[u]=1;
	for(auto v:G[u]){
		if(vis[v]) continue;
		dfs3(v,dep+1);
	}
}
vector<int> zhi;
bool check(int x){
	int cnt=0,mmx=-1;
	int flag=0,lst=-1,xxx=-1;
	for(int i=0;i<zhi.size();i++){
		if(mx[zhi[i]]>x) return 0;
		mmx=max(mmx+1,mx[zhi[i]]);
		if(mmx>=x){
			if(flag==2&&lst!=i-1) return 0;
			cnt++;
			if(i>0&&lst!=i-1) flag++;
			lst=i;
			mmx=0;
		}
		if(flag==2) {
			xxx=i;
			break;
		}
	}
	if(flag==2){
//		cout<<"ffsf "<<x<<' '<<xxx<<'\n';
		for(int i=xxx;i<zhi.size();i++){
			if(cnt<k) cnt++;
			else {
				xxx=i;
				break;
			}
		}
		int dis=zhi.size()-xxx-1;
		return dis<=x;
	}
	return cnt<=k;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) G[i].clear(),vis[i]=0;
    zhi.clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        G[u].push_back(v),G[v].push_back(u);
    }
    u1=0;dfs(1,0);
    u2=0;dfs2(u1,0);zhi.push_back(u2);
    for(int lst=u2,i=f[u2];i!=u1&&i!=0;i=f[i]){
    	zhi.push_back(i);
    	son[i]=lst;
    	vis[i]=vis[lst]=vis[f[i]]=1;
    	if(G[i].size()>=3) {
    		mmx=-1;
    		dfs3(i,0);
    		mx[i]=mmx;
		}
    	lst=i;
	}
	zhi.push_back(u1);
	int l=0,r=1e6,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) solve();
	return 0;
}
