#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//scanf("%lld%lld",&a,&b);
//printf("%lld",a*b);

const ll N = 1e6+5;

vector<int> mapa[N];
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> h;
ll c,m,n,d,q;
ll w[1000];
ll lenth[10100][10100];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int cnt = m+1;
    //cout<<1111111111;
//    for(int i=1;i<=10100;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;cin>>x>>y;
            mapa[x].push_back(cnt);lenth[x][cnt] = y;
            mapa[cnt].push_back(x);lenth[cnt][x] = y;

        }
        cnt++;
    }

    while(q--){
        ll ans = 0;
        //cout<<1;
        ll dis[N];
        memset(dis,0x7f,sizeof(dis));
        //cout<<dis[100];
        int x,y;cin>>x>>y;
        int vis[50000]={};vis[x] = 1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> qa;
        qa.push({0,x});
        dis[x] = 0;

        while(!qa.empty()){
            //int flag = INT_MAX;
            int u = qa.top().second;qa.pop();
            //cout<<u<<' ';
            for(auto v:mapa[u]){
                if(v!=u&&vis[v]==0){
                    //cout<<1;
                    int w = lenth[u][v];
                    //cout<<w;
                    if(w+dis[u]<=dis[v]){
                        if(y==v){
                            ans = dis[u]+w;
                        }
                        vis[v] = 1;
                        dis[v] = dis[u]+w;
                        //cout<<dis[v]<<' ';
                        qa.push({dis[v],v});
                    }
                }
            }//cout<<endl;

        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
