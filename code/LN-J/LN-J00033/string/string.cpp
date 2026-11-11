#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    long long n,a[200005],l = 0,ans = 0;
    char c[200005];
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        l += a[i];
    }
    long long i = 1,j = n,sumi = 0,sumj = 0;
    while (sumi < l/2&&sumj < l/2){
        if (a[i] == a[j]){
            if (c[i] != c[j])
                ans += a[i];
            sumi += a[i];
            sumj += a[j];
            i++;
            j--;
        }
        else if (a[i] < a[j]){
            if (c[i] != c[j])
                ans += a[i];
            sumi += a[i];
            sumj += a[j]-a[i];
            a[j] -= a[i];
            i++;
        }
        else {
            if (c[i] != c[j])
                ans += a[j];
            sumj += a[j];
            sumi += a[i]-a[j];
            a[i] -= a[j];
            j--;
        }
    }
    cout << ans;
    return 0;
}
