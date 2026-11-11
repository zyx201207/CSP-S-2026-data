#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>>son[501005];
int dist[501005];
const int inf=0x3f3f3f3f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                int a,t;
                cin>>a>>t;
                son[a+n].push_back({i,t});
                son[i].push_back({a+n,t});
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            int mark=w[x]+w[y];
            x+=n,y+=n;
            memset(dist,0x3f,sizeof dist);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            dist[x]=0;
            pq.push({0,x});
            while(pq.size()){
                pair<int,int>p=pq.top();
                pq.pop();
                int di=p.first;
                int uu=p.second;
                if(dist[uu]!=di)continue;
                for(auto pp:son[uu]){
                    int vv=pp.first;
                    int ww=pp.second;
                    if(dist[vv]>dist[uu]+ww){
                        dist[vv]=dist[uu]+ww;
                        pq.push({dist[vv],vv});
                    }
                }
            }
            cout<<mark+dist[y]<<"\n";
        }
    return 0;
}//32pts
