#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1210;
int a[N];
int f[N],g[N];
void run()
{
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n+1;j++) f[j]=1e9,g[j]=0;
        f[i]=0,g[i]=1;
        for(int j=i;j<=n;j++)
        {
            for(int k=j+1;k<=n&&a[k]-a[j]<=d;k++)
            {
                if(f[k]>f[j]+1) f[k]=f[j]+1,g[k]=0;
                if(f[k]==f[j]+1) g[k]=min(3ll,g[k]+g[j]);
            }
            ans+=g[j]==2;
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) run();
    return 0;
}