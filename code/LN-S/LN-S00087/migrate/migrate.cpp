#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t,n,d;
struct island {
    ll x;
    ll cnt;
} is[2000005];

void bfs() {
    struct node {
        ll x;//pos
        ll s;//path len
    };
    queue<node> q;
    q.push({is[1].x,0});
    while (!q.empty()) {
        node t = q.front();
        for (int i=1;i<=n;i++) {
            if (abs(is[i].x - t.x) > d) break;
            if (is[i].cnt < t.s) continue;//跳过重复的部分
            q.push({is[i].x,t.s+1});
            is[i].cnt++;
        }
        q.pop();
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> t;
    while (t--) {
        cin >> n >> d;
        for (int i=1;i<=n;i++) cin >> is[i].x;
        bfs();
        int sum = 0;
        for (int i=1;i<=n;i++) {
            if (is[i].cnt == 2) sum++;
        }
        cout << sum << endl;
        memset(is,0,sizeof(is));
    }
    return 0;
}
