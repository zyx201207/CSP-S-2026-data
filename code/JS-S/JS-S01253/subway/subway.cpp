#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,d,q,k,u,v;
vector<int>w;
vector<vector<pair<int,int> > > a;
vector<vector<int> > b;
/*
void pre(){
}

void solve(){
}
*/
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    w.resize(m);a.resize(n);
    for (int i = 0;i < m;i++)   cin>>w[i];
    for (int i = 0;i < n;i++){
        cin>>k;
        a[i].resize(k);
        for (int j = 0;j < k;j++){
            cin>>a[i][j].first>>a[i][j].second;
            b[a[i][j].first].push_back(k);
        }
    }
    for (int i = 0;i < q;i++){
        cin>>u>>v;
        int cc = 1e18,cd = 1e18;
        for (int i = 0;i < b[u].size();i++){
            for (int j = 0;j < b[v].size();j++){
                if (b[u][i] == b[v][j]){
                    cc = min(a[b[u][i]][u].second,cc);
                    cd = min(a[b[v][j]][v].second,cd);
                }
            }
        }
        cout<<w[u] + w[v] + cc + cd<<"\n";
    }
    return 0;
}
