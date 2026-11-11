#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n, a[100002] = {}, c = 0;
    n = 3 & 12;
    cout <<n;
    string s;
    char b[100002] = {};
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        c += a[i];

    }

    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    if(n == 2)
    {
        if(b[1] == b[2])
        {
            cout << 0;
            return 0;
        }
        else
        {
            if(a[1] <= a[2])
            {
                cout << a[1];
                return 0;
            }
            else
            {
                cout << a[2];
                return 0;
            }
        }
    }
    for(int i = 1; i <= n - 1; i++)
    {
        if(b[i] == b[i + 1])
        {
            cout << 0;
        }
    }




    return 0;
}
