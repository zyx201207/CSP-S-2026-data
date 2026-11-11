#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long a[500015], b[500015], c[500015];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i <= 500015; i++)
    {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }
    long long n, m;
    cin >> n>> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 1;
    b[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        b[i] = b[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    }
    for(int i = 1; i <= n; i++)
    {
        int h = 1, e = i;
        while(h+ 1< e)
        {
            if(m >= b[i] - b[(h + e) / 2] - ((h + e) / 2 - 1) * (a[i] - a[(h + e) / 2]))
                e = (h + e)/ 2;
            else h = (h + e) / 2;
        }
        if(h == e) c[i] = i - h + 1;
        if(h == e - 1)
        {
            if(m >= b[i] - b[(h + e) / 2] - ((h + e) / 2 - 1) * (a[i] - a[(h + e) / 2])) c[i] = i - h + 1;
            else c[i] = i - e + 1;
        }
    }
    for(int i = 1; i <= n; i++)
        if(c[i] > ans) ans = c[i];
    cout << ans<< "\n";
    return 0;
}
