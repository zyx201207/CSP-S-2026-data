#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,k;
    int a[n];
    cin >> k;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        for ( int j = 1;j <= m;j++)
        {
            cin >> a[i];
            if(a[i] == i)
            {
                k++;
            }
        }
    }
    cout << k;
    return 0;
}
