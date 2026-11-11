#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin >> m >> n;
    int a[105];
    string b[105];
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int c,d;
    c=a[1];
    d=a[1];
    for (int i=1;i<=n;i++)
    {
        if(a[i]<c)
        {
            c=a[i];
        }
        if (a[i]>d)
        {
            d=a[i];
        }
    }
    int s;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>c && a[i]<d)
        s=a[i];
    }
    cout << s;
}
