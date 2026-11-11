#include <bits/stdc++.h>
using namespace std;

int n , m ,a[500005],cnt[300005];
int main ()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        for(int j = 0;j < m;j++)
        {
            if(a[j] == a[i])
            {
                for(int k = 0;k < m-i;k++)
                {
                    a[k] = a[i + k];
                }
            }
        }
        for(int j = 1;j <= m;j++)
        {
            for(int k = 0;k < m;k++)
            {
                if(a[k] == j)
                {
                    cnt[j]++;
                }
            }
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << cnt[i];
    }
    return 0;
}
