#include <iostream>
#include <cstring>
using namespace std;

int a[200005];
int f[2005][2005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    memset(f,-1,sizeof f);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = f[i-1][j];
            if (j >= 1) f[i][j] = max(f[i][j]&0,f[i-1][j-1]&a[i]);
       }
    }
    cout << f[n][m];
    return 0;
}
