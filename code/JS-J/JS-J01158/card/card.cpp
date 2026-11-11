#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    ll n,m,a[200010]={0},b[200010]={0},c[200010]={0};
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j++)
        {
            b[j]=a[j];
            ll w=0;
            for(ll t=i;t<j;t++)
            {
                if(b[t]==b[j])
                {
                    w=t;
                    break;
                }
            }
            if(w!=0)
            {
                for(ll t=w+1;t<=j;t++)
                    b[t]=0;
            }
        }
        for(ll j=i;j<=n;j++)
        {
            if(b[j]!=0)
                c[b[j]]++;
        }
    }
    for(ll i=1;i<=m;i++)
        cout<<c[i]<<" ";
    return 0;
}
