#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
vector<ll> E[110];

void clear(){
    for(int i=1;i<=n;i++){
        E[i].clear();
    }
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
        clear();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
Wow user 1365 get 0 points in hub!Share it!

——————————————————————

T4大失败了。想要整活。

想要在CSP-S SH迷惑行为上青史留名，怎么办呢？

到底该写什么呢？让我想一下？

到底是什么呢？

……

（一阵激烈的歌唱声音响起，一只芙兰fumo出现在了你的眼前……）

*/