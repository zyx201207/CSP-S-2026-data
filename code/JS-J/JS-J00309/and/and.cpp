#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
ll n,m;
ll a[maxn],b[maxn];
ll mx=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=1;
    }
    for(ll i=1;i<=m;i++)
    {
        b[i]=0;
    }
    do
    {
        ll ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(b[i]==0)
            {
                if(ans==-1)ans=a[i];
                else ans=ans&a[i];
            }
        }
        mx=max(mx,ans);
    }while(next_permutation(b+1,b+n+1));
    cout<<mx;
    return 0;
}
