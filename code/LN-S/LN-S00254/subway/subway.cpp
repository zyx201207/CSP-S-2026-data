#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=510;
const int MAXM=5e5+10;
int c,n,m,d,q,k;
int w[MAXM];
int a;
int t[MAXM][MAXN];
int last;
int num;
int x,y;
int total;
long long dep[MAXM];
vector< pair<int,int> > g[MAXM*MAXN];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        last=k;
        scanf("%d",&a);
        scanf("%d",&t[i][a]);
        for(int j=2;j<=k;j++){
            scanf("%d%d",&a,&t[i][a]);
            if(last!=a){
                g[n*(i-1)+last].push_back({n*(i-1)+a,0});
                g[n*(i-1)+a].push_back({n*(i-1)+last,0});
            }
            last=a;
            for(int z=1;z<i;z++){
                g[n*(i-1)+a].push_back({n*(i-1)+a,t[z][a]+t[i][a]});
            }
        }
    }
    while(q--){
        total=0;
        int m1=m;
        scanf("%d%d",&x,&y);
        total=total+w[x]+w[y];
        memset(dep,0x3f,sizeof(dep));
        dep[x]=0;
        while(m1){
            long long minn=1e18;
            int minm=-1;
            for(int i=1;i<=m;i++){
                if(dep[i]<minn){
                    minn=dep[i];
                    minm=i;
                }
            }
            int f=minm;
            for(int i=1;i<=n;i++){
                for(int j=0;j<g[n*(i-1)+f].size();j++){
                    dep[g[n*(i-1)+f][j].first]=min(dep[g[n*(i-1)+f][j].first],dep[n*(i-1)+f]+g[n*(i-1)+f][j].second);
                }
            }
            m1--;
        }
        printf("%lld\n",total+dep[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
