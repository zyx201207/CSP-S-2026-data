#include <bits/stdc++.h>
using namespace std;
int n = 0,m = 0;
int a[200005],l[200005],y = 0;
int maxy = 0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int x = 1;x <= n;x++)
        {
            l[x] = a[x];
        }
        y = l[i];
        for(int j = 1;j < m;j++)
        {
            for(int k = i+1;k <= n;k++)
            {
                if(l[k] != 0)
                {
                    y = y & l[k];
                    l[k] = 0;
                    break;
                }
            }
        }
        if(maxy <= y)
        {
            maxy = y;
        }
    }
    cout << maxy;
    return 0;
}
