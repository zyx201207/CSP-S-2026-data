#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
string s;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        string ai;
        cin>>ai;
        for(int j=1;j<=k;j++)
        {
            s=s+ai;
        }
    }
    for(int i=0,j=s.size()-1;i<j;i++,j--)
    {
        if(s[i]!=s[j])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
