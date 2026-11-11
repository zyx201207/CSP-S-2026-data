#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int siz[505];
struct line{
    int a,t;
}l[505][500005];
vector<int>linec[500005];//line number
int dp[500005];
void dfs(int u){
    for(int i:linec[u]){//i is the line number
        for(int j=1;j<=siz[i];j++){//j is the station
            dp[j]=min(dp[j],dp[u]+l[i][u].t+l[i][j].t);
            dfs(j);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>siz[i];
        for(int j=1;j<=siz[i];j++){
            cin>>l[i][j].a>>l[i][j].t;
            linec[l[i][j].a].push_back(i);
        }

    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y];
        dfs(x);
        ans+=dp[y];
        cout<<ans<<'\n';
    }
    return 0;
}
//what is the Segmentation fault???
//what can i say?
//i cannot say anything.
//what can i do?
//i cannot do anything.
//its too tough.
//so
//see you next time,
//if i can.
