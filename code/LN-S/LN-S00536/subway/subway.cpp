#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=610;
ll dist[N][N];
int tot;
int c,n,m,d,q;
ll w[N];
int a,t;
void floyd() {
    for(int k=1;k<=tot;k++)
        for(int i=1;i<=tot;i++)
            for(int j=1;j<=tot;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dist,0x3f,sizeof dist);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    tot=m;
    for(int i=1;i<=n;i++) {
        int k;
        scanf("%d",&k);
        int last=-1;
        while(k--) {
            scanf("%d%d",&a,&t);
            tot++;
            dist[a][tot]=dist[tot][a]=t;
            if(last!=-1)
                dist[tot][last]=dist[last][tot]=0;
            last=tot;
        }
    }

    for(int i=1;i<=tot;i++) dist[i][i]=0;
    floyd();
    while(q--) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",dist[x][y]+w[x]+w[y]);
    }
    return 0;
}