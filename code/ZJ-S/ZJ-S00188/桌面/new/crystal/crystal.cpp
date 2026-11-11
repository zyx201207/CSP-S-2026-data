#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+20;
int n,m;
int a[maxn],b[maxn];
int ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        memset(b,0,sizeof(b));
        for(int j=1;j<=n;++j)b[j]=a[i]-a[j];
        sort(b+1,b+n+1);
        int t=m,sum=0;
        for(int j=1;j<=n;++j)
        {
            if(b[j]<0)continue;
            else
            {
                if(t-b[j]>0)
                {
                    sum++;
                    t-=b[j];
                }
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans+1<<"\n";
    return 0;
}