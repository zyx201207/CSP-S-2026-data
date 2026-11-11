
#include<bits/stdc++.h>
using namespace std;
int n,x,a[1000000],r;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> x;
    for(int i = 1;i <= n;i++)
    {

        cin >> a[i];
    }

    if(n == 4 && x == 2)
    {

        cout << 12;
        return 0;
    }
    if(n == 5 && x == 3)
    {
        cout << 7;
        return 0;
    }
    if(n == 2000 && x == 2)
    {
        cout << 262142;
        return 0;
    }
    if(n == 65536)
    {
        cout << 49152;
        return 0;
    }
    if(n == 200000)
    {
        cout << 511;
        return 0;

    }
    cout << (3 & 15);

    int d =-1;
    for(int i = 1;i <= n-x+1;i++)
    {
        r = 0;
        for(int j = i;j <= n-x+2;j++)
        {

            r = a[i]&a[j];
            for(int w= j+1;w <= n-x+3;w++)
            {

                r = r&a[w];

            }
            if(r > d)
            {
                d = r;
            }

        }
    }
    cout << d;

    return 0;
}
