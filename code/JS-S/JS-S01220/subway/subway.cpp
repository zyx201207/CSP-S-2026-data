// O(md^2 + n^3 + qd^2), let me pass, plz~. CCF I love you!
#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int n,m,d,q,tmp[N][N];
vector<pair<int,int> >st[M];
long long dis[N][N],w[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%*d %d %d %d %d",&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",w+i);
    }
    for(int i=1,k,a,t;i<=n;i++){
        scanf("%d ",&k);
        for(int j=1;j<=k;j++){
            scanf("%d %d",&a,&t);
            st[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                tmp[i][j]=INT_MAX;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int id1=0;id1<st[i].size();id1++){
            for(int id2=id1+1;id2<st[i].size();id2++){
                tmp[st[i][id1].first][st[i][id2].first]=min(tmp[st[i][id1].first][st[i][id2].first],st[i][id1].second+st[i][id2].second);
                tmp[st[i][id2].first][st[i][id1].first]=tmp[st[i][id1].first][st[i][id2].first];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tmp[i][j]>2000000000){
                dis[i][j]=1e18;
            }else{
                dis[i][j]=tmp[i][j];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(int x,y;q;q--){
        scanf("%d %d",&x,&y);
        if(x==y){
            puts("0");
            continue;
        }
        long long ans=1e18;
        for(int i=0;i<st[x].size();i++){
            for(int j=0;j<st[y].size();j++){
                long long a=dis[st[x][i].first][st[y][j].first];
                long long b=st[x][i].second;
                long long c=st[y][j].second;
                //cerr<<a<<" "<<b<<" "<<c<<endl;
                ans=min(ans,a+b+c);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}