#include <bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int maxx = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        maxx = max(a[i],maxx);
    }
    int ans = 0;
    if (m == 1){
        cout << maxx;
    }
    else if (m == 2){
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                ans = max(ans,a[i] & a[j]);
            }
        }
        cout << ans;
    }
    else if (m == n - 1){
        b[1] = a[1];
        for (int i = 2;i <= n;i++){
            b[i] = b[i - 1] & a[i];
        }
        ans = max(b[n] - b[1],b[n - 1]);
        for (int i = 2;i <= n - 1;i++){
            ans = max(ans,b[i - 1] + b[n] - b[i]);
        }
        cout << ans;
    }
    else if (m == n){
        ans = a[1];
        for (int i = 2;i <= n;i++){
            ans &= a[i];
        }
        cout << ans;
    }
    return 0;
}
