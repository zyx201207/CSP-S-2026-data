#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, b, s, ed;
int w[500100];
struct Edge{
    int to, va;
};
struct Node{
    int p, dis;
};
bool operator <(Node a, Node b){
    return a.dis > b.dis;
}
int dis[500100];
vector<Edge> e[500100];
priority_queue<Node> q;
void dij(){
    memset(dis, 0x3f, sizeof(dis));
    q.push((Node){s, 0});
    dis[s] = 0;
    while(!q.empty()){
        Node st = q.top();
        q.pop();
        if(st.dis > dis[st.p]) continue;
        for(int i = 0;i < e[st.p].size();i++){
            int new_dis = st.dis + e[st.p][i].va;
            if(new_dis < dis[e[st.p][i].to]){
                dis[e[st.p][i].to] = new_dis;
                q.push((Node){e[st.p][i].to, new_dis});
            }
        }
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> b;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        for(int j = 2;j <= x;j++){
            int a, t;
            cin >> a >> t;
            e[i].push_back((Edge){a, t + tmp2});
        }
    }
    while(b--){
        cin >> s >> ed;
        dij();
        cout << dis[ed] + w[s] + w[ed] << endl;
    }
    return 0;
}
