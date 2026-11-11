#include <bits/stdc++.h>
using namespace std;
bool zm[1000005];
long long ans[1000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[1000005],t=1;
    stack<long long> z;
    cin >> n >> m;
    for (long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    long long x=n;
    while(x--)
    {
        for (long long i = t;i <= n;i++)
        {
            if (zm[a[i]]==0)
            {
                z.push(a[i]);
                zm[a[i]]++;
                ans[a[i]]++;
            }
            else
            {
                while(z.top()!=a[i])
                {
                    zm[z.top()]=0;
                    ans[z.top()]--;
                    z.pop();

                }
            }

        }
        t++;
        memset(zm,0,sizeof(zm));
        while(!z.empty())
        {
            z.pop();
        }
    }
    for (long long i = 1;i <= m;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
