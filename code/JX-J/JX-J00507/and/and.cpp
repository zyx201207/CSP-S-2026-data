#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,m,a[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(m == 1){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            ans = max(ans,a[i]);
        }
        cout << ans << endl;
        return 0;
    }
    if(m == n){
        int ans = a[1];
        for(int i = 2;i <= n;i++){
            ans = (ans & a[i]);
        }
        cout << ans << endl;
        return 0;
    }
    if(m == 2){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ans = max(ans,a[i] & a[j]);
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(n <= 20){
        if(m == 3){
            int ans = 0;
            for(int i = 1;i <= n;i++){
                for(int j = i + 1;j <= n;j++){
                    for(int k = j + 1;k <= n;k++){
                        ans = max(ans,a[i] & a[j] & a[k]);
                    }
                }
            }
            cout << ans << endl;
        }
        if(m == 4){
            int ans = 0;
            for(int i = 1;i <= n;i++){
                for(int j = i + 1;j <= n;j++){
                    for(int k = j + 1;k <= n;k++){
                        for(int l = k + 1;l <= n;l++){
                            ans = max(ans,a[i] & a[j] & a[k] & a[l]);
                        }
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
