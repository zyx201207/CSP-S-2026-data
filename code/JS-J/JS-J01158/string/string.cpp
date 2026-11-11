#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string s;
    long long n,j=0,ans=0;
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        long long t;
        char k;
        cin>>t>>k;
        long long m=j+t;
        for(;j<m;j++)
            s[j]=k;
    }
    for(long long i=0;i<j/2;i++)
    {
        if(s[i]!=s[j-i-1])
            ans++;
    }
    cout<<ans;
    return 0;
}
