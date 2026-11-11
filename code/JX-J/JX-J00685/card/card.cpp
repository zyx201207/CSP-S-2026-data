#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],b[500005],ans[500005];
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            b[j] = 0;
        }
        for(int j = i;j <= n;j++)
        {
            b[j] = a[j];
            int z=0;
            for(int k = i;k < j;k++)
            {
                if(b[k] == b[j])
                {
                    z = k;
                    for(int k = z;k < j;k++)
                    {
                        b[k] = 0;
                    }
                }

            }
        }
        for(int j = 1;j <= n;j++)
        {

            if(b[j] != 0)
            {
                ans[b[j]]++;
            }
        }

    }
    for(int i = 1;i <= m;i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
