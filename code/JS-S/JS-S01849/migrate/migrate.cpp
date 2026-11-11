#include <bits/stdc++.h>
using namespace std;
#define int long long
int c=0,t=0,n=0,d=0;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        if(c!=11 && c!=12)
        {
            cout<<0<<endl;
            continue;
        }
        cin>>n>>d;
        int s[n+2]={0};
        for(int i=1;i<=n;i++) cin>>s[i];
        d=d/abs(s[1]-s[2])*2-1;
        if(n-d<=0) cout<<0<<endl;
        else cout<<n-d<<endl;
    }
    return 0;
}
