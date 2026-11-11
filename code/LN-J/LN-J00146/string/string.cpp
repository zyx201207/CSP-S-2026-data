#include <bits/stdc++.h>
#define int long long
using namespace std;
map <int, char> a;
int n;
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int l = 1;
    for(int i = 1; i <= n; i ++){
        int x;
        char c;
        cin >> x >> c;
        while(x --){
            a[l] = c;
            l ++;
        }
    }
    l --;
    int ans = 0;
    for(int i = 1; i <= l/2; i ++){
        if(a[i] != a[l-i+1]){
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
