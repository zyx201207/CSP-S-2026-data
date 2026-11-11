#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
map<char,int> m;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        m[c[i]]+=a[i];
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    int cnt=0,ans=0x7f7f7f7f7f7f7f7f;
    for(int i='a';i<='z';i++)
    {
        if(m[i]>0)
        {
            ans=min(ans,m[i]);
            cnt++;
        }
    }
    if(cnt==1)
    {
        cout<<0;
        return 0;
    }
    else
    {
        cout<<ans<<"\n";
        return 0;
    }
    return 0;
}
