#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,x,dx;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for (int i=1;i<=t;i++)
    {
        cin >> n >> d;
        for (int j=1;j<=n;j++)
        {
            cin >> x;
            if (j==1)dx=x;
            if (j==2)dx=x-dx;
        }
        if (dx>d)
        {
            cout << 0;
        }
        else
        {
            if (d<2*dx)

            {
                cout << 0;
            }

            else
            {

                cout << max((long long)0,(n+1)-2*d/dx);
            }
        }

        cout << endl;
    }
}
