#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> ve[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        cout<<n-1<<endl;
    }
    
    return 0;
}