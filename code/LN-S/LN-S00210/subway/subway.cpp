#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N=800;
const int M=5e5+10;

long long g[N][N]; // subways graph
vector<pair<int,int>> points[M]; // site -> subway line

int c,n,m,dd,q;
int wv[M];

int line_2_site[N][M];

long long d[N][N];

void floyd(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            d[i][j]=g[i][j];
        }
        d[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            g[i][j]=0x3f3f3f3f3f3f3f3f;
        }
    }
    cin >> c >> n >> m >> dd >> q;
    for(int i=1;i<=m;i++){
        cin >> wv[i];
    }
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        for(int j=1;j<=tmp;j++){
            int tmp2,tmp3;
            cin >> tmp2 >> tmp3;
            points[tmp2].push_back({i,tmp3});
            // line_2_site[i][tmp2] = tmp3;
            // cout << "Subway: site" << tmp2 << " into line" << i << " cost " << tmp3 << endl;
        }
    }
    // transform points 2 edges
    for(int k=1;k<=m;k++){
        for(pair<int,int> tmp1:points[k]){
            int i=tmp1.first; // up from i
            for(pair<int,int> tmp2:points[k]){
                int j = tmp2.first; // down to j
                if(i==j){
                    continue;
                }
                long long costs = tmp1.second + tmp2.second;
                g[i][j]=min(g[i][j],costs);
                // cout << "Connected: site" << k << " line" << i << " <=> line" << j << " cost " << costs << endl;
            }
        }
    }
    // calc
    floyd();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // ask
    for(int k=1;k<=q;k++){
        int st,ed;
        cin >> st >> ed;
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(auto tmp1:points[st]){
            int u=tmp1.first;
            for(auto tmp2:points[ed]){
                int v=tmp2.first;
                // cout << "Check: "<< u << "<=>" << v << " cost line:" << d[u][v] << " in: " << tmp1.second + wv[st] << " out: "<< tmp2.second + wv[ed] << endl;
                ans=min(ans,d[u][v] + tmp1.second + wv[st] + tmp2.second + wv[ed]);
            }
        }
        cout << ans << '\n';
    }
}
