#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=4e5+10;
char s[maxn];
int f[maxn];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  int n,sum=0,l,r,mid,c=0,e=0,ans=0,q,u,v;
  cin>>n;
  for(int i=1;i<=n;++i){cin>>f[i]>>s[i];sum+=f[i];}
mid=(sum+1)>>1;
if(s[1]!=s[n])ans+=min(f[1],f[n]);
c+=f[1],e+=f[n];
l=2,r=n-1;
while(l<=r)
{
    if(c<e)
    {
        u=e-c;
        if(r==l+1)
        {
            v=mid-c;
            if(s[r]!=s[l])ans+=min(v,u);
            break;
        }
        if(s[l]!=s[r+1])ans+=min(u,f[l]);
        c+=f[l];
        ++l;
    }
    else if(c>e)
    {
 u=c-e;
        if(r==l+1)
        {
            v=mid-e;
            if(s[r]!=s[l])ans+=min(v,u);
            break;
        }
        if(s[l-1]!=s[r])ans+=min(u,f[r]);
        e+=f[r];
        --r;
    }
    else 
    {
        if(r==l)break;
        if(r==l+1)
        {
            if(s[l]!=s[r])ans+=min(f[l],f[r]);
            break;
        }
        if(s[l]!=s[r])ans+=min(f[l],f[r]);
        c+=f[l];
        e+=f[r];
        ++l;
        --r;
    }
}
cout<<ans;
}