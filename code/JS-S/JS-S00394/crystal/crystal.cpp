#include <bits/stdc++.h>

using namespace std;

long long a[50005], d[50005];

int main()
{
    //freopen("crystal4.in", "r",stdin);//zhushi!!!
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w",stdout);

    long long n, m;
    a[0] = 0;
    scanf("%lld %lld" , &n, &m);
    for (int i = 1;  i<= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        d[i] = a[i] - a[i - 1];

    long long t = m;
    long long tal = 1, mx = 0;
    for (int i = 2; i <= n; i++)
    {
        t -= d[i] * (i - tal);
        //cout << i << " " << tal << " "<< i - tal + 1 << " "<< t << endl;
        if(t < 0)
        {
            while(t < 0)
            {
                t += a[i] - a[tal];
                //cout << a[i] - a[tal] << " "<<t << endl;
                tal++;
            }
        }
        if(i - tal + 1> mx) mx = i - tal + 1;
    }
    printf("%lld", mx);
    return 0;
}
