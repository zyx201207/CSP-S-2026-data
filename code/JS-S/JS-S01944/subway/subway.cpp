#include<bits/stdc++.h>
using namespace std;
long long a[500005],dis[1005][1005],c[505][20005],ans,l[20005];
int g,n,m,d,h,b[505][20005],k[505],x,y;
struct node{
    int dv;
    long long val;
    bool operator <(const node p)const{
        return val>p.val;
    }
};
vector<node> v[20005];
priority_queue<node> e;
queue<node> q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>g>>n>>m>>d>>h;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>b[i][j]>>c[i][j];
    }
    if(g<=11){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                for(int j2=1;j2<=k[i];j2++){
                    if(j==j2)continue;
                    v[b[i][j]].push_back({b[i][j2],c[i][j]+c[i][j2]});
                }
            }
        }
        memset(dis,0x3f,sizeof(dis));
        for(int j=1;j<=m;j++){
            dis[j][j]=0ll;
            e.push({j,0ll});
            while(!e.empty()){
                node t=e.top();
                e.pop();
                for(auto i:v[t.dv]){
                    if(dis[j][i.dv]>dis[j][t.dv]+i.val){
                        dis[j][i.dv]=dis[j][t.dv]+i.val;
                        e.push({i.dv,dis[j][i.dv]});
                    }
                }
            }
        }
        while(h--){
            cin>>x>>y;
            cout<<dis[x][y]+a[x]+a[y]<<'\n';
        }
    }else if(g<=15){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                for(int j2=1;j2<=k[i];j2++){
                    if(j==j2)continue;
                    v[b[i][j]].push_back({b[i][j2],1});
                }
            }
        }
        while(h--){
            cin>>x>>y;
            for(int i=1;i<=m;i++)l[i]=-1ll;
            l[x]=0ll;
            ans=-1;
            while(!q.empty())q.pop();
            q.push({x,0ll});
            while(!q.empty()){
                node t=q.front();
                q.pop();
                for(auto i:v[t.dv]){
                    if(l[i.dv]!=-1ll)continue;
                    if(i.dv==y){
                            ans=t.val+1ll;
                            break;
                    }
                    q.push({i.dv,l[t.dv]+1ll});
                }
                if(ans!=-1)break;
            }
            cout<<ans*2ll*c[1][1]<<'\n';
        }
    }
    return 0;
}
