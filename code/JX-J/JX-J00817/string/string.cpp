#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
char c[N];
long long l, r, x, y, ans;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i] >> c[i];
    x = 1, y = n;
    while(x < y){
        l += a[x];
        while(r < l){
            if(x == y)break;
            if(r + a[y] > l){
                if(c[y] != c[x])ans += l - r;
                a[y] -= (l - r);
                r = l;
                break;
            }
            if(c[y] != c[x])ans += a[y], r += a[y];
            else r += a[y];
            y--;
        }
        if(x == y)break;
        x++;
    }
    cout << ans;
}
