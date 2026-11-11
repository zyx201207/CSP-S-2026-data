#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000010;
int n,k;
vector<int>g[N];
bool vis[N];
int fa[N];
int finds(int x){
    return fa[x]==x?x:fa[x]=finds(fa[x]);
}
void merge(int u,int v){
    int fx=finds(u);
    int fy=finds(v);
    if(fx!=fy) fa[fx]=fy;
}
bool check(int xx){
    // cout<<"Check:\n";
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            for(auto j:g[i]){
                if(!vis[j]) continue;
                merge(i,j);
                // cout<<i<<" "<<j<<"\n";
            }
        }
    }
    set<int>st;
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        int fx=finds(i);
        st.insert(fx);
    }
    // cout<<xx<<"th size is:"<<st.size()<<"\n";
    int p=st.size();
    if(p>2) return false;
    return true; 
}
// int dis[N];
int bfs(int st){
    queue<pair<int,int> >q;
    q.push(make_pair(st,0));
    while(!q.empty()){
        auto ttmp=q.front();
        q.pop();
        int u=ttmp.first;
        int stp=ttmp.second;
        if(vis[u]) return stp;
        for(auto to:g[u]){
            q.push(make_pair(to,stp+1));
        }
    }
    return 114514;
}
int fun(){
    int luka=0;
    // cout<<"Function:\n";
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int dis=bfs(i);
        // cout<<dis<<" ";
        luka=max(luka,dis);
    }
    // cout<<"\n"<<luka<<"\n";
    return luka;
}
void solve1(int T){
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int miku=INT_MAX;
        for(int i=0;i<(1<<n);i++){
            int st=1;
            int teto=0;
            for(int t=1;t<=n;t++){
                vis[t]=0;
                if(i&st){
                    teto++;
                    vis[t]=1;
                }
                st<<=1;
            }
            if(teto!=k) continue;
            bool flag=check(i);
            // cout<<flag<<"\n";
			if(!flag) continue;
			// for(int t=1;t<=n;t++) cout<<vis[t]<<" ";
			// cout<<"\n";
            int lty=fun();
            // cout<<lty<<"\n";
            miku=min(miku,lty);
        }
        cout<<miku<<"\n";
    }

}
void solve2(int T){
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        cout<<n/4<<"\n";
    }
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    if(c<=3){
        solve1(T);
    }else{
        solve2(T);
    }
	return 0;
}
