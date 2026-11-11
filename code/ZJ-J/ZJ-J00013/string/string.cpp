#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
char c[200005];
ll ans, m, a[200005];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        m += a[i];
    }
    int l = 1, r = n, L = 0, R = 0;
    while(l < r && L <= m / 2 && R <= m / 2){
        if(a[l] == a[r]){
            if(c[l] != c[r])
                ans += a[l];
            l++;
            r--;
        }
        else{
            if(a[l] > a[r]){
                if(c[l] != c[r])
                    ans += a[r];
                a[l] -= a[r--];
            }
            else{
                if(c[l] != c[r])
                    ans += a[l];
                a[r] -= a[l++];
            }
        }
    }
    cout << ans;
    return 0;
}
