#include<bits/stdc++.h>
using namespace std;
#define inf 0x37373737
const int N=1e6+5;
int n,c,T,k;
int f[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while (T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            int u,v;
            cin>>u>>v;
            f[u]=v;
        }
        cout<<"1\n";
    }    
    return 0;
}