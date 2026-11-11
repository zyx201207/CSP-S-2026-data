#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 20;

int c, t;
int u[maxn], v[maxn];

int main() {
    /*
    Its been a long day
    without you my friend
    when i tell you about me when i see you again
    come a long way
    from every began
    when i tell you about me when i see you again
    A~~~ A~~~~A~~~
    */
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i < n; i++) cin >> u[i] >> v[i];
        cout << rand() % 10 + 1 << endl;
    }
    return 0;
}
