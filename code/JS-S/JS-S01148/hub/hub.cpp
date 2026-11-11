#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,lN=25;
int n,k;
vector <int> G[N];
bool vis[N];
void dfs(int p,int can) {
    vis[p]=true;
    for (int i=0;i<G[p].size();i++) if (!vis[G[p][i]] && can&(1ll<<G[p][i])) dfs(G[p][i],can);
}
int mem[N];
int get(int p,int fa,int can) {
    if (mem[p] || (can&(1<<p))) return mem[p];
    int res=0x7fffffff;
    for (int i=0;i<G[p].size();i++) if (G[p][i]!=fa) res=min(get(G[p][i],p,can)+1,res);
    return res<20?(mem[p]=res):res;
}
void solve() {
    cin>>n>>k;
    for (int i=1,u,v;i<n;i++) {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=0x7fffffff;
    for (int i=0;i<(1<<(n+1));i+=2) {
        int cnt=0,ii=i;
        while (ii) ii-=ii&-ii,cnt++;
        if (cnt!=k) continue;
        cnt=0;
        for (int j=1;j<=n;j++) {
            if (!vis[j] && i&(1<<j)) dfs(j,i),cnt++;
        }
        if (cnt<3) {
            int res=0;
            for (int j=1;j<=n;j++) {
                if (!(i&(1ll<<j))) res=max(get(j,-1,i),res);
            }
            ans=min(ans,res);
        }
        for (int i=1;i<=n;i++) vis[i]=false,mem[i]=0;
    }
    cout<<ans<<endl;
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--) solve();
    return 0;
}
/*
get 5 to 15 points is enough for T4.
*/
/*
I am ROBIN's DOG!!!
Miss ROBIN!!! I am your fans!!!
This is true music!
*/