#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
    }
    int ii= 1,ji = n;
    while (ii != ji)
    {
        if (c[ii] != c[ji])
        {
            if(a[ii]>=a[ji])
            {
                a[ii]-=a[ji];
                ans+=a[ji];
                a[ji] = 0;
                ji--;
            }
            else
            {
                a[ji]-=a[ii];
                ans+=a[ii];
                a[ii] = 0;
                ii++;
            }
        }
        else
        {
            if(a[ii]>=a[ji])
            {
                a[ii]-=a[ji];
                a[ji] = 0;
                ji--;
            }
            else
            {
                a[ji]-=a[ii];
                a[ii] = 0;
                ii++;
            }
        }
    }
    cout << ans;
    return 0;
}
