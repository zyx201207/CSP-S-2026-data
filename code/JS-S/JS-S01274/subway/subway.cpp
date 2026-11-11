#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,n,m,d,q;

int k,s,w;
int a[500005];
int x,y;

struct node{
    int pi,t;
};

vector <node> p[500005];

ll dis[505][505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d%d",&s,&w);

            p[s].push_back({i,w});
        }
    }
    for(int i=1;i<=m;i++){
        int len=p[i].size();
        for(int j=0;j<len-1;j++){
            for(int k=j+1;k<len;k++)
                if(dis[p[i][j].pi][p[i][k].pi]>p[i][j].t+p[i][k].t)
                    dis[p[i][j].pi][p[i][k].pi]=dis[p[i][k].pi][p[i][j].pi]=p[i][j].t+p[i][k].t;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        ll ans=ll(1e18);
        for(int j=0;j<p[x].size();j++){
            for(int k=0;k<p[y].size();k++)
                ans=min(ans,p[x][j].t+p[y][k].t+dis[p[x][j].pi][p[y][k].pi]);
        }
        printf("%lld\n",ans+a[x]+a[y]);
    }
    return 0;
}
