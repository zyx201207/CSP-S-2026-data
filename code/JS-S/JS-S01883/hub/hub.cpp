#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e6 + 1;

ll c, t;
ll n, k;
vector<ll> g[maxn];
ll rt;
set<ll> s;
ll cnt = 0;
ll ans = 0x3f3f3f3f3f3f3f3f;
/*
ll check(ll cur, ll fa){
    if(s.insert(cur) == false){
        return 1;
    }
    s.erase(cur);
    for(ll i = 0; i < g[cur].size(); i++){
        ll ch = g[cur][i];
        if(ch == fa){
            continue;
        }
        return check(ch, fa) + 1;
    }
}
void dfs(ll cur, ll fa, ll hubn, ll snum){
    if(hubn == k){
        cnt = 0;
        for(int i = 1; i <= n; i++){
            if(s.insert(i) == true){
                s.erase(i, -1);
                d[i] = check(i);
                cnt = max(cnt, d[i]);
                if(cnt >= ans){
                    break;
                }
            }
        }
        ans = min(ans, cnt);
        return ;
    }
    for(ll i = 0; i < g[cur].size(); i++){
        ll ch = g[cur][i];
        if(ch == fa){
            continue;
        }
        if(snum == 2){
            s.insert(cur)
            dfs(ch, cur, hubn + 1, snum1);
            s.erase(cur);
            continue;
        }
        dfs(ch, cur, hubn, snum);
        s.insert(cur)
        if(s.insert(fa) == false){
            dfs(ch, cur, hubn + 1, snum);
        }else{
            dfs(ch, cur, hubn + 1, snum + 1);
        }
        s.erase(cur);
    }
}
*/
void solve(ll testnum, ll casenum){
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
        g[i].clear();
    }
    for(ll i = 1; i <= n - 1; i++){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(ll i = 1; i <= n - 1; i++){
        if(g[i].size() == 1){
            rt = i;
            break;
        }
    }
    ans = 0x3f3f3f3f3f3f3f3f;
    //dfs(rt, 0, 0);
    cout << casenum << "\n";
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> t;
    for(ll casei = 1; casei <= t; casei++){
        solve(c, t);
    }
    cout << flush;
    return 0;
}
