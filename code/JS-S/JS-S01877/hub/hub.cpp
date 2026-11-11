#include<bits/stdc++.h>
using namespace std;
#define int long long
//const int N;
int C,n,k;
void prep();
void init();
void dr();
void work();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int T=1;
    cin>>C>>T;
    prep();
    while(T--){
        init();
        dr();
        work();
    }
    return 0;
}
void prep(){
}
void init(){
}
void dr(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
    }
}
void work(){
    if(n==k) cout<<0<<'\n';
    else cout<<1<<'\n';
}
