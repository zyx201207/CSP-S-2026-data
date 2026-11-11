#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int w[N];
struct nod{
    int a,t;
};
vector<nod>ve[505],vea[N];
int dis[N],vis[N];
bool operator <(nod x,nod y){
    return x.t>y.t;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k,maxk=0;
    for(int i=1;i<=n;i++){
        cin>>k;
        maxk=max(maxk,k);
        int a,t;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            ve[i].push_back({a,t});
        }
    }
    if(maxk<=2){
        for(int i=1;i<=n;i++){
            int w=ve[i][0].t+ve[i][1].t;
            vea[ve[i][0].a].push_back({ve[i][1].a,w});
            vea[ve[i][1].a].push_back({ve[i][0].a,w});
        }
        int x,y;
        for(int i=1;i<=q;i++){
            for(int i=1;i<=m;i++){
                dis[i]=1e18;
                vis[i]=0;
            }
            cin>>x>>y;
            int ans=w[x]+w[y];
            priority_queue<nod>pq;
            pq.push({x,0});
            dis[x]=0;
            while(!pq.empty()){

                nod h=pq.top();
                pq.pop();
                if(vis[h.a]){
                    continue;
                }
                vis[h.a]=1;
                for(auto x:vea[h.a]){
                    if(dis[x.a]>dis[h.a]+x.t){
                        dis[x.a]=dis[h.a]+x.t;
                        pq.push({x.a,dis[x.a]});
                    }
                }
            }
            ans+=dis[y];
            cout<<ans<<"\n";
        }
    }
    return 0;
}
