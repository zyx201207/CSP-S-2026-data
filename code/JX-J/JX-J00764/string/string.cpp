#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int const MAXN = 2e5 + 5;
ll n, a[MAXN], ans;
char ch[MAXN];
int main() {               
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);                                        
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i] >> ch[i];
    ll l = 1, r = n, len_l = a[1], len_r = a[n];
    while(l <= r) {
        if(ch[l] != ch[r]) {
            ans += min(len_l, len_r);
        }
        if(len_l < len_r) {
            l++;
            len_r -= len_l;
            len_l = a[l];
        }
        else if(len_l > len_r) {
            r--;
            len_l -= len_r;
            len_r = a[r];
        }
        else {
            l++, r--;
            len_l = a[l], len_r = a[r];
        }
        //cout << len_l << ' ' << len_r << '\n';
    }
    cout << ans << '\n';
    return 0;
}






