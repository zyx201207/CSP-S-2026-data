#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
constexpr int maxn=5e5+10;
constexpr int maxm=3e5+1;
int x[maxn],w1[maxn],w2[maxn];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>x[i];
        }
        int r=2;
        for(int i=1;i<=n;++i)
        {
            while(r<=n)
            {
                if((__int128)x[r]-x[i]>(__int128)d){w1[i]=r-1,w2[i]=r-2;break;}
                r++;
            }
            if(!w1[i])w1[i]=n,w2[i]=n-1;
        }
        for(int i=1;i<=n;++i)
        {
            ans+=w1[w1[i]-1]-w1[w2[i]-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
