#include <bits/stdc++.h>
using namespace std;

int a[500001], c[300001], cnt[300001], w[300001];

int main(){
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);

    int n, m, top;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        top = 1;
        c[1] = a[i];
        for (int j = 1; j <= m; ++j){
            w[j] = 0;
        }
        w[a[i]] = 1;

        for (int j = i+1; j <= n; ++j){
            if (w[a[j]]){
                int wa = w[a[j]];
                for (int k = wa; k <= top; ++k){
                    w[k] = 0;
                }
                top = wa-1;
            }
            ++top;
            c[top] = a[j];
            w[a[j]] = top;
        }

        for (int j = 1; j <= top; ++j){
            ++cnt[c[j]];
        }
    }

    for (int i = 1; i <= m; ++i){
        cout << cnt[i] << ' ';
    }

    return 0;
}
