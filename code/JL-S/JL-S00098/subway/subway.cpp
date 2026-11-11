#include<bits/stdc++.h>
using namespace std;
const int N=1005;
#define int long long
int a[N];
int ai[505][N];
vector<pair<pair<int,int>,int>>v[505][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int k,lx,y;
        cin>>k>>lx>>y;
        v[i][lx].push_back({{lx,0},y});
//        cout<<1<<endl;
        v[0][lx].push_back({{lx,i},y});
//        cout<<endl<<v[0][lx].size()<<' '<<lx<<endl;
        for(int j=1,x;j<k;j++){
            cin>>x>>y;
            v[i][lx].push_back({{x,i},0});
            v[i][x].push_back({{lx,i},0});
            v[i][x].push_back({{x,0},y});
            v[0][x].push_back({{x,i},y});
            lx=x;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        vector<vector<int>>dis(n+1,vector<int>(m+1,INT_MAX));  
        vector<vector<int>>vis(n+1,vector<int>(m+1)); 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        dis[0][x]=0;
        q.push({0,{x,0}});
        while(q.size()){
            int u=q.top().second.first,top=q.top().second.second;
            q.pop();
            if(vis[top][u])continue;
            vis[top][u]=1;
            for(auto i:v[top][u]){
                if(dis[i.first.second][i.first.first]>dis[top][u]+i.second){
                    dis[i.first.second][i.first.first]=dis[top][u]+i.second;
                    q.push({dis[i.first.second][i.first.first],{i.first.first,i.first.second}});
                }
            }
        }
        cout<<dis[0][y]+a[y]+a[x]<<endl;
    }
    return 0;
}