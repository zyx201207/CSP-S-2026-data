#include<bits/stdc++.h>
using namespace std;
long long n;
string s="",s1;
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        while(a--)  s+=b;
    }
    s1=s;
    reverse(s1.begin(),s1.end());
    long long l=s.size();
    for(long long i=0;i<l/2+1;i++)
    {
        if(s[i]!=s1[i])
        {
            s1[i]=s[i];
            s[l-i-1]=s[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
