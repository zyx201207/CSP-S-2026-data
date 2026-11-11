#include<bits/stdc++.h>
using namespace std;
int a[500001], ans[500001];
bool tf[500001];
int main() {

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        fill(tf + i + 1, tf + n + 1, true);
        for(int j = i; j <= n; j++)
            for(int k = i; k < j; k++)
                if(a[k] == a[j] && tf[k]) {
                    for(int l = k; l < j; l++)
                        tf[l] = false;
                    break;
                }
        for(int j = i; j <= n; j++) {
            if(tf[j]) ans[a[j]]++;
        }
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    return 0;
}
