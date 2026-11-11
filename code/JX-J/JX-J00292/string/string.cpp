#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,ans=0;
    string s,c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    for(int i=1;i<=s.length()/2;i++)
    {
        if(s[i-1]!=s[s.length()-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
