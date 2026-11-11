#include <bits/stdc++.h>
using namespace std;

long long n,m,a[2000005],ans;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    ans = a[n-m+1];
    for (int j=n-m+1;j<=n;j++){
        ans &= a[j];
    }
    cout << ans;
    return 0;
}
