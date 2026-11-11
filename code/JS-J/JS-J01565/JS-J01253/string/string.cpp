#include<bits/stdc++.h>
using namespace std;
long long n,T,cnt,l,r,ans;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int q=1;q<=n;q++)
    {
        cin>>a[q]>>c[q];
        T+=a[q];
    }
    l=1,r=n;
    while(l!=r)
    {
        if(a[l]>=a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
        }
        else
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
        }
    }
    cout<<ans;
    return 0;
}
