#include<bits/stdc++.h>
using namespace std;
#define int long long //You will see the god unless you use long long
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m, maxn = 0, i, j;
    scanf("%lld %lld", &n, &m);
    long long a[n - 1] = {};
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    long long b[a[n - 1]][a[n - 1]] = {};
    for (i = 0; i < n; i++) for (j = i; j < n; j++) b[a[i]][a[j]] = a[j] - a[i];
    for (i = 0; i < n; i++){
        int sum = 0, num = 0;
        for (j = i; j >= 0; j--){
            if (sum + b[a[j]][a[i]] <= m){
                sum += b[a[j]][a[i]];
                num++;
            }
            else break;
        }
        maxn = max(maxn, num);
    }
    cout << maxn;
    fclose(stdin);
    fclose(stdout);
    //好像做出来了
    //洛谷uid:1630835
    return 0;
}
