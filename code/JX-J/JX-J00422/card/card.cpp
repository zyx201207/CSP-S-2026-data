#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n, m;
int a[N];
int p[N];
bool pa[N];
int paa[N];
int ans[N];

int main () {
    freopen("card.in", "r", stdin);
    freopen("card,out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(!pa[p[j - i]]) {
                p[j - i] = a[i];
                pa[p[j - i]] = 1;
                paa[p[j - i]] = j - i;
            }
            else {
                fill(p + j - i, p + n + 1, 0);
                p[j - i] = a[i];
            }
            ans = p[j - i];
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}