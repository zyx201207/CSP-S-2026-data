#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int n,d,a[2000010],ans;
int f0[2000010],f1[2000010];
int li[2000010],ri[2000010];
int cl[2000010],cr[2000010];
int c1[2000010],c2[2000010];
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    li[0]=ri[0]=0,li[n+1]=ri[n+1]=n+1;
    a[0]=a[1]-d-1;
    a[n+1]=a[n]+d+1;
    for(int i=1;i<=n;i++)
    {
        li[i]=li[i-1];
        while(a[i]-a[li[i]]>d)li[i]++;
    }
    for(int i=n;i>=1;i--)
    {
        ri[i]=ri[i+1];
        while(a[ri[i]]-a[i]>d)ri[i]--;
    }
    for(int i=1;i<=n;i++)
    {
        cl[i]=cr[i]=1;
        c1[i]=c2[i]=0;
        if(ri[li[i]]==i)cl[i]--;
        if(li[ri[i]]==i)cr[i]--;
    }
    for(int i=1;i<=n;i++)if(ri[i]>=i+2)c1[ri[i]]++;
    for(int i=1;i<=n;i++)if(li[i]<=i-2)c2[li[i]]++;
    for(int i=1;i<=n;i++)cl[ri[i]]++,cr[li[i]]++;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"  "<<li[i]<<"<-"<<i<<"->"<<ri[i]<<'\n';
    // }
    ans=0;
    for(int i=1;i<=n;i++)f0[i]=f1[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(li[i]<i&&ri[li[i]]==i)f0[i]=f0[li[i]]+cl[i],f1[i]+=f1[li[i]];
        else f0[i]=cl[i];
        int pans=0;
        if(li[i]<i&&li[li[i]]<li[i])
        {
            int p=li[i],q=li[li[i]];
            if(ri[q]-p+1==2)
            {
                if(ri[ri[q]]==i)f1[i]+=f0[q];
                else pans+=f0[q];
                ans--;
            }
        }
        if(ri[i]>i&&ri[ri[i]]>ri[i])
        {
            int p=ri[i],q=ri[ri[i]];
            if(li[li[q]]!=i&&p-li[q]+1==2)f1[q]++,ans--;
        }
        pans+=f1[i]*cr[i];
        ans+=pans;
        // cout<<"   "<<i<<" "<<f0[i]<<" "<<f1[i]<<" "<<pans<<" "<<ans<<endl;
    }
    for(int i=2;i<=n;i++)
    {
        int cx=c1[i],cy=c2[i-1];
        ans+=cx*cy;
        // cout<<",,,"<<i<<" "<<cx<<" "<<cy<<endl;
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int tid,t;
    cin>>tid>>t;
    while(t--)solve();
    return 0;
}
/*
Are you going to Scarborough Fair?
*/