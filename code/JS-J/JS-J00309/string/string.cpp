#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll n;
ll a[maxn];
char z[maxn];
ll ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>z[i];
    }
    ll l=1,r=n;
    while(l<r)
    {
        if(z[l]!=z[r])
        {
            ans+=min(a[l],a[r]);
            if(a[l]<a[r])
            {
                a[r]-=a[l];
                l++;
            }
            else
            {
                a[l]-=a[r];
                r--;
            }
        }
        else
        {
            if(a[l]<a[r])
            {
                a[r]-=a[l];
                l++;
            }
            else
            {
                a[l]-=a[r];
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}

