#include <bits/stdc++.h>
using namespace std;
int a[234567];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int mx=1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int q=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[j]>a[i])
                if(mx<=a[j] and a[i])
                    mx=a[j] and a[i];
            else
                if(mx<=a[i] and a[j])
                    mx=a[i] and a[j];
        }

    cout<<mx;
    return 0;
}
