#include <bits\stdc++.h>
using namespace std;
int main{
11 n,m,a[500050],qzh[500050],sum=1;
freopen("cystal.in","r",stdin)
freopen("crystal.out","w",stdout)
cin>>n>>m;
for(int i=1;i<n;i++)
{
   cin>>a[i];
}
sort(a+1,1+a+n);
for(int i=1;i<n;i++)
{
   qzh[i]=a[i]+qzh[i-1];
}
for(int i=2;i<=n;i++)
{
  11 j=i-n;
  while((i-j+1)*a[i]-(qzh[i]-qzh[j]<=m))
  {
    j--;
    if(j==0)
    {
       break;
    }

  }if(j!=0)
  {
     cout<<j<<' '<<i<<'\n';
  }
  sum=max(i-j,sum);
}
    cout<<sum;
}
