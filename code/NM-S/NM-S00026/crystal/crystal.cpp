#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
ll dp[5005][5005];
void init()
{
    sort(a+1,a+n+1);



    memset(dp,0,sizeof(dp));
    ll ans=-1e18;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            //cout<<i<<" "<<j<<endl;
            dp[i][j]=dp[i][j-1]+(a[i]-a[i-j]);
            if(dp[i][j]<=m&&j>ans)
            {
                ans=j;
            }
        }
    }
    cout<<ans+1;

}


int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    //ll k;
    bool f=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            f=1;
        }
    }

    if(f==1)
    {
        init();
        return 0;
    }

    sort(a+1,a+n+1);
    //k=a[2]-a[1];
    for(ll i=1;i<=n;i++)
    {
        ll num;
        num=(ll)(1+a[i])*(ll)i;//need
        num=num/2;
        if(m<num)
        {
            cout<<i;
            return 0;
        }
    }

    cout<<n;
    return 0;
}
