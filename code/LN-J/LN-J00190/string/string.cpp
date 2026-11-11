#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        long long aa;
        char cc;
        cin >> aa >> cc;
        if(cc == c[cnt]) a[cnt] += aa;
        else
        {
            a[++cnt] = aa;
            c[cnt] = cc;
        }
    }
    long long h = 1, t = cnt, sum = 0;
    while(h < t)
    {
        if(a[h] > a[t])
        {
            if(c[h] != c[t])
            {
                sum += a[t];
                a[h] -= a[t];
                a[t] = 0;
            }
            else
            {
                a[h] -= a[t];
                a[t] = 0;
            }
        }
        else if(a[h] < a[t])
        {
            if(c[h] != c[t])
            {
                sum += a[h];
                a[t] -= a[h];
                a[h] = 0;
            }
            else
            {
                a[t] -= a[h];
                a[h] = 0;
            }
        }
        else
        {
            if(c[h] != c[t])
            {
                sum += a[t];
                a[t] = 0;
                a[h] = 0;
            }
            else
            {
                a[t] = 0;
                a[h] = 0;
            }
        }
        if(a[t] == 0) t--;
        if(a[h] == 0) h++;
    }
    cout << sum;
    cout << "\n";
    return 0;
}
