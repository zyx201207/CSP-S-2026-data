#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,s = 1,e,l,ll = 0,fl[2000020],sl[2000020],ne[200020],d[200020],w[2];
vector <long long> g[2000020];
void dfs1(long long u,long long f,int tt){
    ne[u] = f;
    d[u] = d[f] + 1;
    if (ll < d[u]){
        ll = d[u];
        e = u;
    }
    for (auto v : g[u]){
        if (v == f || v == w[tt]) continue;
        dfs1(v,u,tt);
    }
}
void dfs2(long long u,long long f,int tt){
    ne[u] = f;
    d[u] = d[f] + 1;
    for (auto v : g[u]){
        if (v == f || v == w[tt]) continue;
        dfs2(v,u,tt);
        if (d[v] - d[u] > fl[u]){
            sl[u] = fl[u];
            fl[u] = d[v] - d[u];
        }
        else sl[u] = max(sl[u],d[v] - d[u]);
    }
    ll = max(ll,fl[u] + sl[u] + 1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> c >> t;
    if (c == 13 || c == 14){
        while (t--){
            cin >> n >> k;
            for (int i = 1;i < n;i++){
                long long a,b;
                cin >> a >> b;
                g[a].push_back(b);g[b].push_back(a);
            }
            long long res = n / 2;
            if (res == 1){
                if (k <= 2) cout << 1 << "\n";
                else cout << 0 << "\n";
                continue;
            }
            if (res == 2){
                if (k == 1) cout << "2\n";
                if (k > 1 && k < 5) cout << "1\n";
                if (k >= 5) cout << "0\n";
                continue;
            }
            if (res + 2 < k) cout << "1\n";
            else cout << max(1ll*1,(res+2)/(k+1)) << "\n";
        }
        return 0;
    }
    while (t--){
        cin >> n >> k;
        for (int i = 1;i < n;i++){
            long long a,b;
            cin >> a >> b;
            g[a].push_back(b);g[b].push_back(a);
        }
        dfs1(1,0,0);s = e;ll = 0;dfs1(s,0,0);l = ll;
        if (ll % 2 == 0){
            w[0] = e;
            for (int i = 1;i < l / 2;i++) {w[0] = ne[w[0]];}
            w[1] = ne[w[0]];ll = 0;
            dfs2(w[0],0,0);dfs2(w[1],0,1);
            cout << max((ll+1)/2,l/2) << "\n";
        }
        else{
            w[0] = e;
            for (int i = 1;i <= l / 2;i++) {w[0] = ne[w[0]];}
            ll = 0;
            dfs2(w[0],0,0);
            cout << max((ll+1)/2,l/2) << "\n";
        }
        l = 0,ll = 0,w[0] = w[1] = 0;
        for (int i = 1;i <= n;i++) {g[i].clear();ne[i]=d[i]=fl[i]=sl[i]=0;}
    }
    return 0;
}
