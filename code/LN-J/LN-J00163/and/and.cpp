#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a[200005];
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int ans = a[1];
    for (int i = 2;i <= m;i++){
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
