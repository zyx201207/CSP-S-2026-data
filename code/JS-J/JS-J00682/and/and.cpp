#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
long long ans,ans1;
long long n,m;
long long qq=0;
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(long long w,long long e,long long g)
{
    if(w==n+1&&e==m+1)
    {
        if(g>qq) qq=g;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        dfs(w+1,e,g);
        dfs(w+1,e+1,g&a[i]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ans=max(ans,a[i]);
        if(i==1) ans1=a[i];
        else ans1&=a[i];
    }
    if(m==1) cout<<ans;
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
             ans=max(ans,a[i]&a[j]);
        cout<<ans;
    }
    else if(m==n) cout<<ans1;
    else if(n<=20)
         {
             dfs(0,0,2^30-1);
             cout<<qq;
         }
         else
         {
             long long ans4=2^30-1;
             sort(a+1,a+n+1,cmp);
             for(int i=1;i<=m;i++) ans4&=a[i];
             cout<<ans4;
         }
    return 0;
}
