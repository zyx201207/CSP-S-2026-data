#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[500010],s[500010],ans=0,c=0;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
    for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=2;i<=n;i++)
{
    s[i]=a[i+1]-a[i];
}
for(int i=2;i<=n;i++)
{
    s[i]=s[i]+s[i-1];
}
for(int i=2;i<=n;i++)
{
    s[i]=s[i]*s[i]+s[i-1];
}
ans=s[1]+1;
for(int i=1,j=1;i<=j,i<n,j<=n;i++)
{
    if(s[i]=0)
    {
        if(s[j]=0)
        {
          if(s[j]-s[i]<=m)
          {
            ans+=max(s[i]+2,i+1);
          }
        }
    }
   else
    {
        j++;

    }
    cout<<ans;
}
return 0;
}
