#include<iostream>
#include<vector>
using namespace std;
long long o=1000000000000;
long long a1[200000000];
int main()
{
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);

     char d;
     long long n,b,e=0,s=0,l;
     cin>>n;

     for(long long  i=0;i<n;i++)
     {
         cin>>b>>d;
         for(long long j=0;j<b;j++)
         {
            int o=e+j;
            a1[o]=d;
            l=e+j;
         }
         e+=b;
     }



     for(long long i=0;i<(l+1)/2;i++)
     {
        if(a1[i]!=a1[l-i])
        {

            s+=1;
                    }
     }
     cout<<s;
     return 0;



}
