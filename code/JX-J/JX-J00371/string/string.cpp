#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, l, r;
long long a[maxn], ans;
char c[maxn];
int main(){
    freopen("string.in", "r", stdin);
    freopen("stding.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] ;
        cin >> c[i];
    }
    l = 1, r = n;
    ans = 0;
    while(l < r){
        long long tmp = min(a[l], a[r]);
        if(c[l] != c[r])ans += tmp;
        a[l] -= tmp;
        a[r] -= tmp;
        if(a[l] == 0)l++;
        if(a[r] == 0)r--;
    }
    cout << ans;
    return 0;
}
