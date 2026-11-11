#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],num[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int x = 1;x <= n;x++)
    {
        for(int i = x;i <= n;i++)
        {
            if(cnt[a[i]] == 0)
            {
                cnt[a[i]]= 1;
            }
            else
            {
                for(int j = i - 1;j >= 1;j--)
                {
                    if(a[j] == a[i])
                    {
                        break;
                    }
                    cnt[a[j]] = 0;
                }
            }
        }
        for(int i = 1;i <= m;i++)
        {
            if(cnt[i] == 1)
            {
                num[i]++;
                cnt[i] = 0;
            }
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}

