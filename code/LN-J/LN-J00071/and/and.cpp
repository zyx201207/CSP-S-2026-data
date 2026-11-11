#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[1000],s,d=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        a[i]=s;
        d++;
    }
    sort(a,a+d);
    for(int i=d;i<=d;i++)
    {
        cout<<a[d]&&a[0];
    }
    return 0;
}
