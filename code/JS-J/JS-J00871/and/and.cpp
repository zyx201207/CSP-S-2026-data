#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a[0],a[n-1]);
    int ans;
    ans = a[n-1];

        ans&a[n-2];




    cout << ans;
    return 0;
}
