#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    long long x=a[l],y=a[r];
    char g=c[l],h=c[r];
    while(l<=r)
    {
        if(x<y)
        {
            l++;
            y-=x;
            if(g!=h)
            {
                ans+=x;
            }
            x=a[l];
            g=c[l];
        }
        if(x>y)
        {
            r--;
            x-=y;
            if(g!=h)
            {
                ans+=y;
            }
            y=a[r];
            h=c[r];
        }
        if(x==y)
        {
            l++;
            r--;
            if(g!=h)
            {
                ans+=x;
            }
            x=a[l];
            g=c[l];
            y=a[r];
            h=c[r];
        }
    }
    cout<<ans;
    return 0;
}
