#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long ans,b,c,d,e,f,g,h,l,k,n,m,i,j;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   cin>>n>>m;
   for(i=1;i<=n;i++)
   {
       cin>>a[i];
   }
   ans=a[1];
    for(i=2;i<=n;i++)
    {
        ans=ans&a[i];
    }
    if(ans!=1)
    cout<<ans;
    else
        cout<<1;
    return 0;
}
