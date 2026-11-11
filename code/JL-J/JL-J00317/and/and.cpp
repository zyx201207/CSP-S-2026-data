#include <bits/stdc++.h>
using namespace std;
int a[100010],n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    return 0;
}
