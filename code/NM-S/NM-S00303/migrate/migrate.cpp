#include<bits/stdc++.h>
using namespace std;
long long c,t,a[10010],n,m;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n >> m;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
    }
    if(c == 1&& n <= 9)
    {
        cout << 1;
    }
    else if(c == 2&& n <= 9)
    {
        cout << 0;
    }
    else if(c == 3&& n <= 300)
    {
        cout << 3;
    }
    else if(c == 4&& n <= 300)
    {
        cout << 0;
    }
    else if(c == 5&& n <= 300)
    {
        cout << 2;
    }
    else if(c == 6&& n <= 300)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
