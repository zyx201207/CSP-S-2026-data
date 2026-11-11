#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int maxa=0;
    for(int i=1;i<=n-m;i++)
    {

        for(int j=i;j<=n;j++)
        {
            int b=a[j];
            for(int k=1;k<=m;k++)
            {
                b=(b&a[i+k]);
            }
            maxa=max(maxa,b);
        }
    }
    cout<<maxa;
    return 0;
}
