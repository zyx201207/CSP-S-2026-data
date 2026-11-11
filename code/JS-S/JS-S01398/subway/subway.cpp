#include<bits/stdc++.h>
#define Pair pair<int,int>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,a[505][N],t[505][N],w[N],k[N],ans,vis[N];
vector<int> in[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            in[a[i][j]].push_back(j);
        }
    }
    int timer=1;
    while(q--){
        timer++;
        int x,y;cin>>x>>y;
        ans=w[x]+w[y];
        priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
        pq.push({0,x});
        while(!pq.empty()){
            int id=pq.top().second,val=pq.top().first;
            pq.pop();

            if(vis[id]==timer) continue;
            vis[id]=timer;
            if(id==y){
                cout<<ans+val<<"\n";
                break;
            }
            for(int i:in[id]){
                for(int j=1;j<=k[i];j++){
                    if(j==id) continue;

                    pq.push({val+t[i][id]+t[i][j],a[i][j]});
                }
            }
        }

    }
    return 0;
}
