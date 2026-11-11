#define dps 799
#define I dryer
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<ctime>
#include<vector>
using namespace std;
#define int long long
typedef vector<int> vv;
#define x first
#define y second
#define pb push_back
typedef pair<int,int> pii;
typedef vector<pii> vp;
typedef vector<vv> vvv;
const int N = 5010;
vv vt[N];
int dep[N];
int fa[N][20];
int a[N];
int ans = 109020000;
int dst[20];
int f[20];
inline int find(int x){
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
inline void merge(int x,int y){
    f[find(x)] = find(y);
}
int mp[20];
inline void check(int n){
    memset(dst,63,sizeof dst);
    memset(mp,0,sizeof mp);
    for(int i=1;i<=n;++i) f[i] = i;
    for(int i=1;i<=n;++i){
        if(a[i] == 0) continue;
        for(int j:vt[i]) if(a[j]) merge(i,j);
    }
    int cc = 0;
    for(int i=1;i<=n;++i) {
        if(a[i] == 0) continue;
        mp[find(i)] ++; if(mp[find(i)]==1) ++ cc;
    }
    if(cc > 2) return;
    queue<int> q; for(int i=1;i<=n;++i) {
        if(a[i]) q.push(i), dst[i] = 0;
    }
    while(q.size()){
        int p = q.front(); q.pop();
        for(int j:vt[p]){
            if(dst[j] > dst[p]+1) dst[j]=dst[p]+1, q.push(j);
        }
    }
    int as = 0;
    for(int i=1;i<=n;++i) as = max(as, dst[i]); ans = min(ans, as);
    // for(int i=1;i<=n;++i) cout << a[i] << ' '; cout << as << ' ' << ans << ' ' << cc << endl;
}
inline void dfs(int u,int now,int n){
    if(now<0) return;
    if(n + 1 == u){
        if(now != 0) return;
        return check(n);
    }
    dfs(u+1,now,n); a[u]=1; dfs(u+1,now-1,n); a[u]=0;
}
signed main(){
    freopen("hub.in","r",stdin); freopen("hub.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--){
        int n,k;cin>>n>>k;
        for(int i=1;i<n;++i){
            int x,y;cin>>x>>y; vt[x].pb(y); vt[y].pb(x);
        }
        dfs(1,k,n); cout << ans << endl; ans = 3658743287;
        for(int i=0;i<=n;++i) vt[i].clear();
    }
}