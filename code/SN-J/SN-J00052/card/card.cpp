
#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >>m;
    int a[105];
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    int b[105];
    for (int i=1;i<=n;i++)
    {
        b[i]=a[i]/2+1;
        cout << b[i];
    }

    return 0;
}
