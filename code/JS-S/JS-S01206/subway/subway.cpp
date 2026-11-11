#include <bits/stdc++.h>
using namespace std;
int main(){
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
    if(a[i]=a[i-1]) s[++c][0]=a[i]-a[i-1];
    else s[c][1]++;
}
for(int i=2;i<=n;i++)
{
    s[i][0]=s[i][0]+s[i-1][0];
}
for(int i=2;i<=n;i++)
{
    s[i][0]=s[i][0]*s[i][1]+s[i-1][0];
}
ans=s[1][1]+1;
for(int i=1,j=1;i<=j,i<n,j<=n;i++)
{
    if(s[i][1]=0)
    {
        if(s[j][i]=0)
        {
          if(s[j][0]-s[i][0]<=m)
          {
            ans=max(ans,j-i+1);
          }
        }
    }
   else
    {
        i++;

    }
    cout<<ans;
}
return 0;
}
