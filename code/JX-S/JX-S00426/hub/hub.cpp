#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,e[5005][5005],ans;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int e=1;e<=t;e++)
    {
        cin>>n>>k;
        for(int i;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            ans+=u;
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}
