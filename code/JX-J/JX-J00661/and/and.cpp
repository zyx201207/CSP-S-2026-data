#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[100005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    if(m==n)
    {
        cout<<(a[1]&a[2]);
    }
    else if(m==1)
    {
        cout<<a[n];
    }
    else
    {
        cout<<a[n-m+1];
    }
}
