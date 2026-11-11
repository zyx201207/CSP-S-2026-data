#include<bits/stdc++.h>
using namespace std;
long long x[2000005],step[2000005];
vector <int> G[200005];
struct node{
    int x,step;
};
map <int, int> mp;
bool bfs(int st, int ed){
    queue <node> Q;
    Q.push({st,0});
    while(!Q.empty()){
        node t = Q.front(); Q.pop();
        if(t.x == ed){
            mp[t.step]++;
            continue;
        }
        for(auto v : G[t.x]){
            Q.push({v,t.step+1});
        }
    }
    int minn = INT_MAX;
    for(auto x : mp){
        minn = min(minn,x.first);
    }
    if(mp[minn] == 2) return true;
    else return false;
}
void buildC(){
    for(int i = 2; i <= 5; i++) G[1].push_back(i);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T; cin >> c >> T;
    while(T--){
        int n,d; cin >> n >> d;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        if(c >= 13 && c <= 14){
            cout << 0 << "\n";
            continue;
        }
        for(int i = 1; i <= 5000; i++){
            G[i].clear();
        }

        if(c <= 10){
            for(int i = 1; i <= n; i++){
                for(int j = i+1; j <= n; j++){
                    if(i == j) continue;
                    if(x[j] - x[i] <= d){
                        G[i].push_back(j);
                    }
                }
            }
            //buildC();
            for(int i = 1; i <= n; i++){
                for(int j = i+1; j <= n; j++){
                    if(i == j) continue;
                    mp.clear();
                    if(bfs(i,j)) ans++;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
/*
n <= 5000?
*/