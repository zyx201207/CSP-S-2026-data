#include<bits/stdc++.h>
#define FL(a, b, c) for(int a = (b), a##end = (c); a <= a##end; ++a)
#define FR(a, b, c) for(int a = (b), a##end = (c); a >= a##end; --a)
#define endl '\n'
#define fr first
#define se second
#define int long long
using namespace std;
constexpr int N = 1e6 + 10;
struct A{
    int s, l, r, op;
};
int n, d, a[N], R[N], L[N], ans, vis[N], w[N], CCC;
A e[N];
void sol(int*a, int n){
    // int s = 0, g = 0;
    FL(i, 0, n + 1)
    w[i] = 0, e[i].s = -1, e[i].op = 0;
    // FR(i, n - 1, 1){
    //     int x = i, y = i + 1;
    //     if(R[x] != R[y])vis[x] = R[x];
    //     else vis[x] = n;
    // }
    FL(i, 1, n)
    {
        // cout << i << " " << w[i] << " " << L[i] << "*" << w[L[i]] << " ";
        int &s = (w[i] += w[L[i]] + 1);
        // cout << s << endl;  
        if (R[i] <= i + 1)
            continue;
        int x = R[i], y = R[i] - 1;
        // cout << x << " " << y << " " << R[x] << " " << R[y] << " " << s << endl;
        if (R[x] == R[y])
        {
            e[i].s = s, e[i].op = 1;
            if (R[y - 1] != R[y])
                e[i].s = s, e[i].l = R[y - 1] + 1, e[i].r = n;
            else
                e[i].l = R[y - 1] + 1, e[i].r = e[i].l - 1; 
            // cerr << R[y - 1] + 1 << " " << s << endl;
            // s = 0;
        }
        else
        {
            e[i].l = R[y - 1] + 1, e[i].r = R[y], e[i].s = s;
            // f[R[y - 1] + 1] += s - g[i], f[R[y] + 1] -= s - g[i];
            w[R[y] + 1] += s, s = 0;
        }
    }
    FR(i, n, 1){
        if(e[i].s < 0)continue;
        int x = R[i], y = R[i] - 1;
        if(e[x].s > 0){
            if(e[x].op)e[i].r = min(e[i].r, R[R[x]] - 1);
            else e[i].l = max(e[i].l, e[x].r);
        }
        x = y;
        if(e[x].s > 0){
            if(e[x].op)
            e[i].r = min(e[i].r, R[R[x]] - 1);
            else
                e[i].l = max(e[i].l, e[x].r);
        }
        // }
        // cout << i << " ";
        // cout << e[i].l << " " << e[i].s << " " << e[i].r << endl;
        ans += e[i].s * max(e[i].r - e[i].l + 1, 0LL);
    }
}
void ___(){
    cin >> n >> d, R[n] = n, L[0] = 1, ans = 0;
    FL(i, 1, n){
        cin >> a[i], L[i] = L[i - 1];
        while(a[i] - a[L[i]] > d)
            L[i]++;
    }
    FR(i, n - 1, 1){
        R[i] = R[i + 1];
        while(a[R[i]] - a[i] > d)
            R[i]--;
    }
    // FL(i, 1, n)
        // cout << R[i] << " \n"[i == iend];
    // FL(i, 1, n)
    //     cout << L[i] << " \n"[i == iend];
    int lst = 0;
    FL(i, 1, n)
    if (R[i] == i)
        sol(a + lst, i - lst), lst = i;
    cout << ans << endl;
}
namespace sol1{
    int dis[N], ans, g[N];
    vector<pair<int, int>> e[N];
    unordered_map<int, int> mp;
    void get(int x)
    {
        priority_queue<int, vector<int>, greater<int>> p, q;
        mp.clear();
        FL(i, 1, n + 1)
        dis[i] = 1e9, g[i]=0,
        e[i].clear();
        dis[x] = 0, e[R[x] + 1].emplace_back(0, 1), mp[0]++, p.emplace(0);
        // if(R[x] == x)return;
        // cerr << x << endl;
        FL(i, x + 1, n)
        {
            for (auto z : e[i])
                q.emplace(z.fr), mp[z.fr] -= z.se; //, cout << z.fr << " " << z.se << "*" << endl;
            while (q.size() && p.top() == q.top())
                q.pop(), p.pop();
            // cerr << p.size() << " " << q.size() << endl;
            if (!p.size())
                return;
            dis[i] = p.top() + 1;
            // cout << dis[i] << " " << i << " " << x << " " << mp[dis[i] - 1] << endl;
            if (mp[dis[i] - 1] == 2)
                ans++, g[i] = 1;
            mp[dis[i]] += mp[dis[i] - 1], p.emplace(dis[i]), e[R[i] + 1].emplace_back(dis[i], mp[dis[i] - 1]);
        }
}
void ___(){
    cin >> n >> d, R[n] = n, L[0] = 1, ans = 0;
    FL(i, 1, n){
        cin >> a[i], L[i] = L[i - 1];
        while(a[i] - a[L[i]] > d)
            L[i]++;
    }
    // if(CCC == 13 || CCC == 14){
        // cout << (n) * (n - 1) / 2 <<? endl;
        // return;
    // }
    FR(i, n - 1, 1){
        R[i] = R[i + 1];
        while(a[R[i]] - a[i] > d)
            R[i]--;
    }
    FL(i, 1, n){
        get(i);
        if(CCC == 11 || CCC == 12){
            FL(i, 2, n)if(g[i]){
                ans += n - i;
            }
            break;
        }
    }
    cout << ans << endl;
    // cerr << "*";
}
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int t, c;
    cin >> c >> t, CCC = c;
    while(t--){
        if(c <= 12)
            sol1::___();
        else
        ___();
    }   
}