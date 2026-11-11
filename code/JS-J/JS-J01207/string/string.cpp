#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+1;
int main()
{
    freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);


    string s,q;
    string a;
    long long len=0,res1=0,res2=0;
    int c,n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c>>a;
        len+=c;
        for(long long j=1;j<=c;j++)
            s+=a;
            q+=a;
    }
    //cout<<s<<endl;;
     for(long long l=1;l<=len/2-1;l++)
     {
         for(long long r=len+1;r>=len/2;r--)
         {
             if(s[l]!=s[r]&&s[l]!=NULL&&s[r]!=NULL)
             {
                 res1++;
                 //cout<<s[l]<<' '<<s[r]<<endl;
                 //cout<<s<<endl;
                                  s[l]=s[r];


             }



             }
         }
     }
     cout<<res1;
     return 0;
}
