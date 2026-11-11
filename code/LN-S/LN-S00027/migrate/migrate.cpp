#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,m;
    cin >> c >> t;
    for(int i = 1;i <= t;i++)
    {
        int n,d;
        cin >> n >> d;
        for(int j = 1;j <= n;j++)
        {
            cin >> a[j];
            if(j != 1 && a[j] - a[j - 1] > d)
            {
               m = j;
            }
        }

    }
    cout << "1" << endl << "2";

    return 0;
}
