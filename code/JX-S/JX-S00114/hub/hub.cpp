#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 10;
int c,t;
struct node{
    int t,nex;
}e[N << 1];
int head[N],tot,n,kk,siz[N],dep[N],dis[N],summ1 = 0,summ2 = 0;
bool ss[N];
void add(int x,int y){
    e[++tot].t = y;
    e[tot].nex = head[x];
    head[x] = tot;
}
void dfs1(int x,int fa){
    if (ss[x] == 0) return ;
    summ1++;
  //  if (x == 1) cout << 111112;
    for (int i = head[x]; i ; i = e[i].nex){
        int v = e[i].t;
        if (v == fa) continue;
        if (ss[v] == 0) continue;
        dfs1(v,x);
    }
}
void dfs2(int x,int fa){
    if (ss[x] == 0) return ;
    summ2++;
    for (int i = head[x]; i ; i = e[i].nex){
        int v = e[i].t;
        if (v == fa) continue;
        if (ss[v] == 0) continue;
        dfs2(v,x);
    }
}
void dfs(int x,int fa){
    dep[x] = dep[fa] + 1;
    dis[x] = min(dis[x],dep[x] - 1);
    for (int i = head[x]; i ; i = e[i].nex){
        int v = e[i].t;
        if (v == fa) continue;
        dfs(v,x);
    }
}
void solve(){
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1; i <= tot; i++) e[i].t = e[i].nex = 0;
    tot = 0;
    cin >> n >> kk;
    for (int i = 1; i <= n - 1; i++){
        int u,v;
        cin >> u >> v;
        add(u,v),add(v,u);
    }
    int ans = 1e9;
    for (int i = 0; i < (1 << n); i++){
        int x = (((1 << n) - 1)^i);
        for (int j = x; j >= 0; j = ((j - 1)&x)){
            int sum1 = 0,sum2 = 0;
            summ1 = 0,summ2 = 0;
            for (int k = 1; k <= n; k++) ss[k] = 0;
            for (int k = 1; k <= n; k++){
                if ((i&(1 << (k - 1))) > 0) sum1++,ss[k] = 1;
                if ((j&(1 << (k - 1))) > 0) sum2++,ss[k] = 1;
            }    
            if (sum1 + sum2 == kk){
                summ1 = 0,summ2 = 0;
                for (int k = 1; k <= n; k++){
                    if ((i&(1 << (k - 1))) > 0){
                        dfs1(k,0);
                        break;
                    }
                }
                for (int k = 1; k <= n; k++){
                    if ((j&(1 << (k - 1))) > 0){
                        dfs2(k,0);
                        break;
                    }
                }
                if (summ1 = sum1 && summ2 == sum2){
                    for (int k = 1; k <= n; k++) dis[k] = 1e9;
                    for (int k = 1; k <= n; k++){
                        if ((i&(1 << (k - 1))) > 0 || (j&(1 << (k - 1))) > 0){
                            dfs(k,0);
                          //  if (i == 6 && j == 512) cout << k << " ";
                            //for (int d = 1; d <= n; d++) dis[]
                        }
                    }
                    int minn = 0;
                    for (int k = 1; k <= n; k++) minn = max(minn,dis[k]);
                    ans = min(ans,minn);
                   // if (minn == 1) cout << i << " " << j << '\n';
                }
            }
            if (j == 0) break;
        }
    }
    cout << ans << '\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        solve();
    }
    return 0;
}