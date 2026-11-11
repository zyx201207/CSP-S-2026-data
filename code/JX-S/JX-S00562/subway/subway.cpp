#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5,N=505;
int cnt[M],f[M],k[M][2],z[M],a[N][M],w[M];
int n,c,q,d,m;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int mn=1e9;
    for(int i=1;i<=n;i++)
    {
        int s;
        cin>>s;
        for(int j=1;j<=s;j++)
        {
            cin>>a[i][j]>>k[a[i][j]][i];
            z[a[i][j]]+=k[a[i][j]][i];
            cnt[a[i][j]]++;
            f[a[i][j]]=i;
        }
    }
    
    for(int i=1;i<=m;i++)
        if(cnt[i]==2) mn=min(mn,z[i]);
    if(n==2)
    {
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            int ans=w[x]+w[y];
            if(cnt[x]==2||cnt[y]==2)
            {
                if(cnt[x]==1)
                {
                    ans+=k[x][f[x]];
                    ans+=k[y][f[x]];
                }
                else if(cnt[y]==1)
                {
                    ans+=k[y][f[y]];
                    ans+=k[x][f[y]];
                }
                else ans+=min(k[x][1]+k[y][1],k[x][2]+k[y][2]);
                cout<<ans<<endl;
            }
            else if(f[x]==f[y])
            {
                ans+=k[x][f[x]]+k[y][f[y]];
                cout<<ans<<endl;
            }
            else
            {
                ans+=k[x][f[x]]+k[y][f[y]];
                ans+=mn;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}