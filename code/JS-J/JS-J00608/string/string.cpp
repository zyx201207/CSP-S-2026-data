#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],L,ans,cntl,cntr,l,r;
char c[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i],L+=a[i];
    r=n;
    while(cntl<L/2)
    {
        l++;
        if(cntl+a[l]<=L/2)
        {
            cntl+=a[l];
            while(cntr<cntl)
            {
                if(c[l]!=c[r]) ans+=min(cntl-cntr,a[r]);
                if(cntr+a[r]<=cntl) cntr+=a[r],r--;
                else a[r]-=cntl-cntr,cntr=cntl;
            }
        }
        else
        {
            a[l]-=L/2-cntl;
            cntl=L/2;
            while(cntr<cntl)
            {
                if(c[l]!=c[r]) ans+=min(cntl-cntr,a[r]);
                if(cntr+a[r]<=cntl) cntr+=a[r],r--;
                else a[r]-=cntl-cntr,cntr=cntl;
            }
        }
    }
    cout<<ans;
    return 0;
}
