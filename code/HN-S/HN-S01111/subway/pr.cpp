#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1,w;i<=m;i++) cin>>w;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;cin>>a>>t;
        }
    }
    vector<pair<int,int>> a(q);
    while(q--){
        int x,y;cin>>x>>y;
        if(x>y) swap(x,y);
        a[q]={x,y};
    }
    sort(a.begin(),a.end());
    for(auto[x,y]:a) cout<<x<<' '<<y<<'\n';
    return 0;
}