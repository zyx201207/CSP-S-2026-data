#include<bits/stdc++.h>
using namespace std;

struct t
{
    long long x;
    char c;
}a[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i ++)
    {
        cin >> a[i].x >> a[i].c;
    }
    long long sum = 0;
    long long h = a[1].x,h1 = a[n].x;
    char w = a[1].c,w1 = a[n].c;
    int l = 1,r = n;
    while (l < r)
    {
        if (a[l].c == a[r].c)
        {
            long long bh = min(a[l].x,a[r].x);
            a[l].x -= bh;
            a[r].x -= bh;
            if (a[l].x == 0)
            {
                l ++;
            }
            if (a[r].x == 0)
            {
                r --;
            }
        }
        else
        {
            long long bh = min(a[l].x,a[r].x);
            a[l].x -= bh;
            a[r].x -= bh;
            sum += bh;
            if (a[l].x == 0)
            {
                l ++;
            }
            if (a[r].x == 0)
            {
                r --;
            }
        }
    }
    cout << sum;
    return 0;
}
