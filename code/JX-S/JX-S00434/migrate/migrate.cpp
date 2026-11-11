#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int c, t;
    cin >> c >> t;
    for (int a = 1; a <= t; a++)
    {
        int n, b, bo = 1, cnt = 0;
        cin >> n >> b;
        int m[n + 1], q[n / 2 + 1], p[n / 2 + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> m[i];
        }
        for (int i = 1; i <= n; i++)
        {

            for (int j = i + 3; j <= n; j++)
            {

                for(int o1 = i, o2 = j; o2 - o1 != 1; o1++, o2--)
                {

                    if (m[o1 + 1] - m[o1] > b || m[o2] - m[o2 - 1] > b)
                    {
                        bo = 0;
                        break;
                    }

                }

                if (m[i] + b >= m[i + 3])
                bo = 0;
                if (bo)
                {
                    cnt++;
                }

                bo = 1;

            }

        }
        cout << cnt << endl;

    }


    return 0;
}
