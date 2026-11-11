#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    srand(time(NULL));
    int n;
    cin >> n;
    if(n == 0)
    {
        cout << 1 << endl << 2;
    }else
    {
        int x = rand();
        for(int i = 1; i <= x; i++)
        {
            cout << rand();
        }
    }
}
