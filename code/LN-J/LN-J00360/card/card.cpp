#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, m, c[maxn], a[maxn], t[maxn];
stack <int> s;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(!a[c[j]]) s.push(c[j]), a[c[j]] = 1;
            else {
                while(s.top() != c[j]) a[s.top()] = 0, s.pop();
                if(s.top() != c[j]) s.push(a[j]), a[c[j]] = 1;
            }
        }
        for(int j = 1; j <= m; j++) t[j] += a[j], a[j] = 0;
    }
    for(int i = 1; i <= m; i++) cout << t[i] << ' ';
    return 0;
}
