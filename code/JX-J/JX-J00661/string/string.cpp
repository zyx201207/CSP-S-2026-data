#include <bits/stdc++.h>
using namespace std;
int n,a[200005],num=0;
long long z[26],sum=0;
char c[200005];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i]>>c[i];
       z[((int)c[i]-96)]+=a[i];
       sum+=a[i];
   }
   for(int i=1;i<=26;i++)
   {
       if(z[i]!=0)
       {
           num++;
       }
   }
   if(n==1)
   {
       cout<<0;
       return 0;
   }
   else if(n==2){
   if(c[1]==c[2])
   {
       cout<<0;
       return 0;
   }
   else{
        cout<<min(a[1],a[2]);
   }
   }
   else if(num==2)
   {
       sort(z+1,z+26+1);
       cout<<z[25];
   }
   else
   {
       cout<<sum/2;
   }
}
