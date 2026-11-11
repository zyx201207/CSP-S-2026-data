#include<bits/stdc++.h>
using namespace std;
#define maxm 500010
#define maxq 100010
#define maxn 510
using ll=long long;
using p=pair<int,int>;
const ll INF=1e18;

int c,n,m,d,q;
ll w[maxm];
p qry[maxq];
ll dis[maxn][maxn];
vector<p>station_s1[310];

void solv1(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=INF;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll s1_a,s1_t;
            cin>>s1_a>>s1_t;
            for(p li:station_s1[s1_a]){
                int v=li.first,len=li.second;
                dis[i][v]=min(dis[i][v],s1_t+len);
                dis[v][i]=dis[i][v];
            }
            station_s1[s1_a].push_back({i,s1_t});
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
                dis[j][i]=dis[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ll ans=INF;
        for(p j:station_s1[x]){
            int u=j.first,u_t=j.second;
            for(p k:station_s1[y]){
                int v=k.first,v_t=k.second;
                ans=min(ans,u_t+v_t+dis[u][v]);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
}

ll s2_st[maxm][2];
int vis[maxm];
void solv2(){
    for(int i=1;i<=n;i++){
        s2_st[i][0]=s2_st[i][1]=INF;
    }
    ll c_fee=INF;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int s2_a;
            cin>>s2_a;
            vis[s2_a]|=(1<<(k-1));
            cin>>s2_st[s2_a][k-1];
            if(n==2)c_fee=min(s2_st[s2_a][0]+s2_st[s2_a][1],c_fee);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ll ans=INF;
        ans=min(ans,s2_st[x][1]+s2_st[y][1]);
        ans=min(ans,s2_st[x][0]+s2_st[y][0]);
        ans=min(ans,s2_st[x][1]+s2_st[y][0]+c_fee);
        ans=min(ans,s2_st[x][0]+s2_st[y][1]+c_fee);
        cout<<ans+w[x]+w[y]<<endl;
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    if(c<=11){
        solv1();
        return 0;
    }
    if(20<=c&&c<=21){
        solv2();
        return 0;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
