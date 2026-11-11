#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5*1e5+5;
ll a[N],n,m,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++)
    {
        int tp=m;
        for(ll j=i-1;j>=1;j--)
        {
            ll dis=a[i]-a[j];
            if(tp-dis<=0)
            {
                ans=max(ans,i-j+1);
                break;
            }
            tp-=dis;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
