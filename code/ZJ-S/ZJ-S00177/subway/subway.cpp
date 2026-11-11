#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
#define PII pair<int,int>
using namespace std;
int c,n,m,d,q,t[500005],tot,dis[505][505];
vector<PII >s[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q;tot=m;
    for(int i=1;i<=m;i++) cin>>t[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        int num;cin>>num;
        for(int j=1;j<=num;j++){
            int x,y;cin>>x>>y;
            s[x].push_back({i,y});   
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<s[i].size();j++){
            for(int k=0;k<s[i].size();k++){
                if(j!=k){
                    int x=s[i][j].first,y=s[i][k].first;
                    int val1=s[i][j].second,val2=s[i][k].second;
                    dis[x][y]=min(dis[x][y],val1+val2);
                    dis[y][x]=min(dis[y][x],val1+val2);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dis[i][k]==1e18) continue;
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        int ans=1e18;
        for(int j=0;j<s[x].size();j++){
            for(int k=0;k<s[y].size();k++){
                int u=s[x][j].first,v=s[y][k].first;
                int val1=s[x][j].second,val2=s[y][k].second;
                // cout<<u<<' '<<v<<' '<<dis[u][v]<<'\n';
                ans=min(ans,dis[u][v]+val1+val2);
            }
        }
        cout<<ans+t[x]+t[y]<<'\n';
    }
    return 0;
}