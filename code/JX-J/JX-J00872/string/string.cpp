#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s;
    for(long long i=1; i<=n; ++i)
    {
        long long a;
        char b;
        cin>>a>>b;
        for(long long i=1; i<=a; ++i)
        s=s+b;
    }
    long long l=0,r=s.size()-1;
    while(l<r)
    {
        if(s[l]!=s[r]) ans++;
        l++,r--;
    }
    cout<<ans;
    return 0;
}
