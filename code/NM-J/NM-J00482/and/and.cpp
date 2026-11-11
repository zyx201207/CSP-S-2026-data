#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
long long a[20005];

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1, cmp);
    ans = a[1];
    a[1] = 0;
    for(int i=1; i<m; i++)
    {
        sort(a+1, a+n+1, cmp);
        n--;
        int cnt = 0, ls;
        for(int j=1; j<=n; j++)
        {
            int suan = ans&a[j];
            if(suan>cnt)
            {
                cnt = suan;
                ls = j;
            }
        }
        a[ls] = 0;
        ans = cnt;
    }
    cout << ans;
    return 0;
}
