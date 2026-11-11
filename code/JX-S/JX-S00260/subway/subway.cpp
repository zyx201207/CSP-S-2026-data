#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,q;
int w[N],a[505][N],t[505][N],ans=INT_MAX;
vector< pair<int,int> > v[N];
void dfs(int x,int e,int tim){
    if(x==e){
        ans=min(ans,tim);
        return;
    }
    x++;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
           cin>>a[i][j]>>t[i][j];
           v[a[i][j-1]].push_back({a[i][j],t[i][j]});
        }
    }
    for(int o=1;o<=q;o++){
        int sx,ex;
        cin>>sx>>ex;
        dfs(sx,ex,w[sx]+w[ex]);
        cout<<ans;
        ans=INT_MAX;
    }
    cout<<n*m;
    return 0;
}
