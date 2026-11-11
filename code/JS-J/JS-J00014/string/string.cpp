#include<bits/stdc++.h>
using namespace std;
int n, a[200010], lstl, lstr, f, r;
long long ans = 0;
char c[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    f = 1;
    r = n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    lstl = a[1];
    lstr = a[n];
    while(f < r){
        int cost = min(lstl, lstr);
        if(c[f] != c[r]){
            ans += cost;
        }
        lstl -= cost;
        lstr -= cost;
        if(lstl == 0){
            f++;
            lstl += a[f];
        }
        if(lstr == 0){
            r--;
            lstr += a[r];
        }
    }
    cout << ans;
    return 0;
}
