#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct UndergroundStation{
    vector<pair<int,int>> lines;
    int dis2gnd;
}UndergroundStations[50086];
vector<pair<int,int>> UndergroundLines[50086];
int dis[50086],k[50086];
void bfs(int x,int y){
    fill(dis,dis+m+1,1e9);
    dis[x]=0;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int t=q.front(); q.pop();
        for(auto i:UndergroundStations[t].lines){
            for(auto j:UndergroundLines[i.first]){
                if(dis[j.first]>=dis[t]+i.second+j.second){
                    dis[j.first]=dis[t]+i.second+j.second;
                    q.push(j.first);
                }
            }
        }
    }
    cout<<dis[y]+UndergroundStations[x].dis2gnd+UndergroundStations[y].dis2gnd<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>UndergroundStations[i].dis2gnd;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t; cin>>a>>t;
            UndergroundStations[a].lines.push_back(make_pair(i,t));
            UndergroundLines[i].push_back(make_pair(a,t));
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        bfs(x,y);
    }
    return 0;
}