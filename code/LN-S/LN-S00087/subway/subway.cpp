#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//unused variables
int c;//test pt


int w[500005];

struct __line {
    int id;
    int t;//time required
};

vector<__line> scl[500005];//station connected lines

struct __station {
    int t;//time required
    int a;//id
};

//connected stations.
vector<__station> line[505];
int vis[505];//record visit time

int n,m,d,q;

int bfs(int x,int y) {

    struct __node {
        int t;//time spent
        int l;//current line
    };

    queue<__node> q;
    memset(vis,0x3f,sizeof(vis));
    for (__line& startline : scl[x]) {
        q.push({startline.t,startline.id});
        vis[startline.id] = startline.t;
    }

    while (!q.empty()) {
        int cur_time = q.front().t;
        int cur_line = q.front().l;
        q.pop();
        for (__station& s : line[cur_line]) {
            for (__line& next_line : scl[s.a]) {
                int new_time = cur_time + s.t + next_line.t;
                if (new_time < vis[next_line.id]) {
                    vis[next_line.id] = new_time;
                    q.push({new_time,next_line.id});
                }
            }
        }
    }
    int minn = INT_MAX;
    for (__line& stopline : scl[y]) minn = min(minn,vis[stopline.id]+stopline.t);
    return minn;
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++) scanf("%d",w+i);
    for (int i=1;i<=n;i++) {//i : line id
        int k;
        scanf("%d",&k);
        for (int j=1;j<=k;j++) {//j : line connected stations (a&t)
            __station station;
            scanf("%d%d",&station.a,&station.t);
            scl[station.a].push_back({i,station.t});
            line[i].push_back(station);
        }
    }
    for (int r=1;r<=q;r++) {
        int x,y;
        cin >> x >> y;
        cout << bfs(x,y)+w[x]+w[y] << endl;
    }
    return 0;
}
