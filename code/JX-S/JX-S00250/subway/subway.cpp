#include<bits/stdc++.h>
using namespace std;

struct node{
    int s,t;
};

const int N = 5e5 + 6;
int tm[N];
vector<node> arr[506];

vector<int> mp[506];
bool vis[506];

queue<node> q;

int bfs(int x,int y){
    memset(vis,false,sizeof(vis));

    q.push({x,0});

    while(!q.empty()){
        node T = q.front();
        q.pop();

        if(T.s == y) return T.t;

        for(int f : mp[T.s]){
            if(vis[f]) continue;
            q.push({f,T.t + tm[f] + arr[T].t});
            vis[f] = true;
        }
    }

    return -1;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= m;i ++) cin >> tm[i];

    int k;
    for(int i = 1;i <= n;i ++){
        cin >> k;
        for(int j = 1;j <= k;j ++){
            int S,T;
            cin >> S >> T;
            arr[N].push_back({S,T});
        }

        for(node l : arr[i]){
            for(node r : arr[i]){
                if(l.s == r.s) continue;
                mp[l.s].push_back(r.s);
                mp[r.s].push_back(l.s);
            }
        }

    }

    while(q --){
        int x,y;
        cin >> x >> y;

        cout << bfs(x,y) << "\n";
    }

    return 0;
}