#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005],a[505][500005],t[505][500005],x[100005],y[100005];
vector<pair<int,int>> e[1005];
priority_queue<>q;
long long Dijkstra(int a,int b){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
        e[i].push_back({n+i,w[i]});
        e[n+i].push_back({i,w[i]});
    }
    for (int i=1;i<=n;i++){
        cin>>k[i];
        for (int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
        e[a[i][1]].push_back({n+a[i][1],t[i][1]});
        e[n+a[i][1]].push_back({a[i][1],t[i][1]});
        for (int j=2;j<=k[i];j++){
            e[a[i][j]].push_back({a[i][j-1],0});
            e[a[i][j-1]].push_back({a[i][j],0});
            e[a[i][j]].push_back({n+a[i][j],t[i][j]});
            e[n+a[i][j]].push_back({a[i][j],t[i][j]});
        }
    }
    for (int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for (int i=1;i<=2*n;i++)
        e[0].push_back({i,0});
    for (int i=1;i<=n;i++){
        cout<<Dijkstra(0,i);
    }
    return 0;
}
