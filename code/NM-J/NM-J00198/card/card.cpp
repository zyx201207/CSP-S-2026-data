#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,u[10086],r,maxn = -1;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> u[i];
    }
    for(int i = 1;i<=n-m+1;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            r = u[i] & u[j];
            if(m>2)
            {
                for(int k = 2;k<m;k++)
                {
                    j++;
                    r = r & u[j];
                }
            }
            if(maxn < r)
            {
                maxn = r;
            }
        }

    }
    cout << maxn;
    return 0;
}

