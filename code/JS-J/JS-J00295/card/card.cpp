#include<bits/stdc++.h>
using namespace std;

int  a[500005], ans[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int k = 1; k <= n; k++)
    {
        bool f[500005];
        int s[500005];
        for(int i = 1; i <= m; i++)
            f[i] = 0;
        int top = 0;
        for(int i = k; i <= n; i++)
        {
            if(f[a[i]] == 0)
            {
                top++;
                s[top] = a[i];
                f[a[i]] = 1;
            }
            else
            {
                int t;
                for(int j = 1; j <= top; j++)
                {
                    if(s[j] == a[i])
                    {
                        t = j;
                        break;
                    }
                }
                for(int j = top - t; j <= top; j++)
                    f[j] = 0;
                top -= t + 1;
                top++;
                s[top] = a[i];
                f[a[i]] = 1;
            }
        }
        for(int i = 1; i <= top; i++)
            if(s[i] != 0) ans[s[i]]++;
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
