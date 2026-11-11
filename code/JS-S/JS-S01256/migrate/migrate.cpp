#include <bits/stdc++.h>
using namespace std;
long long n,d;
long long x[2000005];
struct tDot{
    long long x;long long t;
};
vector<long long> g[20000005];
int dis[500][500];
long long bfs(long long st,long long ed){
    if(dis[st][ed]==0x3f3f3f3f)return 0;
    bool b[n+1];
    memset(b,0,sizeof(b));
    queue<tDot> q;
    b[st]=1;
    q.push({st,0});
    long long cnt=0;
    while(!q.empty()){
        tDot D=q.front();
        q.pop();
        long long x=D.x,t=D.t;
        b[x]=1;
        if(x==ed && t==dis[st][ed]){
            cnt++;
            continue;
        }
        if(cnt>2){
            return 0;
        }
        if(t>dis[st][ed])continue;
        for(int v:g[x]){
            if(!b[v]){
                q.push({v,t+1});
            }
        }
    }
    if(cnt==2)
    return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){

        cin>>n>>d;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(abs(x[i]-x[j])<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                    dis[i][j]=dis[j][i]=1;
                }
                else{
                    break;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long t=bfs(i,j);
                ans+=t;
           //     if(t)cout<<i<<" "<<j<
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
