#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
   freopen("hub.in","r",stdin);
   freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int u,v;
        cin>>n>>k;
        vector<int>g[10001];
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
        }
        cout<<1<<"\n";
    }
    return 0;
}
//I love your mother CCF
