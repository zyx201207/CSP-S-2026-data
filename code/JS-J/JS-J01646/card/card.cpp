#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans[300005];
bool is[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        ans[a[i]]=0;
    }
    long long u=n;
    while(u--)
    {
        for (long long i=1;i<=n;i++)
        {
            is[a[i]]=false;
        }
        for (long long i=n-u;i<=n;i++)
        {
            if(is[a[i]]==true)
            {
                for (long long j=n-u;j<i;j++)
                {
                    if(a[j]==a[i])
                    {
                        for (long long k=j;k<i;k++)
                        {
                            is[a[k]]=false;
                        }
                        break;
                    }
                }
            }
            is[a[i]]=true;
        }
        for (int i=n-u;i<=n;i++)
        {
            if(is[a[i]]==true)
            {
                ans[a[i]]++;
                is[a[i]]=false;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
