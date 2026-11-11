#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int g=a[1];
    for(int i=2;i<=n;i++)
        g=__gcd(g,a[i]);
    for(int i=1;i<=n;i++)
    {
        a[i]/=g;
        string t(a[i],c[i]);
        s+=t;
    }
    string r=s;
    reverse(r.begin(),r.end());
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=r[i])
            ans++;
    cout<<ans*g;


    return 0;
}
