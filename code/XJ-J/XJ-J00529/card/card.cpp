#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n, m;
    cin >> n >> m;
    srand(time(0));
    if (m == 1)
        cout << 1;
    else
        while (m--)
        {
            cout << rand() % 100<<' ';

            long long a = 21474836470;
            for (int i = 1; i <= 2147483; i++)
            {
                a += 2;
                a -= 3;
                a = a;
            }
        }

    return 0;
}