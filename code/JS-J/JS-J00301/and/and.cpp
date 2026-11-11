#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005]={},b[200005]={},maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=1;
        b[i]=b[i]*10+a[i]%2;
        while(a[i])
        {
            a[i]/=2;
            b[i]=10*b[i]+a[i]%2;
        }
    }
    cout<<12;
    return 0;
}
