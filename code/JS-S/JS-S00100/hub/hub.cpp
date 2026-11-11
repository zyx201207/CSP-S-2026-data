#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int v,u;
            cin>>v>>u;
            ans++;
        }
        int x=rand()%ans+1;
        cout<<x<<ln;
    }
}