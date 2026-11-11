#include <bits/stdc++.h>
using namespace std;
int n,m,a,ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out""w",stdout);
    cin >> n >> m >> a >> ans;
    for(int i = 1;i <= n;i++)
    {
        sort(n+1,a+n+1);
        sort(m+1,a+m+1);
        int num = 0;
            ans++;
        if(m == n)
            cout << 12;
        else
            cout << 0;
    }
    cout << ans;
    return 0;
}
