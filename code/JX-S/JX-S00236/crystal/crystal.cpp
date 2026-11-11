//!!!remember freopen!!!
//Let's milk DANCE!
#include<bits/stdc++.h>
typedef long long ll;
ll n,m,a[500005],ans;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++)
    {
        ll tmp=0,tr=1;
        for(ll j=i-1;j>=1;j--)
        {
            if(tmp+(a[i]-a[j])<=m)
            {
                tmp+=(a[i]-a[j]);
                tr++;
            }
            else
            {
                break;
            }
            //cout<<i<<" "<<j<<" "<<tmp<<endl;
        }
        //cout<<i-tr+1<<endl;

        ans=max(ans,tr);
    }
    cout<<ans<<endl;
    return 0;
}
//X X XXX
