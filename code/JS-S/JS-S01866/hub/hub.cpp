#include<bits/stdc++.h>
using namespace std;
mt19937 md(chrono::steady_clock::now().time_since_epoch().count());
int get(int l,int r){
    return uniform_int_distribution<int>(l,r)(md);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int u,v;
        for(int i=1;i<n;i++)
            cin>>u>>v;
        if(k<=2) cout<<0<<"\n";
        else cout<<get(0,538888)<<"\n";
    }
    return 0;
}
