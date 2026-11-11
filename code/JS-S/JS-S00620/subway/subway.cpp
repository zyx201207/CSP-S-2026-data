#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
#define d first
#define v second
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
typedef __gnu_pbds::priority_queue<pii,greater<pii> > heap;
const int N=6e5+7;
int c,n,m,d,t,cnt;
int w[N],dis[N];
vector <pii> p[N];
heap q;
heap::point_iterator it[N];
int dij(int x,int y){
    q.clear();
    for(int i=1;i<=n+m;i++){
        dis[i]=1e12;
        it[i]=NULL;
    }
    dis[x]=0;
    it[x]=q.push({0,x});
    while(!q.empty()){
        auto d=q.top().d,u=q.top().v;
        q.pop();
        for(auto e:p[u]){
            auto v=e.v,nd=d+e.d;
            if(dis[v]>nd){
                dis[v]=nd;

               if(it[v]!=NULL)
                    q.modify(it[v],{nd,v});
                else
                    it[v]=q.push({nd,v});
            }
        }
    }
    return dis[y];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int t,a;
            cin>>a>>t;
            p[a].push_back({t,m+i});
            p[m+i].push_back({t,a});
        }
    }
    while(t--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+dij(x,y)+w[y]<<'\n';
    }
    return 0;
}
