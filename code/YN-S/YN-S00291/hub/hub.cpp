//I love Nagato Yuki forever!!!
#include<bits/stdc++.h>
using namespace std;
namespace Z3k7223{
    #define ll long long
    int n,k;
    const int N=1e6+10;
    vector<int>g[N];
    void solve_(){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n==k){
            cout<<"0\n";
            return;
        }
        if(n/2<=k){
            cout<<"1\n";
            return;
        }
        int m=n/2+1-(k-2);
        if(m%4==0){
            cout<<m/4<<'\n';
        }else{
            cout<<m/4+1<<'\n';
        }
    }
    void solve(){
        int c,t;
        scanf("%d%d",&c,&t);
        while(t--){
            solve_();
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    Z3k7223::solve();
    return 0;
}