#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005];
void solve1()
{
    ll ans=0;
    for(int mark=0;mark<(1<<n);mark++)
    {
        if(__builtin_popcount(mark)!=m)continue;
        ll sum=(1<<30)-1;
        for(int i=1;i<=n;i++)if((mark>>(i-1))&1)sum&=a[i];
        ans=max(ans,sum);
    }
    cout<<ans;
}
void solve2()
{
    sort(a+1,a+n+1);
    cout<<a[n];
}
void solve3()
{
    ll sum=(1<<30)-1;
    for(int i=1;i<=n;i++)sum&=a[i];
    cout<<sum;
}
void solve4()
{
    ll ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)ans=max(ans,a[i]&a[j]);
    cout<<ans;
}
void solve5()
{
    ll pre[200005],suf[200005],ans=0;
    pre[1]=a[1],pre[0]=(1<<30)-1,suf[n]=a[n],suf[n+1]=(1<<30)-1;
    for(int i=2;i<=n;i++)pre[i]=pre[i-1]&a[i];
    for(int i=n-1;i>=1;i--)suf[i]=suf[i+1]&a[i];
    for(int i=1;i<=n;i++)ans=max(ans,pre[i-1]&suf[i+1]);
    cout<<ans;
}
void solve6()
{
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20)solve1();
    else if(m==1)solve2();
    else if(m==n)solve3();
    else if(m==2&&n<=5000)solve4();
    else if(m==n-1)solve5();
    else solve6();
    return 0;
}
