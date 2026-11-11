#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int m,n,b;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> m >> b;
        for(int j = 1;j<=m;j++)
        {
            cin >> a[j];
        }
        cout << m-3 << endl;
    }
    return 0;
}
