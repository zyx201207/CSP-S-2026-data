#include<bits/stdc++.h>
using namespace std;
int a[500005], v[500005], ans[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int p = 1;
        for(int j = i;j <= n;j++)
        {
            int t = a[j];
            bool flag = 1;
            if(v[p - 1] == t)
            {
                flag = 0;
            }
            if(flag)
            {
                v[p] = t;
                p++;
            }
        }
        for(int j = 1;j < p;j++)
        {
            ans[v[j]]++;
        }
        memset(v, 0, sizeof(v));
    }
    for(int i = 1;i <= m;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
