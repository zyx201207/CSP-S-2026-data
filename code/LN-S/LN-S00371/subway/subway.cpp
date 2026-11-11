#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db cerr<<"fff"<<'\n';
#define int unsigned
/*
max_element()
accumulate()
priority_queue
*/

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,n,m,d,p;
    cin >> c >> n >> m >> d >> p;
    vector<int> wa(m);
    vector<vector<int>> a(n+m),t(n+m);
    for (int i = 0; i < m; i++) {
        cin >> wa[i];
    }
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int tt,aa;
            cin >> aa >> tt;
            aa+=n-1;
            a[i].push_back(aa);
            a[aa].push_back(i);
            t[i].push_back(tt);
            t[aa].push_back(tt);
        }
    }
    while(p--) {
        int x,y;
        cin >> x >> y;
        x--,y--;
        x+=n,y+=n;
        queue<int> q,w;
        vector<int> dis(n+m,0x3f3f3f3f);
        q.push(x);
        w.push(0);
        while(!q.empty()) {
            int qq = q.front(),ww = w.front();q.pop(),w.pop();
            if (dis[qq]<=ww)continue;
            dis[qq] = ww;
            for (int i = 0; i < a[qq].size(); i++) {
                q.push(a[qq][i]),w.push(ww+t[qq][i]);
            }
        }
        cout << wa[x-n]+wa[y-n]+dis[y] << endl;
    }
    return 0;
}
