#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200007];
ll sum=0,ans=0;
char c[200007];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            ans++;
        }
    }
    cout<<ans/2;
    return 0;
}
