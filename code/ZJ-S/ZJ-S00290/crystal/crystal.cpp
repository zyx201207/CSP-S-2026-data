#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=5e5+10;
int f[maxn];
signed main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m,ans=0,l=0,r,e,x;
cin>>n>>m;
r=n;
for(int i=1;i<=n;++i)cin>>f[i];
sort(1+f,f+1+n);
l=0;
while(l<=r)
{
e=x=0;
    int mid=(l+r)>>1;
    for(int i=1;i<=mid;++i)  e+=f[mid]-f[i];
    if(e<=m)x=1;
    for(int i=mid+1;i<=n;++i)
    {
        e+=(f[i]-f[i-1])*mid;
        e-=f[i]-f[i-mid];
if(e<=m)x=1;
    }
if(x)
{
    ans=max(mid,ans);
    l=mid+1;
}
else r=mid-1;
}
cout<<ans;
return 0;
}
