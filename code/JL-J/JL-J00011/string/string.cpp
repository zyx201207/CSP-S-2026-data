#include <bits/stdc++.h>
using namespace std;
char a[1000000001];
int c[1000000001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   int n;
   cin>>n;
   int k=0;
   for(int i=1;i<=n;i++)
   {
       cin>>c[i];
       for(int j=1;j<=c[i];j++)
       {
           a[j+k]=c[i];
           k+=c[i];
       }
   }
   int ans=0;
   int len=strlen(a);
   for(int i=1;i<=len/2;i++)
   {
       if(a[i]!=a[len-i+1])
        ans++;
   }
   cout<<ans;
}

