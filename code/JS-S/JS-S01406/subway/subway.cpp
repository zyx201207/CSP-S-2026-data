#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
int c,n,m,d,q;
long long w[500005];
long long dis[505][505];
vector<pair<int,long long> > lines[500005];

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=inf;
        }
         dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto a:lines[i]){
            for(auto b:lines[i]){
                dis[a.first][b.first]=min(dis[a.first][b.first],a.second+b.second);
            }
        }
    }
}

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
}

long long query(int x,int y){
    long long ans=LONG_LONG_MAX;
    for(auto i:lines[x]){
        for(auto j:lines[y]){
            ans=min(dis[i.first][j.first]+i.second+j.second,ans);
        }
    }
    return ans;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }

    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        while(k--){
            int a;
            long long t;
            cin >> a >> t;
            lines[a].push_back({i,t});
        }
    }

    init();
    floyd();

    while(q--){
        int x,y;
        cin >> x >> y;
        cout << w[x]+w[y]+query(x,y) << '\n';
    }
    return 0;
}
