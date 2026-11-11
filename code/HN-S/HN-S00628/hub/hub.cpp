#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, dep[11], ans, k, x, y;
bool vis[11], vst[11];
vector<int> vec[11];

template<typename type>
inline void read(type &x){
    x=0;bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    flag?x=-x:0;
}
template<typename type>
inline void write(type x, bool mode=1){
    x<0?x=-x,putchar('-'):0;static short Stack[50],Top(0);
    do Stack[++Top]=x%10,x/=10; while(x);
    while(Top) putchar(Stack[Top--]|48);
    mode?putchar('\n'):putchar(' ');
}
void bfs(int x){
    vst[x] = 1;
    for( int i : vec[x] ){
        if(vis[i] && !vst[i]) bfs(i);
    }
}
void mfs(int x, int o, int d){
    dep[x] = min(dep[x], d);
    for( int i : vec[x] ){
        if(i == o) continue;
        mfs(i, x, d + 1);
    }
}
void dfs(int x){
    if(x > n){
        int cnt = 0;
        for( int i = 1; i <= n; i++ ){
            if(vis[i]) cnt++;
        }
        if(cnt != k) return;
        memset(vst, 0, sizeof(vst));
        cnt = 0;
        for( int i = 1; i <= n; i++ ){
            if(!vst[i] && vis[i]) bfs(i), cnt++;
        }
        if(cnt >= 3) return;
        memset(dep, 0x3f, sizeof(dep));
        for( int i = 1; i <= n; i++ ){
            if(vis[i]) mfs(i, 0, 0);
        }
        int mx = 0;
        for( int i = 1; i <= n; i++ ) mx = max(mx, dep[i]);
        ans = min(ans, mx);
        return;
    }
    dfs(x + 1);
    vis[x] = 1;
    dfs(x + 1);
    vis[x] = 0;
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    read(c), read(t);
    while(t--){
        ans = 1e18;
        read(n), read(k);
        for( int i = 1; i <= n; i++ ) vec[i].clear();
        for( int i = 1; i < n; i++ ){
            read(x), read(y);
            vec[x].emplace_back(y);
            vec[y].emplace_back(x);
        }
        dfs(1);
        write(ans);
    }
    return 0;
}