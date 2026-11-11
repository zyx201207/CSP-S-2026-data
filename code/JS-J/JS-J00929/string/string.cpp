#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long a, s, cnt = 0, step[300000][2];
    char q;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> s >> q;
        step[i][0] = s;
        step[i][1] = q;
    }
    int l = 0, r = a - 1;
    while (l <= r)
    {

        if (step[l][1] != step[r][1])
        {
            if (step[l][0] > step[r][0])
            {
                step[l][0] -= step[r][0];
                cnt += step[l][0];
                r--;
            }
            else if (step[l][0] < step[r][0])
            {
                step[r][0] -= step[l][0];
                cnt += step[r][0];
                l++;
            }
            else
            {
                cnt += step[l][0];
                l++;
                r--;
            }
        }

        else
        {
            if (l != r)
            {
                if (step[l][0] > step[r][0])
                {
                    step[l][0] -= step[r][0];
                    r--;
                }
                else if (step[l][0] < step[r][0])
                {
                    step[r][0] -= step[l][0];
                    l++;
                }
                else
                {
                    l++;
                    r--;
                }
            }
            else
            {
                cnt += step[l][0] / 2;
                break;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
