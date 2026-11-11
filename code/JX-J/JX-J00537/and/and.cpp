#include<bits/stdc++.h>
using namespace std;
long long m,n,b,a[10005],c;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cout<<a[n/2+1];
}
