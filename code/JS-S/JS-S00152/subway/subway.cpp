#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long e[505][505],w[500010];
vector<long long>e1[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(e,0x3f,sizeof(e));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1,k;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;++j){
            int x,y;
            scanf("%d%d",&x,&y);
            e1[x].push_back(i);
            e1[x].push_back(y);
        }
    }
    for(int r=1;r<=m;++r){
        int sz=e1[r].size();
        for(int i=0;i<sz;i+=2){
            for(int j=0;j<sz;j+=2){
                if(i==j)continue;
                int x=e1[r][i],y=e1[r][j];
                e[x][y]=e[y][x]=min(e[x][y],e1[r][i+1]+e1[r][j+1]);
            }
        }
    }
    for(int i=1;i<=n;++i)e[i][i]=0;
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                e[i][j]=e[j][i]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    while(q--){
        int s,t;
        long long an=1e18;
        scanf("%d%d",&s,&t);
        int sz1=e1[s].size(),sz2=e1[t].size();
        for(int i=0;i<sz1;i+=2){
            for(int j=0;j<sz2;j+=2){
                int x=e1[s][i],y=e1[t][j];
                an=min(an,e1[s][i+1]+e1[t][j+1]+e[x][y]);
            }
        }
        cout<<an+w[s]+w[t]<<"\n";
    }
    return 0;
}
