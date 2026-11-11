#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long m, a[510000], s[510000];

int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    for (int i = 1; i < n; i++){
        s[i] = a[i + 1] - a[i];
    }
    bool ok = true;
    for (int i = 2; i < n; i++)
        if (s[i] != s[i - 1]){
            ok = false;
            break;
        }
    if (ok == true){
        long long x = m;
        int t = s[1];
        while (x >= t){
            x -= t;
            ans++;
            t += s[1];
        }
        printf("%d", ans + 1);
        return 0;
    }
    for (int i = 1; i <= n; i++){
        long long x = m;
        int sum = 0;
        for (int j = i - 1; j >= 1; j--){
            if ((a[i] - a[j]) <= x){
                x += (a[j] - a[i]);
                sum++;
            }
        }
        sum++;
        for (int j = i; j < n; j++){
            if (s[j] == 0){
                sum++;
            }else
                break;
        }
        if (sum > ans)
            ans = sum;
    }
    printf("%d", ans);
    return 0;
}
