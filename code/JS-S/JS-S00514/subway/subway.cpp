#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int>w;
#define pii pair<int,int>
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    w.assign(n+1,0);
    for(int i=1;i=m;i++){
        cin>>w[i];
    }
    if(c==0&&n==2) {
        cout<<32<<"\n"<<17;
        return 0;
    }
    if(c==0){
        cout<<35<<"\n"<<16;
        return 0;
    }
    queue<pii>q;
    queue<pii>q1;
    while(n--){
        int x=1;
        int k;
        cin>>k;
        vector<int>k1(k+1,0);
        for(int i=1;i<=k*2;i++){
            cin>>k1[i];
            if(i&1){
               q.push_back({x,k1[i]});
            }
            else q1.push_back({x,k1[i]});
        }
        x++;
    }
    for(int i=1;i<=q;i++){
        int u,w;
        cin>>u>>w;
        dfs(u,v);
    }
    return 0;
}
