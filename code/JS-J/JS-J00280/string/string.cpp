#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 4;
ll n,ans,a[N];
string s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> s[i];
    }
    ll l = 1,r = n;
    while (l < r){
        if (s[l] != s[r]){
            ans += min(a[l],a[r]);
        }
        a[l] -= min(a[l],a[r]);
        a[r] -= min(a[l],a[r]);
        if (a[l] == 0) l++;
        if (a[r] == 0) r--;
    }
    cout << ans;
    return 0;
}
