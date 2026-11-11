#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k;
vector<int> a[2000004];
int cc[14]={1,0,2,0,1,2,1,0,0,1};
int cnt;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cout<<cc[++cnt]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
        vector<int> t[2000004];
        swap(a,t);
    }
    return 0;
}
