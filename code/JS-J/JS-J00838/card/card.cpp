#include <bits/stdc++.h>
using namespace std;
int n,m,a[5000005],cnt[5000005];
bool f[5000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    if(n <= 5000)
    {
        if(m == 1) cout << n;
        else
        {
            for(int i = 1 ; i <= n ; i++)
            {
                for(int j = 1 ; j <= m ; j++) f[j] = false;
                for(int j = i ; j <= n ; j++)
                {
                    if(f[a[j]] == false) f[a[j]] = true;
                    else
                    {
                        for(int k = j - 1 ; k >= i ; k--)
                        {
                            f[a[k]] = false;
                            if(a[k] == a[j]) break;
                        }
                        f[a[j]] = true;
                    }
                }
                for(int j = 1 ; j <= m ; j++)
                {
                    if(f[j]) cnt[j]++;
                }
            }
            for(int i = 1 ; i <= m ; i++) cout << cnt[i] << " ";
        }
    }
    else if(m == 2)
    {
        if(a[n] == 1)
        {
            cnt[1] = n;
            for(int i = 1 ; i <= n ; i++)
            {
                if(a[i] == 2) cnt[2]++;
            }
        }
        if(a[n] == 2)
        {
            a[2] = n;
            for(int i = 1 ; i <= n ; i++)
            {
                if(a[i] == 1) cnt[1]++;
            }
        }
        cout << cnt[1] << " " << cnt[2];
    }
    else if(m > 3000)
    {
        for(int i = 1 ; i <= n ; i++) cnt[a[i]]++;
        for(int i = 1 ; i <= m ; i++) cout << cnt[i] << " ";
    }
    return 0;
}
