#include<bits/stdc++.h>
using namespace std;
long long a[100010],l,r,cnt,n,i;
char s[100010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   cin>>n;for( i=1;i<=n;i++) cin>>a[i]>>s[i];
   l=1;r=n;
   while(l<=r)
   {
       if(l>=r)
       {

           cout<<cnt;return 0;
       }
       if(s[l]==s[r])
       {

           if(a[l]<a[r])
           {

               a[r]-=a[l];l++;
           }
           else if(a[l]>a[r])
           {

               a[l]-=a[r];r--;
           }
           else{
            l++;r--;
           }
       }
       else
        {
            cnt+=min(a[r],a[l]);
       if(a[l]<a[r])
       {
           a[r]-=a[l];l++;
       }
        else if(a[l]>a[r])
           {

               a[l]-=a[r];r--;
           }
           else{
            l++;r--;
           }
       }
   }
  cout<<cnt;
}
