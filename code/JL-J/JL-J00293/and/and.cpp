#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[105];
    int n,m,p=1;
    cin<<n<<m;
    int maxn=10;
    for (i=0;i<=n;i++)
    {
        cin<<a[i];
        for(k=0;k<=n;k++)
        {
            for(i=0;i<=k;i++)
            {
                p=p*2;
            }
            if (p=n)
            {
                cout<<a[i]+1;
                return 0;
            }
            p=0;
        }
    }


    if (a[i]>maxn)
        cout>>a[i];
    else
        cout>>a[i+1];
    return 0;
}
