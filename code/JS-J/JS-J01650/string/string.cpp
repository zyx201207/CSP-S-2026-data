#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int n;
int sum=0;
int ans;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
    //if(sum%2==0)
    {
        int l=1,r=n;
        int ll=a[1],rl=a[n];
        char lc=c[1],rc=c[n];
        while(l<r)
        {
            if(lc==rc)
            {
                if(ll<rl) rl-=ll,l++,ll=a[l],lc=c[l];
                else if(ll>rl) ll-=rl,r--,rl=a[r],rc=c[r];
                else if(ll==rl) r--,rl=a[r],rc=c[r],l++,ll=a[l],lc=c[l];
            }
            if(lc!=rc)
            {
                if(ll<rl) ans+=ll,rl-=ll,l++,ll=a[l],lc=c[l];
                else if(ll>rl) ans+=rl,ll-=rl,r--,rl=a[r],rc=c[r];
                else if(ll==rl) ans+=ll,r--,rl=a[r],rc=c[r],l++,ll=a[l],lc=c[l];
            }
            //cout<<ll<<' '<<rl<<' '<<rc<<' '<<lc<<' '<<ans<<'\n';
        }
    }
    cout<<ans;
    return 0;
}
