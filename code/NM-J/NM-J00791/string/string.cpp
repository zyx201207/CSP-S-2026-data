#include "bits/stdc++.h"
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n, x;
    int sum = 0;
    char a;
    string s, s1;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        sum += x;

        cin >> a;

        for(int j = 1; j <= x; j++)
        {
            s += a;
        }
    }

    if(sum % 2 == 0)
    {
        cout << sum / 2 - 1;
        return 0;
    }
    else cout << sum / 2;

    return 0;
}
