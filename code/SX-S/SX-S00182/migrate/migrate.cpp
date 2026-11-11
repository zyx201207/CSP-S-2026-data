#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
const int N=2e6+5;
struct node{
    int v,cnt;
}f[N];
int a[N];
void slv()
{
    int n,d;
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int k=1;k<n;k++)
    {
        f[k].v=0;
        f[k].cnt=1;
        for(int i=k+1;i<=n;i++)
        {
            f[i].v=inf;
            f[i].cnt=0;
            for(int j=i-1;j>=k&&abs(a[i]-a[j])<=d;j--)
            {
                if(f[j].v<f[i].v)
                {
                    f[i].v=f[j].v;
                    f[i].cnt=f[j].cnt;
                }
                else if(f[j].v==f[i].v) 
                    f[i].cnt+=f[j].cnt;
            }
            f[i].v+=1;
            if(f[i].cnt==2) ans++;
        }         
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
        slv();
    return 0;
}