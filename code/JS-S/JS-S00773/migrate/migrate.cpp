#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int x[2000005];
int up[2000005],down[2000005];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int lim=1;
        for(int i=1;i<=n;i++)
        {
            while(lim<n&&x[lim+1]-x[i]<=d)lim++;
            up[i]=lim;
        }
        lim=n;
        for(int i=n;i>=1;i--)
        {
            while(lim>1&&x[i]-x[lim-1]<=d)lim--;
            down[i]=lim;
        }
        int ans=0;
        int l=1,pre=0;
        for(int r=1;r<=n;r++)
        {
           while(l+1<down[r])pre=(up[l]==l)?l:pre,l++;
           if(l<down[r]&&up[l]!=down[r])
           {
               if(up[l]-down[r]==1)ans+=(l-pre);
               pre=l;
           }
        }
        cout<<ans<<endl;
    }
    return 0;
}
