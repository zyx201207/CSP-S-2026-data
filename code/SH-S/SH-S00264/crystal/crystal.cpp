#include<bits/stdc++.h>
using namespace std;
#define maxn 523456
typedef long long lint;
lint n, m, a[maxn], s[maxn], ans = 1;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(lint i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(lint i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i];
    }
    for(lint i = 1; i <= n; i++){
        // for(lint j = 1; j <= n; j++){
        //     if(a[j] * (j - i + 1) - s[j] + s[i-1] <= m){
        //         ans = max(ans, j - i + 1);
        //     }
        // }
        lint l = i, r = n, anss = i;
        while(l <= r){
            lint mid = (l + r) / 2;
            if(a[mid] * (mid - i + 1) - s[mid] + s[i-1] <= m){
                anss = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        ans = max(ans, anss - i + 1);
    }
    cout << ans << endl;
    return 0;
}