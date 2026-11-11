#include<bits/stdc++.h>
using namespace std;

const int maxm=5e5+10;
const int maxn=5e2+10;
vector<pair<int,int> > v[maxm];
long long dis[maxn][maxn];
int w[maxm];
int c,n,m,d,q;
void solve(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    int p,a,b;
    for(int i=1;i<=n;i++){
        scanf("%d",&p);
        for(int j=0;j<p;j++){
            scanf("%d%d",&a,&b);
            v[a].push_back(make_pair(i,b));
        }
    }
    for(int i=1;i<=m;i++){
        for(int l=0;l<v[i].size();l++){
            for(int r=l+1;r<v[i].size();r++){
                int posl=v[i][l].first,posr=v[i][r].first;
                dis[posl][posr]=dis[posr][posl]=min(dis[posl][posr],(long long)v[i][l].second+v[i][r].second);
            }
        }
    }
    solve();
    for(int i=1;i<=q;i++){
        scanf("%d%d",&a,&b);
        if(a==b){
            printf("0\n");
            continue;
        }
        long long sum=w[a]+w[b],mn=0x3f3f3f3f3f3f3f3f;
        for(pair<int,int> l:v[a]){
            for(pair<int,int> r:v[b]){
                mn=min(mn,dis[l.first][r.first]+l.second+r.second);
                // fprintf(stderr,"%d %d %d %d\n",l.first,r.first,l.second,r.second);
            }
        }
        // fprintf(stderr,"%d qwq\n",sum);
        printf("%lld\n",sum+mn);
    }
    return 0;
}