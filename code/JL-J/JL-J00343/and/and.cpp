#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],ma=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>ma)ma=a[i];
    }
    cout<<ma;
    return 0;
}
