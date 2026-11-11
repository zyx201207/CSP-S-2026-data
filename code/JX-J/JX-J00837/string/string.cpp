#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    long long a;
    char c;
    long long l=0,ans=0;
    string s=" ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        l+=a;
        if(l>=100000000) cnt=1;
        if(cnt==0)
        {
            for(int j=1;j<=a;j++)
            {
               s=s+c;
            }
        }
        else
        {
            for(int j=1;j<=a/100000;j++)
            {
               s=s+c;
            }
        }
    }
    if(cnt==0)
    {
       for(int i=1;i<=l/2;i++)
       {
           if(s[i]!=s[l+1-i])
           {
               s[l+1-i]=s[i];
               ans=ans+1;
           }
           else
           {
               continue;
           }
       }
    }
    else
    {
        l/=100000;
        for(int i=1;i<=l/2;i++)
        {
           if(s[i]!=s[l+1-i])
           {
               s[l+1-i]=s[i];
               ans=ans+100000;
           }
           else
           {
               continue;
           }
        }
        if(l%2!=0) ans+=500;
    }
    cout<<ans;
    return 0;
}
