#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x;
int main()
{
    feropen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    if(m==1)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]>x)
            {
                x=a[i];
            }
        }
        cout << x;
    }
    if(m==n)
    {
        long long y=a[0];
        for(int i=1;i<n;i++)
        {
            x=y&a[i];
            y=x;
        }
        cout << x;
    }
    if(m==2)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                int s=a[i]&a[j];
                if(s>x)
                {
                    x=s;
                }
            }
        }
        cout << x;
    }
    return 0;
}
