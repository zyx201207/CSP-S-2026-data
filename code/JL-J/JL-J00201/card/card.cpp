#include <bits/stdc++.h>
using namespace std;
int n, m, a[500001], lst[300001], ans[300001];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        lst[a[i]] = max(lst[a[i]], i);
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++){
            ans[a[j]]++;
            if (j != lst[a[j]])
                j = lst[a[j]];
        }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
