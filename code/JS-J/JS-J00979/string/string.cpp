#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],ans;
char m[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>m[i];
    }
    ll l=1,r=n;
    while(l<r)
    {
        if(m[l]!=m[r])
        {
            if(a[l]>a[r])
            {
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r])
            {
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
            else
            {
                ans+=a[r];
                l++;
                r--;
            }
        }
        else
        {
            if(a[l]>a[r])
            {
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r])
            {
                a[r]-=a[l];
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
