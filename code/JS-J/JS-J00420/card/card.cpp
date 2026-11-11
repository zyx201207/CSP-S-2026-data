#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int f[500005];
int cnt[500005];
int main()
{
    //freopen(card.in, "r", stdin);
    //freopen(card.out, "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(f[a[i]] > 1)
        {
            for(int j = i; j <= n; j++)
            {
                if(a[j] == a[i])  break;
                f[a[j]]--;
            }
        }
        if(f[a[i]] == 1)  cnt[a[i]]++;
    }
    for(int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
