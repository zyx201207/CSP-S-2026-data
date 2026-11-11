#include <bits/stdc++.h>
using namespace std;
int n,a[200005],x;
char c[200005];
bool f=0;
int main()
{
    feropen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> c[i];
        if(c[0]!=c[i])
        {
            f=1;
        }
        if(a[i]>x)
        {
            x=a[i];
        }
    }
    if(n==1||f==0)
    {
        cout << 0;
    }
    else if(n==2)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]<x)
            {
                x=a[i];
            }
        }
        cout << x;
    }
    return 0;
}
