#include<bits/stdc++.h>
using namespace std;
#define int long long
int ma = INT_MIN;
int n, m;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    if(n <= 20){
        if(m == 1){
        int ma = INT_MIN;
        for(int i = 1;i <= n; i++) {
            ma = max(ma, a[i]);
        }
        cout << ma;
        return 0;
    }else if(m == 2){
        int ma = INT_MIN;
        for(int i = 1;i <= n; i++){
            for(int j = i + 1;j <= n; j++){
                ma = max(ma, a[i]&a[j]);
            }
        }
        cout << ma;
        return 0;
    }else if(m == 3){
        int ma = INT_MIN;
        for(int i = 1;i <= n; i++) for(int j = i+1;j<=n;j++) for(int k=j+1;k<=n;k++) ma=max(ma,a[i]&a[j]&a[k]);
        cout<<ma;
        return 0;
    }else if(m==4){
        int ma=INT_MIN;
        for(int i = 1;i <= n; i++) for(int j = i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int b=k+1;b<=n;b++) ma=max(ma,a[i]&a[j]&a[k]&a[b]);
        cout<<ma;
        return 0;
    }
    }
    if(m == 1){
        int ma = INT_MIN;
        for(int i = 1;i <= n; i++){
            ma = max(ma, a[i]);
        }
        cout << ma;
        return 0;
    }
    if(m == 2){
        int ma = INT_MIN;
        for(int i = 1;i <= n; i++){
            for(int j = i+1;j <= n; j++){
                int y = a[i] & a[j];
                if(y > ma){
                    cout << a[i] << "&" << a[j] << "=" << y << '\n';
                }
                ma = max(ma, y);
            }
        }
        cout << ma;
        return 0;
    }
     if(m == n){
         int res = 1;
         for(int i = 1;i <= n; i++){
            res = res & a[i];
         }
         cout << res;
         return 0;
     }
    if(m == n-1){
        int ans = INT_MIN;
        for(int i = 1;i <= n; i++){
            int res = 1;
            for(int j = 1;j <= n; j++){
                if(j != i){
                    res &= a[j];
                }
            }
            ans = max(ans, res);
        }
        cout << ans;
        return 0;
    }
    return 0;
}
