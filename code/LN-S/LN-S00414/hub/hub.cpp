#include<bits/stdc++.h>
using namespace std;
vector<int>e[100005];
void c1314()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(k>=n)
    {
        cout<<0<<endl;
        return;
    }
    cout<<(n/2-k+3)/4+1;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==13||c==14||c==0)
    {
        while(t--)
            c1314();
    }
    return 0;
}
