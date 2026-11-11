#include <bits/stdc++.h>
using namespace std;
int n, m, a[500001];
int b[300001];
int ans[300001];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    bool sxpl = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i - 1])
            sxpl = 0;
    }
    if(sxpl){
        for(int i = n; i >= 1; i--){
            ans[a[i]] = i;
            if(a[i] == a[i - 1])
                break;
        }
        for(int i = 1; i <= m; i++){
            cout << ans[i] << ' ';
        }
    }
    else{
        for(int i = 1; i < n; i++){
            cout << 0 << ' ';
        }
        cout << n << '\n';
    }
    return 0;
}
