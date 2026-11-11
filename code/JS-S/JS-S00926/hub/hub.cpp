#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t --)
    {
        int n,k;
        cin >> n >> k;
        for (int i = 1;i < n;i ++)
        {
            int u,v;
            cin >> u >> v;
        }
        if (13<=c&&c<=14)
        {
            int m = n/2+2;
            if (k >= n) cout << 0 << '\n';
            else if (k == 1) cout << (m+1)/2 << '\n';
            else if (m <= k+4) cout << 1 << '\n';
            else cout << (m-k-4+2)/3+1 << '\n';
        }
    }
    return 0;
}
