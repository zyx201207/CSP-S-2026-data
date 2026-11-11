
#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[20005],dp[20005][20005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        pair<int,int> t[k+1];
        for(int j=1;j<=k;j++){
            cin>>t[j].first>>t[j].second;
        }
        for(int j=1;j<=k;j++){
            for(int l=j+1;l<=k;l++){
                dp[t[j].first][t[l].first]=((dp[t[j].first][t[l].first]==0)?(t[j].second+t[l].second):(min(dp[t[j].first][t[l].first],t[j].second+t[l].second)));
                dp[t[l].first][t[j].first]=dp[t[j].first][t[l].first];
                for(int z=1;z<=m&&z!=t[j].first&&z!=t[l].first;z++){
                    if(dp[z][t[l].first]!=0){
                        dp[z][t[l].first]=min(dp[z][t[l].first],dp[z][t[j].first]+dp[t[j].first][t[l].first]);
                        dp[t[l].first][z]=dp[z][t[l].first];
                    }
                    else if(dp[z][t[j].first]!=0){
                        dp[z][t[l].first]=dp[z][t[j].first]+dp[t[j].first][t[l].first];
                        dp[t[l].first][z]=dp[z][t[l].first];
                    }
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int xr,yr;
        cin>>xr>>yr;
        cout<<dp[xr][yr]+w[xr]+w[yr]<<'\n';
    }


    return 0;
}

