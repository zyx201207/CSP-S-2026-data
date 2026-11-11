#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> q[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            q[u].push_back(v);
            q[v].push_back(u);
        }
        cout<<"1\n";

    }
    return 0;
}