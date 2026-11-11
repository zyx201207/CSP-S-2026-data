#include<bits/stdc++.h>
#define ls(u) (u << 1)
#define rs(u) ((u << 1) | 1)
using namespace std;
typedef long long ll;
#define PLL pair<ll, ll>
#define fi first
#define se second
const int N = 2e6 + 10, MAXN = 5009, INF = 1e9;
int n, h[N], pre[N];
ll d, x[N]; 
struct Node{
    ll val, pl;
    friend Node operator + (Node x, Node y){
        if(x.val < y.val) return x;
        if(x.val > y.val) return y;
        return {x.val, x.pl + y.pl};
    }
}f[N], p[N << 2];
const Node Empty = {INF, 0};
void up(int u){
    p[u] = p[ls(u)] + p[rs(u)];
}
void modify(int u, int l, int r, int x, Node t){
    if(l == r) return (void)(p[u] = t);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(ls(u), l, mid, x, t);
    else modify(rs(u), mid + 1, r, x, t);
    up(u);
}
Node query(int u, int l, int r, int x, int y){
    if(y < x) return Empty;
    if(x <= l && r <= y) return p[u];
    int mid = (l + r) >> 1;
    Node ans = Empty;
    if(x <= mid) ans = ans + query(ls(u), l, mid, x, y);
    if(y > mid) ans = ans + query(rs(u), mid + 1, r, x, y);
    return ans;
}
void build(int u, int l, int r){
    p[u] = Empty;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(ls(u), l, mid);
    build(rs(u), mid + 1, r);
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int test_id, T;
    scanf("%d%d", &test_id, &T);
    while(T--){
        scanf("%d%lld", &n, &d);
        for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
        int l = 1;
        for(int i = 1; i <= n; i++){
            while(l <= i && x[i] - x[l] > d) l++;
            pre[i] = l;
            // printf("pre[%d] = %d\n", i, pre[i]);
        }
        if(n <= 5000){
            ll ans = 0;
            for(int u = 1; u <= n; u++){
                f[u] = {0, 1};
                p[0] = Empty;
                modify(1, 1, n, u, f[u]);
                for(int v = u + 1; v <= n; v++){
                    f[v] = query(1, 1, n, pre[v], v - 1);
                    f[v].val++;
                    modify(1, 1, n, v, f[v]);
                }
                build(1, 1, n);
                for(int v = u + 1; v <= n; v++) if(f[v].pl == 2) ans++;
            } 
            printf("%lld\n", ans);
        }else{
            f[1] = {0, 1};
            p[0] = Empty;
            build(1, 1, n);
            modify(1, 1, n, 1, f[1]);
            for(int i = 2; i <= n; i++){
                f[i] = query(1, 1, n, pre[i], i - 1);
                f[i].val++;
                modify(1, 1, n, i, f[i]);
            }
            // for(int i = 1; i <= n; i++) printf("%lld ", f[i].pl);
            // putchar(10);
            vector<int> cw;
            cw.clear();
            for(int i = 1; i <= n; i++){
                if(f[i].pl == 2) cw.push_back(i);
            }
            // for(int i : cw) printf("%d ", i);
            // putchar(10);
            int len = cw.size();
            ll ans = 0;
            // printf("be = %d en = %d\n", be, en);
            int l = len - 1;
            for(int i = 1; i <= n; i++){
                while(l >= 0 && i + cw[l] - 1 > n) l--; 
                if(l < 0) break;
                ans += l + 1;
            }
            printf("%lld\n", ans);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}