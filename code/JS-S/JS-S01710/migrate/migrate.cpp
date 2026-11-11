#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        int x[500005],nx[500005],r=0,ans=0;
        ans=0;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=1;i<=n;i++)
        {
            while(r<=n && x[r]-d<=x[i])r++;
            nx[i]=r-1;
            //cout<<' '<<nx[i]<<' ';
        }
        for(int i=1;i<=n;i++)
            ans+=nx[nx[i]-1]-nx[nx[i]-2];
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6*/
