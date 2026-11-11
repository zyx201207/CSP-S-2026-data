#include<iostream>
#include<algorithm>
using namespace std;
long long a[5000001] , n , s[5000001] , ans = -0x3f3f3f3f3f3f3f3f , m;
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = 1 ; i <= n ; i ++){
        s[i] = s[i - 1] + a[i];
    }
    for(int i = n ; i >= 2 ; i --){
        long long l = 1 , r = i;
        while(l <= r){
            long long mid = l + r >> 1;
            if(a[i] * (i - mid + 1) - s[i] + s[mid - 1] <= m) r = mid - 1;
            else l = mid + 1;
        }
        if(l < 1) continue;
        ans = max(ans , i - l + 1);
    }
    cout << max(1ll , ans);
    return 0;
}
