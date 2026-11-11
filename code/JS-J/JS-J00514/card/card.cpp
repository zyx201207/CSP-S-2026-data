#include <bits/stdc++.h>
using namespace std;
int n = 0,m = 0,cnt = 0,x = 0;
int a[500005],kc[500005],jg[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            x = cnt+j-i+1;
            kc[x] = a[j];
            for(int k = 1;k < x;k++)
            {
                if(kc[k] == kc[x])
                {
                    for(int k = 1;k < x;k++)
                    {
                        kc[k] = 0;
                    }
                    break;
                }
            }
        }
        cnt = 0;
        for(int j = 1;j <= x;j++)
        {
            if(kc[j] != 0)
            {
                jg[kc[j]]++;
                cnt++;
                kc[cnt] = kc[j];
                kc[j] = 0;
            }
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << jg[i] << " ";
    }
    return 0;
}
