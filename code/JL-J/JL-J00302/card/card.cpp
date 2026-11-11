#include<iostream>
using namespace std;
long long n3[1000000];
int n1[1000000];
int n[1000000];
int main()
{
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   long long a,b;
   cin>>a>>b;
   long long n2[a],e,s,l=0;
   for(int i=0;i<a;i++)
   {
       cin>>n[i];
       n2[i]=i+1;
   }
   for(int i=0;i<a;i++)
   {

       for(int j=i;j<a;j++)
       {
          for(int k=i;k<j;k++)
          {
             if(n[j]==n[k] && j!=k)
             {
                e=j-k;
                break;
             }
          }
          int l=j-e;
          n1[l]=n[j];
       }
       e=0;
       for(int j=0;j<a;j++)
       {
           for(int k=0;k<b;k++)
           {
               if(n2[k]==n1[j])
                n3[k]+=1;
           }
       }
       for(int p=0;p<a;p++)
       n1[p]=0;
   }


   for(int p=0;p<b;p++)
    cout<<n3[p]<<" ";
   return 0;
}
