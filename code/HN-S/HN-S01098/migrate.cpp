#include<bits/stdc++.h>
#define int long long 
const int N=1e6;
using namespace std;
int c,t,n,d;
int a[N+5],f[N+5],sum[N+5],nxt[N+5];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;int ans=0,l=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        { 
            while(l+1<=n&&a[l+1]-a[i]<=d) l++;
            nxt[i]=l;
        }
        for(int i=1;i<=n;i++)
        {
            int l=i+1,r=nxt[i];
            sum[l-1]=0;
            for(int j=l;j<=r;j++) f[j]=1,sum[j]=sum[j-1]+1;
            while(r<=n)
            {
                int L=r+1,R=nxt[r],flg=0;
                for(int x=L;x<=R;x++)
                {
                    while(a[x]-a[l]>d) l++;
                    if(a[x]-a[l]<=d) f[x]+=sum[r]-sum[l-1];
                }
                sum[L-1]=0;
                for(int x=L;x<=R;x++)
                {
                    if(f[x]==2) ans++;
                    if(f[x]<=2) flg=1;
                    sum[x]=sum[x-1]+f[x];
                }
                if(!flg) break;
                l=L,r=R;
            }
            for(int j=1;j<=n;j++) f[j]=0,sum[j]=0;
        }cout<<ans<<"\n";
    }
}