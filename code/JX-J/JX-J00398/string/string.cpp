#include<bits/stdc++.h>
using namespace std;
int main()
{

 freopen("string.in","r",stdin);
 freopen("string.out","w",stdout);

 int n,cnt=0,step=0;
 char s[100005];
 long long a[1000005];
 char c[100005];
 cin>>n;
 for(int i=1;i<=n;i++)
 {
     cin>>a[i]>>c[i];
     while(a[i]--)
     {
         s[cnt++]=c[i];
     }
 }
 int flag=0;
 for(int i=1;i<cnt;i++)
 {
     if(s[i]!=s[i++])
     {
         flag=1;
     }
 }
 if(flag!=1)
 {
   cout<<"0";
   return 0;
 }
 for(int i=1;i<=cnt;i++)
 {
     if(s[i]!=s[cnt+1-i])
     {
      s[cnt+1-i]=s[i];
      step++;
     }
 }
 cout<<step;
 return 0;
}
