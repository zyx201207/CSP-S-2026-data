#include<bits/stdc++.h>
using namespace std;
long long ans=0,n;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        string a;
        cin>>x>>a;
        for(long long j=1;j<=x;j++)
        {
            s+=a;
        }
    }
    for(long long i=0;i<=n/2;i++)
    {
        if(s[i]!=s[n-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
