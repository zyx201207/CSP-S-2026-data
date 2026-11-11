#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
long long e[505][505];
int inf=INT_MAX;
long long INF=inf;
vector<pair<int,int> > dtz[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    INF*=100000;
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d ",&w[i]);
    int ki,ai,ti;
    for(int i=1;i<=n;i++){
        scanf("%d ",&ki);
        for(int j=1;j<=ki;j++){
            scanf("%d %d ",&ai,&ti);
            dtz[ai].push_back({i,ti});
        }
    }
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            if(i!=j)e[i][j]=INF;
            else e[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<dtz[i].size();j++){
            for(int k=0;k<j;k++){
                long long tmp=dtz[i][j].second+dtz[i][k].second;
                e[dtz[i][j].first][dtz[i][k].first]=min(e[dtz[i][j].first][dtz[i][k].first],tmp);
                e[dtz[i][k].first][dtz[i][j].first]=e[dtz[i][j].first][dtz[i][k].first];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i!=j){
                    e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
                    e[j][i]=e[i][j];
                }
            }
        }
    }
    int x,y;
    while(q--){
        scanf("%d %d ",&x,&y);
        long long ans=INF;
        for(int i=0;i<dtz[x].size();i++){
            for(int j=0;j<dtz[y].size();j++){
                int xt=dtz[x][i].first;
                int yt=dtz[y][j].first;
                ans=min(ans,e[xt][yt]+dtz[x][i].second+dtz[y][j].second);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
