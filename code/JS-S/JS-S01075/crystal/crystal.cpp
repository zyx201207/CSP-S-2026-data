#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500050],s[500050],ans = 0,l = 1,t = 0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {cin >> a[i];}
    sort(a+1,a+1+n);
    for (int i = 1;i <= n;i++){
        s[i] = s[i-1] + a[i];
        while (a[i] * (i - l + 1) - s[i] + s[l-1] > m) l++;
        ans = max(ans,i - l + 1);
    }
    cout << ans;
    return 0;
}
