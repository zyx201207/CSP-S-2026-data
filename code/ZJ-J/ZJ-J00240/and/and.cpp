#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int a[maxn],ww[33],sum[maxn],pre[maxn];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    bool f=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]!=i-1)f=1;
        for(int j=0;j<=30;++j)
        {
            if(a[i]&(1<<j))ww[j]++;
        }
    }
    int k=0;
    for(int i=30;i>=0;--i)
    {
        if(ww[i]>=m)
        {
            k=1<<i;
            break;
        }
    }
    int ans=0;
    sort(a+1,a+n+1);
    if(n<=20)
    {
        for(int ma=0;ma<(1<<n);++ma)
        {
            int w=(1<<21)-1,cnt=0;
            for(int i=0;i<n;++i)
            {
                if(ma&(1<<i))
                {
                    cnt++;
                    w&=a[i+1];
                }
            }
            if(cnt==m)ans=max(w,ans);
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        cout<<a[n];
    }
    else if(m==2)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i!=j)ans=max(a[i]&a[j],ans);
            }
        }
        cout<<ans;
    }
    else if(n==m)
    {
        int w=a[1];
        for(int i=2;i<=n;++i)
        {
            w&=a[i];
        }
        cout<<w;
    }
    else if(n==m+1)
    {
        sum[1]=a[1];
        for(int i=2;i<=n;++i)
        {
            sum[i]=sum[i-1]&a[i];
        }
        pre[n]=a[n];
        for(int i=n-1;i>=1;--i)
        {
            pre[i]=pre[i+1]&a[i];
        }
        for(int i=1;i<n;++i)
        {
            ans=max(ans,pre[i+1]&sum[i-1]);
        }
        ans=max(sum[m],ans);
        cout<<ans;
    }
    else if(!f)
    {
        sort(a+1,a+n+1,greater<>());
        int w=a[1];
        for(int i=2;i<=m;++i)
        {
            w&=a[i];
        }
        cout<<w;
    }
    else 
    {
        cout<<k;
    }
    return 0;
}
