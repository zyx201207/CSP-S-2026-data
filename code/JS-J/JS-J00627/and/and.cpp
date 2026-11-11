#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[3000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    int ans = 0;
    if (m == 1){
        int mx = a[1];
        for (int i = 2;i <= n;i++){
            mx = max(mx,a[i]);
        }
        ans = mx;
        cout << ans;
    }
    else if(m == n){
        int num = a[1];
        for (int i = 2;i <= n;i++){
            num &= a[i];
        }
        ans = num;
        cout << ans;
    }
    else{
        int mx = 0;
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                mx = max(mx,a[i] & a[j]);
            }
        }
        ans = mx;
        cout << ans;
    }
    return 0;
}
