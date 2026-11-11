#include<bits/stdc++.h>
#define int long long
using namespace std;
char s[10000001];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,t=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
            s[t+j]=c;
        t+=a;
    }
    int ans=0;
    for(int i=1;i<t;i++)
    {
        if(s[i]!=s[t])ans++;
        t--;
    }
    cout<<ans;
    return 0;
}
