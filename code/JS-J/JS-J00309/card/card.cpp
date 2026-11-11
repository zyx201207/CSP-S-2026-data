#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
ll n,m;
ll a[maxn],b[maxn];
ll ans[maxn];
ll ha[maxn];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);


    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int p=0;p<n;p++)
    {
        memset(ha,0,sizeof(ha));
        for(ll i=1+p;i<=n;i++)
        {
            b[i]=a[i];
            if(ha[b[i]]==0)
            {
                ha[b[i]]=i;
            }
            else
            {
                for(ll j=i;j>=ha[b[i]];j--)
                {
                    ha[b[j]]=0;
                }
                ha[b[i]]=i;
            }
        }
        for(ll i=1;i<=m;i++)
        {
            if(ha[i]!=0)
            {
                ans[i]++;
            }
        }
    }
    for(ll i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
