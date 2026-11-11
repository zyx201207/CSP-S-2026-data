#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1100000], cnt[1100000];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;  i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(a[j] != a[j+1]) cnt[a[j]]++;
        }
    }
    for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
    return 0;
}
