#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
const ll INF = 2e18;
int t, n, tot;
ll d, x[N], b[N];
bool vis[N];
vector < pair < int, int > > v;
struct node{
    int l, r;
    node(int _l = 0, int _r = 0): l(_l), r(_r) {}
    bool operator< (const node &b) const{
        if (r - l != b.r - b.l){
            return r - l > b.r - b.l;
        }
        if (l != b.l){
            return l < b.l;
        }
        return r < b.r;
    }
}p[N];
int query1(ll val){
    int l = 1, r = n;
    while (l < r){
        int mid = (l + r) >> 1;
        if (x[mid] < val){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;
}
int query2(ll val){
    int l = 1, r = n;
    while (l < r){
        int mid = (l + r + 1) >> 1;
        if (x[mid] > val){
            r = mid - 1;
        }
        else{
            l = mid;
        }
    }
    return l;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%*d%d", &t);
    while (t--){
        tot = 0;
        v.clear();
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++){
            scanf("%lld", &x[i]);
        }
        x[0] = -INF, x[n + 1] = INF;
        for (int i = 1; i < n; i++){
            b[i] = x[i + 1] - x[i];
        }
        bool f1 = true;
        for (int i = 1; i < n; i++){
            if (b[i] != b[1]){
                f1 = false;
                break;
            }
        }
        if (f1){
            if (d <= b[1] || d >= x[n] - x[1]){
                printf("0\n");
            }
            else{
                printf("%lld\n", n + 1 - d / b[1] * 2);
            }
            continue;
        }
        if (x[n] - x[1] <= d){
            printf("0\n");
            continue;
        }
        int cnt2 = 0;
        for (int i = 1; i <= n; i++){
            if (x[i] - x[1] <= d && x[n] - x[i] <= d){
                cnt2++;
            }
        }
        if (cnt2 >= 2){
            printf("0\n");
            continue;
        }
        if (cnt2 == 1){
            printf("1\n");
            continue;
        }
        for (int i = 1; i < n; i++){
            int l = query1(x[i + 1] - d);
            if (l >= i || x[l] < x[i + 1] - d){
                continue;
            }
            int r = query2(d + x[i]) - 1;
            if (r <= i || x[r + 1] > d + x[i]){
                continue;
            }
            if (x[r + 1] - x[l] < d){
                continue;
            }
            p[++tot] = node(l, r);
            // printf("why i=%d, %d %d\n", i, l, r);
        }
        for (int i = 1; i <= tot; i++){
            vis[i] = false;
        }
        for (int i = 1; i <= tot; i++){
            for (int j = 1; j <= tot; j++){
                if (i == j){
                    continue;
                }
                if (p[i].l <= p[j].l && p[j].r <= p[i].r){
                    vis[j] = true;
                }
                if (p[j].l <= p[i].l && p[i].r <= p[j].r){
                    vis[i] = true;
                }
            }
        }
        for (int i = 1; i <= tot; i++){
            if (!vis[i]){
                v.push_back(make_pair(p[i].l, p[i].r));
                // printf("chk %d %d\n", p[i].l, p[i].r);
            }
        }
        int ans = 0;
        for (int l = 1; l < n; l++){
            for (int r = l + 1; r < n; r++){
                bool flag = true;
                for (int i = l; i <= r; i++){
                    if (b[i] > d){
                        flag = false;
                        break;
                    }
                }
                if (!flag){
                    continue;
                }
                int cnt = 0;
                for (auto i : v){
                    if (l <= i.first && i.second <= r){
                        cnt++;
                    }
                }
                if (cnt == 1){
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}