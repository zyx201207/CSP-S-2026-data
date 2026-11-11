#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010];
int main()
{freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 cin>>a[i];
 sort(a+1,a+1+n);
 for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
 int l=1,r=n;
 while(l<r)
 {int mid=(l+r+1)>>1;bool ac=0;
  for(int i=mid;i<=n;i++)
  if((__int128)a[i]*mid-(s[i]-s[i-mid])<=m) ac=1;
  if(ac) l=mid;
  else r=mid-1;
 }
 cout<<l;
}
