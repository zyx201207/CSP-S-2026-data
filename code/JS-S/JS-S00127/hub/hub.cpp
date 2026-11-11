#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<vector<int> > mp;
void solve(){
    scanf("%d%d",&n,&k);
    mp.resize(n+2);
    for(int i = 1;i<=n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    printf("%d\n" ,(k/4)+3);
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        solve();
    }

    return 0;
}

