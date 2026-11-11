#include <bits/stdc++.h>
long long  n,m,a[1010];
using namespace std;
int main()
{
   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
   cin>>n>>m;for(int i=1;i<=n;i++)
   {
       scanf("%lld",&a[i]);

   }
   sort(a+1,a+n+1);
   if(n==1)
   {

       cout<<1;return 0;
   }
   if(n==2)
   {

       if((a[1]-a[2]<=0)&&(a[2]-a[1]<=m)) cout<<2;
       else cout<<1;
       return 0;
   }
   if(n==3)
   {
       if(a[3]*2-a[1]-a[2]<=m) cout<<3;
       else if(a[3]-a[1]<=m||a[3]-a[2]<=m) cout<<2;
       else if(a[2]-a[1]<=m) cout<<2;
       else cout<<1;return 0;
   }
    if(n==4)
    {
        if(a[4]*3-a[2]-a[3]-a[1]<=m) cout<<4;
        else if(a[4]*2-a[3]-a[2]<=m||a[4]*2-a[1]-a[2]<=m||a[4]*2-a[3]-a[1]<=m||a[3]*2-a[1]-a[2]<=m) cout<<3;
       else if(a[4]-a[1]<=m||a[4]-a[3]<=m||a[4]-a[3]<=m||a[3]-a[2]<=m||a[3]-a[1]<=m||a[2]-a[1]<=m) cout<<2;
       else cout<<1;
        return 0;
    }
    if(n==5)
    {
         if(a[5]*4-a[2]-a[3]-a[1]-a[4]<=m) cout<<5;
        else if(a[5]*3-a[4]-a[3]-a[2]<=m||a[5]*3-a[4]-a[3]-a[1]<=m||a[5]*3-a[4]-a[1]-a[2]<=m||a[5]*3-a[3]-a[1]-a[2]<=m&&a[4]*3-a[2]-a[3]-a[1]<=m) cout<<4;
       else if(a[4]*2-a[3]-a[2]<=m||a[4]*2-a[1]-a[2]<=m||a[4]*2-a[3]-a[1]<=m||a[3]*2-a[1]-a[2]<=m||a[5]*2-a[4]-a[3]<=m||a[5]*2-a[4]-a[2]<=m||a[5]*2-a[4]-a[1]<=m||a[5]*2-a[3]-a[2]<=m||a[5]*2-a[3]-a[1]<=m||a[5]*2-a[2]-a[1]<=m) cout<<3;
       else if(a[4]-a[1]<=m||a[4]-a[3]<=m||a[4]-a[3]<=m||a[3]-a[2]<=m||a[3]-a[1]<=m||a[2]-a[1]<=m||a[5]-a[4]<=m||a[5]-a[3]<=m||a[5]-a[2]<=m||a[5]-a[1]<=m) cout<<2;
       else cout<<1;
        return 0;
    }
    cout<<1;return 0;
}
