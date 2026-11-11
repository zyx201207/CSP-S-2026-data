#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PLL;
const int N=5e5+50;
int c,n,m,d,qcnt;
int TT[N];
int dist[505][505];
bool st[505];
int ne[1000005],e[1000005],w[1000005],h[1000005],idx;
vector<PLL> v[N];
vector<int> v1[505];

map<PLL,int> idd;
map<PLL,bool> iff;

void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dij(int s){
    memset(dist[s],0x3f,sizeof(dist[s]));
    memset(st,0,sizeof st);
    dist[s][s]=0;
    priority_queue<PLL,vector<PLL>,greater<PLL>> q;
    q.push({0,s});
    while(q.size()){
        PLL tp=q.top();
        q.pop();
        int des=tp.second,di=tp.first;
        if(st[des])continue;
        st[des]=1;
        for(int i=h[des];~i;i=ne[i]){
            int j=e[i];
            if(dist[s][j]>di+w[i]){
                dist[s][j]=di+w[i];
                q.push({dist[s][j],j});
            }
        }
    }
    return;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(h,-1,sizeof h);
    cin>>c>>n>>m>>d>>qcnt;

    for(int i=1;i<=m;i++)cin>>TT[i];
    if(c<=6){
        for(int i=1;i<=n;i++){
            int k,a,t;
            cin>>k;
            while(k--){
                cin>>a>>t;
                v[a].push_back({i,t});
            }
        }
        for(int i=1;i<=m;i++){
            int s=v[i].size();
            for(int j=0;j<s;j++){
                for(int k=j+1;k<s;k++){
                    int D=v[i][j].second+v[i][k].second;
                    add(v[i][j].first,v[i][k].first,D);
                    add(v[i][k].first,v[i][j].first,D);
                }
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            int k,a,t;
            cin>>k;
            while(k--){
                cin>>a>>t;
                v[a].push_back({i,t});
                v1[i].push_back(a);
                idd[{i,a}]=t;
                iff[{i,a}]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=0;k<v1[i].size();k++){
                    if(iff[{j,v1[i][k]}]){
                        int DDD=idd[{i,v1[i][k]}]+idd[{j,v1[i][k]}];
                        add(i,j,DDD);
                        add(j,i,DDD);
                    }
                }
            }
        }
    }

    

    for(int i=1;i<=n;i++)dij(i);
    while(qcnt--){
        int s,ed;
        cin>>s>>ed;
        int ans=1e14+5;
        int s1=v[s].size(),s2=v[ed].size();
        for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
            int DD=v[s][i].second+v[ed][j].second;
                ans=min(ans,dist[v[s][i].first][v[ed][j].first]+DD);
            }
        }
        ans=ans+TT[s]+TT[ed];
        printf("%lld\n",ans);
    }

    return 0;
}