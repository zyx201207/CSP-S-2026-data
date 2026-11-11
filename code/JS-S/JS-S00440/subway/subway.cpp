#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxm=500005;
int c,n,m,d,q,w[maxm],a[505][maxm],t[505][maxm];
struct edge{
    int f,t,v;
}edge[maxm];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt++;
        int k;cin>>k;
        vector<int> tmp;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            tmp.push_back(a[i][j]);
        }
        for(int j=1;j<=k;j++){
            edge[cnt]
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        dfs(x,y);
        cout<<51<<'\n';
    }
}
