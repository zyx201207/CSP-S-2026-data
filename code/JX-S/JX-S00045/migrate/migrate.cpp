#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000010];
int pre[2000010];
int dt[2000010];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int i,j;
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        for(i=1;i<=n;i++) cin>>x[i];
        int da=0;
        for(int o=1;o<=n;o++)
        {
            j=o;
            for(i=o;i<=n;i++)
            {
                while(x[j+1]-x[i]<=d&&j<n) j++,dt[j]=dt[i]+1;
            }
            pre[o]=1; pre[o+1]=-1;
            int l=o,r=o;
            for(i=o;i<=n;i++)
            {
                pre[i]+=pre[i-1];
                while(dt[l]<=dt[i]&&l<=n) l++;
                while(x[r+1]-x[i]<=d&&r<n) r++;
                if(l<=r) pre[l]+=pre[i],pre[r+1]-=pre[i];
                // cout<<i<<" "<<l<<" "<<r<<"\n";
            }
            for(i=o;i<=n;i++) if(pre[i]==2) da++;
            // for(i=1;i<=n;i++) cout<<dt[i]<<" ";
            // cout<<"\n";
            // for(i=1;i<=n;i++) cout<<pre[i]<<" ";
            // cout<<"\n";
            for(i=0;i<=n+1;i++) pre[i]=dt[i]=0;
        }
        for(i=0;i<=n+1;i++) pre[i]=dt[i]=0;
        cout<<da<<"\n";
    }
    return 0;
}
