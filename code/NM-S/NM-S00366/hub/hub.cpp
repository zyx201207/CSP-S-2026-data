#include <bits/stdc++.h>
using namespace std;
freopen("hub.in", "r", std.in);
freopen("hub.out", "w", std.out);
int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if (n<k)
            cout << k;
        }
    }
    cout << n * k;
    return 0;
}
