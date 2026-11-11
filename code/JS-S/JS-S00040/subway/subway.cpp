#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[100005];
vector<pair<int,int>> ve[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int u;
        cin>>u;
        for(int j=1;j<=x-1;j++){
            int v,w;
            cin>>v>>w;
            ve[u].push_back({v,w});
            u=w;
        }
    }
    cout<<ve[u][0];
    return 0;
}
