#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    if(m == 1){
        int maxx = 0;
        for(int i = 1; i<=n; i++){
            maxx = max(maxx, a[i]);
        }
        cout << maxx;
    }
    if(m == n){
        int ans = a[1];
        for(int i = 2; i<=n; i++){
            ans = ans&a[i];
        }
        cout << ans;
    }
    if(m == 2){
        int ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                ans = max(ans, a[i]&a[j]);
            }
        }
        cout << ans;
    }
    return 0;
}