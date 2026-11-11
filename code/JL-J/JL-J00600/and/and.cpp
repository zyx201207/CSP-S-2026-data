#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin)
    freopen("and.out","w",stdout)
    int n,m;
    cin>>n>>m;
    int a[10000000];
    int k;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i+1])
        {
            int t=a[i+1];
        }
        if(a[k]<t&&a[k]>a[i])
        {
            int r=a[k];
        }
    }
    cout<<r;
    return 0;
}
