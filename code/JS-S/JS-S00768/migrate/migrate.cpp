#include <iostream>
#include <deque>
using namespace std;

long long ls[2000002];
int ne[2000001];
int len[2000001];

void man() {
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> ls[i];
    }
    ls[n + 1] = ls[n] + 1;
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && ls[i] - ls[q.front()] > d) {
            ne[q.front()] = i - 1;
            q.pop_front();
        }
        q.push_back(i);
    }
    while (!q.empty()) {
        ne[q.front()] = n;
        q.pop_front();
    }
    int now = ne[n];
    int cur = n;
    for (int i = n - 1; i >= 1; i--) {
        if (now != ne[i]) {
            //cerr << "break at " << i << endl;
            if (i + 1 != ne[i]) {
                for (int j = i + 1; j <= cur; j++) {
                    len[j] = cur - j + 1;
                }
                cur = i;
            }
            now = ne[i];
        }
    }
    for (int j = 1; j <= cur; j++) {
        len[j] = cur - j + 1;
    }
    long long ans = 0;
    ne[0] = -1;
    for (int i = 1; i <= n; i++) {
        int _ne = ne[i];
        int _nne = ne[_ne - 1];
        if (_nne <= _ne || ls[_nne + 1] - ls[_ne - 1] <= d) continue;
        else {
            ans += len[_nne];
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int t, _n;
    cin >> _n >> t;
    while (t--) man();
}
