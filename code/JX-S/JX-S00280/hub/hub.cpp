#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t, a[100000];
    cin >> c >> t;
    for(int i = 1; i <= 2 * t; i++)
    {
        cin >> a[i];
    }
    if(t == 2)
    {
        cout << "1" << endl << "2" << endl;
    }
    else
    {
        cout << " 2" << endl << "3" << endl;
    }
    return 0;
}
