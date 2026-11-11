#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
const int N = 200010;
int a[N];
int ans, mx, mxx;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(m == 1){
        int mx = 0;
        for(int i = 1; i <= n; i++) mx = max(mx, a[i]);
        cout << mx;
        return 0;
    } else if(m == 2){
        int mx = 0;
        for(int i = 1; i <= n; i++){
            int ans = a[i];
            for(int j = i + 1; j <= n; j++) {
                ans = ans & a[j];
                mx = max(mx, ans);
            }
            mxx = max(mx, ans);
        }
        cout << mxx;
        return 0;
    } else if(m == n){
        int ans = a[1];
        for(int i = 1; i <= n; i++) ans &= a[i];
        cout << ans;
        return 0;
    }
}
