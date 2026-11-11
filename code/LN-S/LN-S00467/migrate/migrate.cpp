#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sig,t,n,m,a[1000005],ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>sig>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=n;i>=4;i--)
        {
            if((a[i-1]-a[i-3]<=m&&a[i]-a[i-2]<=m&&a[i]-a[i-3]>m))
            {
                for(int k=1;;k++)
                {
                    if(i>=4+k&&a[i-1-k]-a[i-3-k]>m)
                    {
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }

                ans++;
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}
