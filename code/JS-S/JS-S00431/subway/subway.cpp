#include<bits/stdc++.h>
#define ii pair<int,long long int>
using namespace std;
typedef long long ll;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    int extra[500050]={};
    for(int i=1;i<=m;i++){
        cin>>extra[i];
    }
    vector< vector<ii> > star(500500);
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int tot;
            ii sta;cin>>tot>>sta.second;
            sta.first=i;
            star[tot].push_back(sta);
        }
    }
    ll dp[505][505]={};//floyd
    for(int i=0;i<505;i++){
        for(int j=0;j<505;j++){
            dp[i][j]=1e17;
        }
        dp[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int k=star[i].size();
        for(int b=0;b<k;b++){
            for(int e=b+1;e<k;e++){
                dp[star[i][b].first][star[i][e].first]=min(dp[star[i][b].first][star[i][e].first],star[i][b].second+star[i][e].second);
                dp[star[i][e].first][star[i][b].first]=min(dp[star[i][e].first][star[i][b].first],star[i][e].second+star[i][b].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                dp[j][i]=dp[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        ll ans=extra[x]+extra[y],minini=1e17;
        for(int i=0;i<star[x].size();i++){
            for(int j=0;j<star[y].size();j++){
                minini=min((star[x][i].second+star[y][j].second+dp[star[x][i].first][star[y][j].first]),minini);
            }
        }
        cout<<ans+minini<<endl;
    }
}
