#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    int a[1000];
    cin >> m >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    cout << n << m << a[4];
    return 0;
}
