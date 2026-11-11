#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s="";
    long long n,ans=0,l=0;
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        long long x;
        char c;
        cin>>x>>c;
        l+=x;
        for(long long j=0;j<x;j++)
        {
            s+=c;
        }
    }
    for(long long i=0;i<l;i++)
    {
        if(s[i]!=s[l-i-1])
        {
            ans++;
            s[l-1-i]=s[i];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
