#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
vector<vector<int> > g,cnt;
void solve(){
    cin>>n>>d;
    vector<int> x(n+1);
    for(int i=1;i<=n;++i){
        cin>>x[i];
    }
    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;++j){
            int dist=x[j]-x[i];
            if(dist>d)break;
            g[i].push_back(j);
        }
    }


    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}
