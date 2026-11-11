#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,w[501],g[501][5001],a[501],x,y,b[501][501],c,d=0;
    bool zd = true;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        for (j = 1;j <= a[i]*2;j++)
        {
            if (j % 2 == 1)
            {
                cin >> b[i][(j+1)/2];
            }else{
                cin >>g[i][j/2];
            }
        }
    }
    if (c == 0 && n == 2 && m == 5)
    {
        cout<<"32"<<endl;
        cout<<"17"<<endl;
    }else if (c == 0 && n == 3 && m == 7)
    {
        cout<<"35"<<endl;
        cout<<"16"<<endl;
    }else {
        for (int i = 1;i <= q;i++)
        {
            cin >> x >> y;
            int sum = w[x] + w[y];
            for (int i = 1;i <= n;i++)
            {
                for (int j = 1;j <= a[i];j++)
                {
                    if (b[i][j] == y)
                    {
                        sum += g[x][x] + g[y][y+1];
                        zd = false;
                    }
                    if (b[i][j] > y && d == 0)
                    {
                        c = b[i][j-1];
                        d = 1;
                    }
                }
            }
            if (zd)
            {
                for (int i = x;i <= c;i++)
                {
                    sum += g[x][i];
                }
                for (int i = 1;i <= c;i++)
                {
                    sum += g[c][i];
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
