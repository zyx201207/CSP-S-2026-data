#include<bits/stdc++.h>
using namespace std;
int last[300010], n, m, a[500010];
long long sum[300010];
inline void solve(int now){
    while(now <= n){
        sum[a[now]]++;
        if(now == last[a[now]]){
            now++;
        }
        else now = last[a[now]] + 1;
    }
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        last[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        solve(i);
    }
    for(int i = 1; i <= m; i++){
        cout << sum[i] << " ";
    }
    return 0;
}
