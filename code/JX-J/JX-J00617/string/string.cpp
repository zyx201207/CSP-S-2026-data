#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s;
    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        char c;
        cin>>c;
        for(long long j=1;j<=x;j++)
        {
            s+=c;
        }
    }
    long long l=s.size();
    for(long long i=0;i<=l/2;i++)
    {
        if(s[i]!=s[l-i])
            ans++;
    }
    cout<<ans;
    return 0;
}
