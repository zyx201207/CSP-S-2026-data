#include <bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
int c,n,m,d,q,x,y;
int w[M],dist[M];
struct Sub{
    int u,t;
}a[N][M];
vector<int>line[M];
long long ans=0;
void dfs(int k,int e){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j].u>>a[i][j].t;
            line[i].push_back(a[i][j].u);
        }
    }
    while(q--){
        cin>>x>>y;
    cout<<0<<'\n';
    }
    return 0;
}
