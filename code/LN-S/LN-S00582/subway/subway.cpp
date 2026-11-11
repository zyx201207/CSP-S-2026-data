#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
int w[550];
int a[550][500050],t[550][500050];
int k;

vector<pair<int,int> > e[3000];
map<int,int> mp;
ll dis[3000][3000];

void spfa(int x)
{
    bool f[1000];
    for (int i=1;i<=m+n;i++)
        f[i]=0;

    queue<int> qe;
    qe.push(x);
    f[x]=1;
    while(!qe.empty()){
        int u = qe.front();
        qe.pop();
        f[u]=0;
        for(auto m : e[u]){
            int r = m.first;
            int t = m.second;
            if (f[r]){
                continue;
            }
            if (dis[x][r] >= t+dis[x][u]){
                qe.push(r);
                f[r]=1;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++){
        cin >> w[i];
    }
    for (int i=1;i<=n;i++){
        cin >> k;
        for (int j=1;j<=k;j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    int x,y;


    for (int i=1;i<=m+n;i++){
        for (int j=1;j<=m+n;j++){
            dis[i][j] = LONG_LONG_MAX;
        }
    }
    for (int i=1;i<=m+n;i++){
        dis[i][i] = 0;
    }
    for (int i=1;i<=n;i++){
        mp.clear();
        for (int j=1;j<=k;j++){
            mp[a[i][j]] = INT_MAX;
        }
        for (int j=1;j<=k;j++){
            mp[a[i][j]] = min(mp[a[i][j]],mp[t[i][j]]);
        }
        for (auto it:mp){
            int xx=it.first,yy=it.second;
            e[xx].push_back(make_pair(xx+m,yy));
            e[xx+m].push_back(make_pair(xx,yy));
            dis[xx][xx+m]=yy;
            dis[xx+m][xx]=yy;
        }
    }
    for (int i=1;i<=q;i++){
        cin >> x >> y;
        if (dis[x][y]==LONG_LONG_MAX){
            spfa(x);
        }
        cout << dis[x][y]+w[x]+w[y] << endl;
    }
    return 0;
}
// subway
