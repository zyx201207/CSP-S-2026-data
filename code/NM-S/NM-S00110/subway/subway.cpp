#include <bits/stdc++.h>
using namespace std;
const int maxm=5e5+5;
int n,m,q,d,w[maxm];
vector<int> point[maxm];
int t[505][maxm];
long long dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin>>_>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a;j<=k;j++){
            cin>>a>>t[i][a];
            point[a].push_back(i);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int u:point[i])
            for(int v:point[i])
                if(u!=v)
                    dis[u][v]=dis[v][u]=min(dis[u][v],1ll*t[u][i]+t[v][i]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
    while(q--){
        long long ans=0x3f3f3f3f3f3f3f3fll;
        int s,e;
        cin>>s>>e;
        for(int u:point[s])
            for(int v:point[e])
                ans=min(ans,w[s]+w[e]+t[u][s]+t[v][e]+dis[u][v]);
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
