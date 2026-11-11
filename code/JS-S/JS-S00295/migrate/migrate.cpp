#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int x[2000001];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>t;
    for(int T=1;T<=t;T++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }

    }

    return 0;
}
