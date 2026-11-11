#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e18;
long long ktt[1005];
long long way[1005][1005];
pair<long long,long long>road[1005];
long long c,n,m,d,q;
long long dis[1005];
long long isv[100005];
long long ans[1005][1005];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>Q;//val,idx
void Dijkstra(int st){
    memset(isv,0,sizeof(isv));
    //cout<<"----------->"<<st<<endl;
    for(int i=1;i<=m;i++){
        dis[i]=MAXN;
    }
    dis[st]=0;
    Q.push({0,st});
    while(!Q.empty( )){
        pair<long long,long long>t=Q.top( );
        Q.pop( );
        long long tv=t.first;
        long long tw=t.second;
        //cout<<tv<<' '<<tw<<endl;
        if(isv[tw]==1){
            continue;
        }
        isv[tw]=1;
        for(int i=1;i<=m;i++){
            int to=i;
            long long val=way[tw][i];
            long long adis=dis[tw]+val;
            //cout<<"->"<<to<<' '<<val<<' '<<adis<<' '<<dis[to]<<' '<<isv[to]<<' '<<endl;
            if(adis<dis[to]&&isv[to]==0&&val!=MAXN){
                //cout<<"Y"<<endl;
                dis[to]=adis;
                Q.push({dis[to],to});
            }
        }
    }
    //cout<<"`````````````";
    for(int i=1;i<=m;i++){
        //cout<<dis[i]<<' ';
        ans[st][i]=dis[i];
    }
    //cout<<endl;
    return;
}
int main( ){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",ktt+i);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            way[i][j]=2e9;
        }
        way[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        for(int j=1;j<=t;j++){
            scanf("%lld%lld",&road[j].first,&road[j].second);
        }
        for(int j=1;j<=t;j++){
            for(int k=1;k<=t;k++){
                way[road[j].first][road[k].first]=min(way[road[j].first][road[k].first],road[j].second+road[k].second);
            }
        }
    }
    for(int i=1;i<=m;i++){
        Dijkstra(i);
    }
    for(int i=1;i<=q;i++){
        long long from,to;
        scanf("%lld%lld",&from,&to);
        printf("%lld\n",ktt[from]+ktt[to]+ans[from][to]);
    }
    return 0;
}
//36