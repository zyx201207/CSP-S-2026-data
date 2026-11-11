#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    int a[1000005] = {0}, used[1000005] = {0}, ans[1000005] = {0};
    for (long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (long long i = 1; i <= n; i++){
        used[i] = 1;
        for (long long j = 1; j <= n; j++){
            if (a[j] == a[i] && used[j] == 1){
                for (long long z = 1; z < i; z++){
                    used[z] = 2;
                }
            }
        }
        for (long long j = 1; j <= m; j++){
            for (long long z = 1; z <= n; z++){
                if (a[z] == j && used[z] == 1){
                    ans[j] += 1;
                }
            }
        }
    }
    for (long long i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
