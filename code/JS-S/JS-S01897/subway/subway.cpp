#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int maxm = 1010;
const int inf = 0x7fffffff;
int dp[maxm][maxm],w[maxm],k[maxn],c,n,m,d,q;
vector<int> e[maxm],a,t;

int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c == 21 || c == 22){
        int flg[maxm],tc[maxm];
        for(int i = 1;i<=m;i++)
            cin>>w[i];
        for(int i = 1;i<=n;i++){
            cin>>k[i];
            for(int j = 1;j<=k[i];j++){
                int aj,tj;
                cin>>aj>>tj;
                flg[aj] = i;
                tc[aj] = tj;
            }

        }
        while(q--){
            int x,y;
            cin>>x>>y;
            if(flg[x] == flg[y])
                cout<<w[x]+w[y]+t[x]+t[y]<<"\n";
        }
    }
    else{
    memset(dp,0x3f,sizeof(dp));
    for(int i = 1;i<=m;i++)
        cin>>w[i];
    for(int i = 1;i<=n;i++){
        a.clear(); t.clear();
        cin>>k[i];
        for(int j = 1;j<=k[i];j++){
            int aj,tj;
            cin>>aj>>tj;
            a.push_back(aj);
            t.push_back(tj);
        }
        for(int i = 1;i<=k[i];i++)
            for(int j = 1;j<=k[i];j++){
                int u = a[i], v = a[j];
                if(u == v){
                    dp[u][v] = 0;
                    //cout<<0<<"\n";
                }
                else{
                    dp[u][v] = min(dp[u][v],t[i]+t[j]);
                    //cout<<u<<" "<<v<<" "<<t[i]+t[j]<<"\n";
                }
            }
    }
    for(int i = 1;i<=m;i++)
        for(int k = 1;k<=m;k++)
            for(int j = 1;j<=m;j++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+dp[x][y]+w[y]<<"\n";
    }
    //for(int i = 1;i<=m;i++)
        //for(int j = 1;j<=m;j++)
            //cout<<dp[i][j]<<" \n"[j == m];
    }
    
    return 0;
}