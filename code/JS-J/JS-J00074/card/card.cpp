#include <bits/stdc++.h>
using namespace std;
typedef long ll;
ll n,m,a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n - 1; i++)
    {
        if(a[i] != a[i + 1])
        {
            cout << i << " ";
        }
    }
    cout << n;
    return 0;
}

