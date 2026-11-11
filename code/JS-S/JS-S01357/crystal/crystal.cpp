#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;

ll n,m,cnt,sum,ans;
ll a[N],diff[N];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(ll i=2;i<=n;i++)
    {
        diff[i]=a[i]-a[i-1];
    }

    for(ll i=2;i<=n;i++)
    {
        cnt=0;
        sum=0;
        for(ll j=i;j>=1;j--)
        {
            cnt+=diff[j];
            sum+=cnt;
            if(sum>m)
            {
                ans=max(ans,i-j+1);
                break;
            }
        }
    }

    cout<<ans;
    return 0;
}

