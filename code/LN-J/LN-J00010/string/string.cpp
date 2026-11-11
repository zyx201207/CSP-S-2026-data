#include <bits/stdc++.h>
using namespace std;
long long a[200005],n;
string c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    long long tot=0;
    while(l<r)
    {
        if(a[l]<a[r])
        {
            if(c[l]!=c[r]) tot+=a[l];
            a[r]-=a[l++];
        }
        else
        {
            if(c[l]!=c[r]) tot+=a[r];
            a[l]-=a[r--];
        }
    }
    cout<<tot;
    return 0;
}
