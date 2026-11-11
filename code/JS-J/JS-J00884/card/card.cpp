#include <bits/stdc++.h>
using namespace std;

int ans[300005],a[500005],now[500005],cur;
bool have[300005];

int ts[500005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(ans,0,sizeof(ans));
    int n,m;
    cin >> n >> m;
    bool flag=1;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]<a[i-1]) flag=0;
    }
    if (flag==1)
    {
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]!=a[i-1]) cnt++;
        }
        for (int i=1;i<=cnt;i++)
        {
            cout << i << " ";
        }
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        memset(now,0,sizeof(now));
        memset(have,0,sizeof(have));
        for (int j=i;j<=n;j++)
        {
            if (!have[a[j]])
            {
                now[++cur]=a[j];
            }
            else
            {
                while (now[cur]!=a[j])
                {
                    now[cur]=0;
                    cur--;
                }
            }
            memset(have,0,sizeof(have));
            for (int k=1;k<=cur;k++)
            {
                have[now[k]]=1;
            }
        }
        for (int j=1;j<=m;j++)
        {
            ans[j]+=have[j];
        }
        cur=0;
    }
    for (int i=1;i<=m;i++)
        cout << ans[i] << " ";
    return 0;
}
