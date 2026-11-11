#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],l,r,sm;
string c[200002];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    l=1,r=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    while(l<r)
    {
        if(c[l]!=c[r])
        {
            sm+=min(a[l],a[r]);
        }
        a[l]-=min(a[l],a[r]),a[r]-=min(a[l],a[r]);
        l+=!a[l],r-=!a[r];
    }
    cout<<sm;
    return 0;
}
