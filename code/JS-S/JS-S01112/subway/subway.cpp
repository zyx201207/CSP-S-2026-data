#include <bits/stdc++.h>
#define int long long
const int inf=1e14;
using namespace std;
map<pair<int,int>,vector<pair<pair<int,int>,int>>>mp;
int c,n,m,d,Q,w[555555],dis[500][500][500];
vector<int>g[555555];
queue<pair<pair<int,int>,int>>q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,x;
            cin>>u>>x;
            g[i].push_back(u);
            mp[{u,i}].push_back({{u,0},x});
            mp[{u,0}].push_back({{u,i},x});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=n;k++){
                dis[i][j][k]=inf;
            }
        }
    }
    for(int i=1;i<=m;i++){
        while(!q.empty()){
            q.pop();
        }
        q.push({{i,0},w[i]});
        dis[i][i][0]=w[i];
        while(!q.empty()){
            int x=q.front().first.first,sub=q.front().first.second,step=q.front().second;
            q.pop();
            if(sub==0){
                for(int j=0;j<mp[{x,sub}].size();j++){
                    int next_sub=mp[{x,sub}][j].first.second,next_step=mp[{x,sub}][j].second;
                    if(dis[i][x][next_sub]>step+next_step){
                        dis[i][x][next_sub]=step+next_step;
                        q.push({{x,next_sub},dis[i][x][next_sub]});
                    }
                }
            }
            else{
                int this_sub=mp[{x,sub}][0].first.second,this_step=mp[{x,sub}][0].second+step;
                bool f=0;
                for(int j=0;j<g[sub].size();j++){
                    int nx=g[sub][j];
                    if(dis[i][nx][sub]>step){
                        dis[i][nx][sub]=step;
                        q.push({{nx,sub},dis[i][nx][sub]});
                    }
                }
                if(dis[i][x][this_sub]>this_step){
                    dis[i][x][this_sub]=this_step;
                    q.push({{x,this_sub},dis[i][x][this_sub]});
                    f=1;
                }
                if(f==0)
                    continue;
                for(int j=0;j<mp[{x,this_sub}].size();j++){
                    int next_sub=mp[{x,this_sub}][j].first.second,next_step=mp[{x,this_sub}][j].second;
                    if(dis[i][x][next_sub]>this_step+next_step){
                        dis[i][x][next_sub]=this_step+next_step;
                        q.push({{x,next_sub},dis[i][x][next_sub]});
                    }
                }
            }
        }
    }
    while(Q--){
        int s,t;
        cin>>s>>t;
        cout<<dis[s][t][0]+w[t]<<endl;
    }
}
