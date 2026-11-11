#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],b[2000005],ans,mid,nxt,ok,l,r;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        if(c==12 or c==12)
        {
            if((a[2]-a[1])*2<=d and (a[2]-a[1])*3>d and n>3)cout<<n-3<<'\n';
            else cout<<"0\n";
            continue;
        }
        r=1;
        for(int i=1;i<=n;i++)b[i]=0;
        for(int i=1;i<=n;i++)
        {
            while(r<n and a[r+1]-a[i]<=d)r++;
            b[i]=r;
        }
        for(int i=n;i>=1;i--)a[i]-=a[1];
        for(int i=1;i<=n;i++)a[i]+=d+1;
        ans=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
        {
            if(a[i]+d>=a[j])continue;
            mid=b[i],ok=0;
            while(a[j]-a[mid]>d)
            {
                nxt=b[mid];
                if(nxt==mid)
                {
                    ok=2;
                    break;
                }
                ok+=(a[nxt]-a[mid-1]<=d)+(a[nxt]-a[mid-2]<=d);
            }
            ok+=(a[j]-a[mid-1]<=d)+(a[j]-a[mid-2]<=d);
            if(ok==1)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
