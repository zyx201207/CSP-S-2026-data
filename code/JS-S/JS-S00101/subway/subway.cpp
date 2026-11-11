#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN=510,MAXM=5e5+10,MAXD=25,INF=INT_MAX;
int c,n,m,d,q,w[MAXN],t[MAXN][MAXM],k[MAXN],dis[MAXN][MAXN];
struct STATION{
    int cnt,line[MAXD];
    void add(const int x){
        line[++cnt]=x;
        return;
    }
}station[MAXM];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //init
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int to;
        for(int j=1;j<=k[i];j++){
            cin>>to;
            cin>>t[i][to];
            station[to].add(i);    
        }
    }
    //calc distance
    for(int l_in=1;l_in<=n;l_in++){
        for(int l_ot=1;l_ot<=n;l_ot++){
            dis[l_in][l_ot]=INF;
        }
        dis[l_in][l_in]=0;
    }
    
    for(int l_in=1;l_in<=n;l_in++){
        for(int l_ot=l_in+1;l_ot<=n;l_ot++){
            for(int i=1;i<=m;i++){
                dis[l_in][l_ot]=min(dis[l_in][l_ot],t[l_in][i]+t[l_ot][i]);
                dis[l_ot][l_in]=min(dis[l_ot][l_in],t[l_in][i]+t[l_ot][i]);
            }
        }
    }
    //dp
    for(int i=1;i<=n;i++){
        for(int l_in=1;l_in<=n;l_in++){
            for(int l_ot=l_in+1;l_ot<=n;l_ot++){
                dis[l_in][l_ot]=min(dis[l_in][l_ot],dis[l_in][i]+dis[l_ot][i]);
            }
        }
    }
    //output
    int x,y,ans=INF;
    while(q--){
        cin>>x>>y;
        for(int i=1;i<=station[x].cnt;i++){
            for(int j=1;j<=station[y].cnt;j++){
                int tmp=dis[station[x].line[i]][station[y].line[j]];
                ans=min(ans,t[station[x].line[i]][x]+t[station[y].line[j]][y]+dis[station[x].line[i]][station[y].line[j]]);
            }
        }
        ans+=(w[x]+w[y]);
        cout<<ans<<endl;
    }
    return 0;
}