#include<bits/stdc++.h>
using namespace std;
long long a[500010],p[500010],m;
int n,ans=0;
void init()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
int check1()
{
    int f=1;
    for(int i=1;i<=n;i++)
        if(a[i]!=i) f=0;
    return f;
}
int check2()
{
    int f=1;
    for(int i=3;i<=n;i++)
        if((a[i]-a[i-1])!=(a[i-1]-a[i-2])) f=0;
    return f;
}
void solve1()
{
    for(int i=0;i<(1<<n);i++)
    {
        int j=i,cnt=0,maxn=-100,sum=0;
        for(int k=n;k>=1;k--)
        {
            if(j%2==1)
            {
                if(cnt==0) maxn=a[k];
                cnt++;
                sum+=maxn-a[k];
            }
            j/=2;
        }
        if(m>=sum) ans=max(ans,cnt);
    }
    cout<<ans;
}
void solve2()
{
    for(int i=1;i<=n;i++)
        p[i]=p[i-1]+a[i];
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
            if((p[r]-p[l-1])+m>=(r-l+1)*a[r])
                ans=max(ans,r-l+1);
    cout<<ans;
}
void solve3()
{
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        cnt+=i;
        if(m<cnt)
        {
            ans=i;
            break;
        }
    }
    if(ans==0) cout<<n;
    else cout<<ans;
}
void solve4()
{
    long long cnt=0,d=a[n]-a[n-1];
    for(int i=1;i<n;i++)
    {
        cnt+=d*i;
        if(m<cnt)
        {
            ans=i;
            break;
        }
    }
    if(ans==0) cout<<n;
    else cout<<ans;
}
void solve()
{
    for(int i=1;i<=n;i++)
        p[i]=p[i-1]+a[i];
    for(int r=1;r<=n;r++)
        if(p[r]+m>=r*a[r])
            ans=max(ans,r);
    for(int l=n;l>=1;l--)
        if(p[n]-p[l-1]+m>=(n-l+1)*a[n])
            ans=max(ans,n-l+1);
    cout<<ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    init();
    if(n<=20) solve1();
    else if(n<=5000) solve2();
    else if(check1()) solve3();
    else if(check2()) solve4();
    else solve();
    return 0;
}
