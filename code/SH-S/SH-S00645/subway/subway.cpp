#include<bits/stdc++.h>
using namespace std;
int tozt[500005];
int tgt,begt;

struct PR{
    int first;
    int second;
};
vector<PR> linemap[500005]; //train 1's 2 station is the [] station 
int line[505][50005];
int linesz[505];
int linemp[505][50005];

bool vstd[500005];
void dfs(int curt, int cur, int costed){
    if(vstd[cur] or cur == 0) return;
    vstd[cur] = true;
    //cout << " Entered " << cur << " from train " << curt << " current costed " << costed << endl;
    if(cur == tgt){
        cout << begt + costed + line[curt][cur] + tozt[cur] << endl;
        return;
    }

    for(auto x:linemap[cur]){
        int train = x.first;
        int stationcnt = x.second;
        //cout << "able to go to " << x.second << "\'s next station: " << linemp[train][stationcnt + 1] <<" train num = " << x.first << " costed = " << costed << endl;
        if(stationcnt != linesz[train]) {
            if(train == curt) dfs(curt, linemp[train][stationcnt + 1], costed);
            else {
                dfs(train, linemp[train][stationcnt + 1], costed + line[cur][stationcnt] + line[train][stationcnt]);
            }
        }
        if(stationcnt != 1) {
            if(train == curt) dfs(curt, linemp[train][stationcnt - 1], costed);
            else {
                dfs(train, linemp[train][stationcnt - 1], costed + line[cur][stationcnt] + line[train][stationcnt]);
            }
        }
    }
    vstd[cur] = false;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int C, n, m, d, q; cin >> C >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> tozt[i];
    }
    for(int i = 1; i<= n; i++){
        int stops; cin >> stops;
        linesz[i] = stops;
        for(int j = 1; j <= stops; j++){
            int st, tw; cin >> st >> tw;
            linemap[st].push_back({i, j});
            line[i][st] = tw;
            linemp[i][j] = st;
        }
    }
    while(q--){
        int beg; cin >> beg >> tgt;
        for(auto x:linemap[beg]) {
            begt = line[x.first][x.second];
            dfs(x.first, beg, 0);
        }
        tgt = 0;
        begt = 0;
    }
    return 0;
}
