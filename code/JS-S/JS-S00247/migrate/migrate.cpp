#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 100;
const ll inf = 1e7 + 10;

int c, t;
ll n, d;
ll x[N];
int cnl[N];
int cnr[N];

        //The total time depend on the ...
        //The way we chose must add up more quickly than O(n)...
        //Is DP?
        //In fact, we can use Segment tree?
        //Then how to sum?
        //For each point i
        // j can...
        // link with it?
        // It seems that we need to make some predict
/*
such as ...
A - B - C
Oh, that's the min ad the next min !
?
then,,,
we can't make it.
...

*/

///How to calculate !!!

ll dis[5000 + 100], nxdis[N];
vector <int> g[5000 + 100];
using Pr = pair<ll, int>;
void dijkstra (int s) {
    fill (dis, dis + N, inf);
    fill (nxdis, nxdis + N, inf);
    priority_queue <Pr, vector <Pr>, greater <Pr>> pq;
    dis[s] = 0;
    pq.push (make_pair(0, s));

    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (tmp.first > dis[u]) continue;

        for (auto v : g[u]) {
            if (dis[v] == dis[u] + 1) {
                nxdis[v] = dis[v];
            }
            else if (dis[v] > dis[u] + 1) {
                nxdis[v] = dis[v];
                dis[v] = dis[u] + 1;
                pq.push (make_pair(dis[v], v));
            }
            else {  //dis[v] < dis[u] + 1
                nxdis[v] = min (nxdis[v], dis[u] + 1);
            }
        }
    }
}


void work1 () {
    while (t--) {
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; ++ i) {
            cin >> x[i];
        }
        for (int i = 1; i <= n; ++ i) {
            for (int j = i + 1; j <= n; ++ j) {
                if (x[j] - x[i] > d) break;
                g[i].push_back (j);
            }
            //for (int j = i - 1; j >= 1; -- j) {
            //    if (x[i] - x[j] > d) break;
            //    g[i].push_back (j);
            //}
        }
        for (int i = 1; i <= n; ++ i) {
            dijkstra (i);
            cout << i << " :\n";
            for (int j = 1; j <= n; ++ j) {
                cout << dis[j] << ' ' << nxdis[j] << '\n';
            }
            for (int j = i + 1; j <= n; ++ j) {
                if ((j != i) && (dis[j] == nxdis[j]) && (dis[i] < n)) ans++;
            }
        }
        cout << ans << '\n';
    }
    return;
}

void work2 () {
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++ i) {
            cin >> x[i];
        }
        int ts = d / (x[2] - x[1]);
        if (ts > 0) {
            for (int i = 1; i <= n; ++ i) {

            }
        }
        else {
            cout << 0 << '\n';
            return ;
        }
    }
}

int main () {
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin >> c >> t;
    if (c <= 10) work1();

    else if (c == 11) work2 ();

    return 0;
}
