#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
struct op{
    int st,go;
};
int c_,n,m,c__,r,w[500005],dp[505][505];
vector<op> g[505];
vector<op> t[500005];
int main(){
    //add
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    //delete

    cin >> c_ >> n >> m >> c__ >> r;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=inf;
        }
    }
    for(int i=1,k;i<=n;i++){
        cin >> k;
        for(int j=1,x,y;j<=k;j++){
            cin >> x >> y;
            t[x].push_back({i,y});
            g[i].push_back({x,y});
            for(int l=0;l<t[x].size()-1;l++){
                dp[i][t[x][l].st]=t[x][l].go+y;
                dp[t[x][l].st][i]=t[x][l].go+y;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=1,x,y;i<=r;i++){
            cin >> x >> y;
            int minv=0x3f3f3f3f;
            for(int j=0;j<t[x].size();j++){
            for(int k=0;k<t[y].size();k++){
                minv=min(minv,dp[t[x][j].st][t[y][k].st]+w[x]+w[y]+t[x][j].go+t[y][k].go);
            }
            }
            cout << minv << endl;
    }
    return 0;
}
