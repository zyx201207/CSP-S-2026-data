#include<bits/stdc++.h>
#define int long long
using namespace std;
char c;
unsigned long long d,z;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d>>c;
        if(d>=100000000)
        {
            cout<<0;
            return 0;
        }
        for(int j=1;j<=d;j++)
        {
            s=s+c;
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            z++;
            //cout<<i<<' '<<s.size()-i<<'\n';
            //cout<<s[i]<<' '<<s[s.size()-i-1]<<'\n';
        }
    }
    cout<<z;
    return 0;
}
