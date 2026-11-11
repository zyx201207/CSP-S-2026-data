#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[200005];
    int maxn = -1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxn = max(a[i], maxn);
    }
    if(m == 1) cout << maxn;
    else if(m == n){
    int ans = a[1];
        for(int i=2;i<=n;i++){
            ans &= a[i];
        }
        cout << ans;
    }
    else if(m == 2){
        int ans = -1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int sum = a[i] & a[j];
                ans = max(ans, sum);
            }
        }
        cout << ans;
    }
    return 0;
}
