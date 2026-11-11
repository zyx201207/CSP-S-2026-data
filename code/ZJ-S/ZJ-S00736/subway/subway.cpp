#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1009];
struct Line{
    int k,a[1009],t[1009];
}mp[509];
struct node{
    int id;
    long long step;
};
long long dp[1009][1009];
void dfs(int x){
    queue<node> q;

    while(!q.empty()){
        node t=q.front();
        q.pop();

    }
}
void solve(){
    for(int i=1;i<=n;i++){
        dfs(i);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<rand();
    }
    return 0;
}
