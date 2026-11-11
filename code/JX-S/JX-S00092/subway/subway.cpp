#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mp[510][510];
ll w[500010];
int c,n,m,q,d;
ll vis[510];
vector<pair<int,ll>>zt[500010] = {};//first line_zhantai ->dating  cost second
int dij(int st){//from st line to every line
    priority_queue<pair<ll,int>>q;//-cost id

    q.push({0,st});
    mp[st][st] = 0;
    for(int i = 0;i<508;i++){
        vis[i] = LONG_MAX;
    }vis[st] = 0;
    while(!q.empty()){
        pair<ll,int>nowq = q.top();
        q.pop();
        ll dis = nowq.first;
        dis = 0-dis;
        for(int i = 1;i<=n;i++){
            if(mp[nowq.second][i] < LONG_MAX && dis+mp[nowq.second][i]<vis[i]){
                vis[i] = dis+mp[nowq.second][i];
                q.push({0-vis[i],i});
            }
        }
    }
    //cout<<endl;
    for(int i = 1;i<=n;i++){
        mp[st][i] = vis[i];
        mp[i][st] = vis[i];
        //cout<<mp[st][i]<<" ";
    }//cout<<endl;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 0;i<508;i++){
        for(int j = 0;j<508;j++){
            mp[i][j] = LONG_MAX;
        }
    }
    //cout<<mp[1][1]<<" "<<INT_MAX<<" "<<((ll)(INT_MAX))*((ll)(INT_MAX))<<endl;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        for(int j = 1;j<=k;j++){
            int cnt,cost;
            cin>>cnt>>cost;
            zt[cnt].push_back({i,cost});
            for(int x = 0;x<zt[cnt].size()-1;x++){
                mp[zt[cnt][x].first][i] = min(mp[zt[cnt][x].first][i],cost+zt[cnt][x].second);
                mp[i][zt[cnt][x].first] = mp[zt[cnt][x].first][i];
            }
        }
    }
    for(int i = 1;i<=n;i++){
        dij(i);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans = LONG_MAX;
        for(int i = 0;i<zt[x].size();i++){
            for(int j = 0;j<zt[y].size();j++){
                //from i line to j line
                if(zt[x][i].second!=LONG_MAX && zt[y][j].second!=LONG_MAX && mp[zt[x][i].first][zt[y][j].first]!=LONG_MAX){
                    ans = min(ans,zt[x][i].second+zt[y][j].second+mp[zt[x][i].first][zt[y][j].first]);
                }
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
