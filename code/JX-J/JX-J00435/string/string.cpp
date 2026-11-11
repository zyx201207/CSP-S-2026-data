#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, a[1000000], sum = 0;
    char b[1000000];
    cin >> n;
    int num = 0, c = n - 1, r = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        cin >> b[i];
    }
    for(int i = 0; i < sum; i++)
    {
        if(a[r] == 0 || a[c] == 0 || r == c)
        {
            break;
        }
        else
        {
            if(b[r] == b[c])
            {
                if(a[r] > a[c])
                {
                    a[r] -= a[c];
                    c = c - 1;
                }
                else if(a[r] == a[c])
                {
                    a[r] -= a[c];
                    c = c - 1;
                    r++;
                }
                else
                {
                    a[c] -= a[r];
                    r++;
                }
            }
            else
            {
                if(a[r] > a[c])
                {
                    a[r] -= a[c];
                    num += a[c];
                    c = c - 1;
                }
                else if(a[r] == a[c])
                {
                    a[r] -= a[c];
                    num += a[c];
                    c = c - 1;
                    r++;
                }
                else
                {
                    a[c] -= a[r];
                    num += a[r];
                    r++;
                }
            }
        }
    }
    cout << num;
    return 0;
}
