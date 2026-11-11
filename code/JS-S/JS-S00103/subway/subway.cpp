#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
struct edge{
    int v,w;
};
vector<edge> e[505];
int w[N],k[N];
vector<int> a[N],t[N];
vector<edge> c;
priority_queue<pair<int,int>> ed;
bool vis[505];
ll dis[505];
void djiskra(int a){
    ed.push({0,a});
    while(!ed.empty()){

        auto tmp=ed.top();
        ed.pop();
        dis[tmp.second]=tmp.first;
        for(auto x:e[tmp.second]){
            if(dis[tmp.second]-x.v<=dis[x.w]&&dis[x.w]!=1) continue;
            ed.push({dis[tmp.second]-x.v,x.w});
        }

    }
}
int main(){// ll!!!!!!!!!!!!!!!!!
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


//    for(int i=1;i<=10;i++){
//        for(int j=10;j<=20;j++){
//            ed.push({i,j});
//        }
//    }
//    while(!ed.empty()){
//        auto tmp=ed.top();
//        ed.pop();
//        cout<<tmp.first<<" "<<tmp.second<<endl;
//    }



    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int qwqw,m,n,d,q;
    cin>>qwqw>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        while(c.size())c.pop_back();
        for(int j=1;j<=k[i];j++){
            int aa,tt;
            cin>>aa>>tt;
            a[i].push_back(aa);
            t[i].push_back(tt);
            //cout<<i<<" "<<j<<endl;
            c.push_back({aa,tt});
        }
        for(int j=1;j<c.size();j++){
            for(int k=0;k<j;k++){
                e[c[j].w].push_back({c[k].w,c[j].w+c[k].w});
                e[c[k].w].push_back({c[j].w,c[j].w+c[k].w});
            }
        }
        //cout<<114515;
    }
//    cout<<114515;
    while(q--){//qing kong hai mei xie

        ll x,y;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            dis[i]=1;
        }
        ll ans=2147283647;
        for(int j=0;j<a[x].size();j++){
            djiskra(a[x][j]);
            for(int k=0;k<a[k].size();k++)
                ans=min(ans,w[x]+w[y]-dis[k]);
        }

//        for(int i=1;i<=n;i++){
//            cout<<dis[i]<<endl;
//        }
        cout<<ans<<endl;
    }
    return 0;
}
