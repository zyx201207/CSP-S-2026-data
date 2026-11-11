#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s="";
    for(long long i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        for(long long j=1;j<=a;j++)
            s+=b;
    }
    string k=s;
    reverse(s.begin(),s.end());
    long long cuowu=0;
    for(long long i=0;i<s.size()/2;i++)
    {
        if(k[i]!=s[i])
        {
            k[i]=s[i];
            cuowu++;
        }
    }
    cout<<cuowu;
    return 0;
}
