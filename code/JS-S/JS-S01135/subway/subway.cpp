#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int et[500005],fnd[500005][501];
vector<int> lne[501],stn[500005],chng[505];
int tsb[500005][501];
int ch[505][505];
int dis[504];
int bfs(int s,int t,int sst,int tst){
    int ans = 1e9;
    for(int i = 1;i <= 500;i++){
        dis[i] = 1e9;
    }
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty()){
        for(int i = 0;i < chng[q.front()].size();i++){
            if(dis[q.front()] + ch[q.front()][chng[q.front()][i]] <= dis[chng[q.front()][i]]){
                q.push(chng[q.front()][i]);
                dis[chng[q.front()][i]] = dis[q.front()] + ch[q.front()][chng[q.front()][i]];
                if(chng[q.front()][i] == t){
                    ans = min(dis[t] + fnd[sst][s] + fnd[tst][t],ans);
                }
            }
        }
        q.pop();
    }
    if(sst == tst){
        dis[t] = 0;
    }
    ans = min(dis[t] + fnd[sst][s] + fnd[tst][t],ans);
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie();
    cout.tie();
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> et[i];
    }
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        for(int j = 1;j <= x;j++){
            int st,tm;
            cin >> st >> tm;
            lne[i].push_back(st);
            stn[st].push_back(i);
            fnd[st][i] = tm;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < lne[i].size();j++){
            for(int k = 0;k < stn[lne[i][j]].size();k++){
                if(stn[lne[i][j]][k] == i){
                    continue;
                }
                chng[i].push_back(stn[lne[i][j]][k]);
                if(ch[i][stn[lne[i][j]][k]] == 0){
                    ch[i][stn[lne[i][j]][k]] = 1e9;
                }
                ch[i][stn[lne[i][j]][k]] = min(ch[i][stn[lne[i][j]][k]],fnd[lne[i][j]][i] + fnd[lne[i][j]][stn[lne[i][j]][k]]);
            }
        }
    }
    while(q--){
        int s,t;
        cin >> s >> t;
        int mn = 1e9;
        for(int i = 0;i < stn[s].size();i++){
            for(int j = 0;j < stn[t].size();j++){
                mn = min(mn,bfs(stn[s][i],stn[t][j],s,t));
            }
        }
        cout << mn + et[s] + et[t] << endl;
    }
    return 0;
}
