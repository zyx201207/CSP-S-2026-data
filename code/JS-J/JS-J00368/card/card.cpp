#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int a[N], p[N], cnt[N], k[N], n, m;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--){
        if(p[a[i]] == 0) p[a[i]] = i;
    }
    k[n]++;
    for(int i = n - 1; i >= 1; i--){
        if(p[a[i]] == i) cnt[a[i]]++, k[i + 1]++;
        else k[p[a[i]]]++;
    }
    for(int i = 1; i <= n; i++){
        if(p[a[i]] == i) cnt[a[i]] += k[i], k[i + 1] += k[i];
        else k[p[a[i]]] += k[i];
    }
    for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
    return 0;
}
