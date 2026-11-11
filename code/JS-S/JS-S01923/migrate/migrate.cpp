#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    long long c, t;
    cin >> c >> t;
    while(t--)
    {
        long long n, d, a, b;
        cin >> n >> d;
        for(long long i = 1; i < n; i++)
        {
            cin >> a;
        }
        cin >> b;
        b -= a;
        if(d <= b)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << n / 2<< endl;
        }
    }
    return 0;
}

// a 1 2 4
// b 2 3 5;
