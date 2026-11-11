#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int m,n,x=0;
    cin >>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    for(int i=1;i<=n-m;i++)
    {
        int s=a[i];
        for(int j=i;j<=m;j++)
        {
            s=s&a[j+1];
        }
        if(s>x)
        {
            x=s;
        }
    }
    cout << x;
    return 0;
}


