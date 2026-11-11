#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    long long c, t;
    cin >> c >> t;
    while(t--)
    {
        long long n, d, a, b;
        cin >> n >> d;
        for(int i = 1; i < n; i++)
        {
            cin >> a;
        }
        cin >> b;
        b -= a;
        cout << d << ' ' << b << ' ';
        if(d < b)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << d / n<< endl;
        }
    }
    return 0;
}

// a 1 2 4
// b 2 3 5;
