#include <bits/stdc++.h>
#define int long long
const int inf=1e14;
using namespace std;
int c,t,a[22222],n,d,dis[2002][2002],num[2002][2002],ans;
struct node{
    int x,step;
};
vector<int>g[2222];
queue<node>q;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
                else
                    break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=inf;
            }
            for(int j=1;j<=n;j++){
                num[i][j]=0;
            }
            while(!q.empty()){
                q.pop();
            }
            q.push({i,0});
            dis[i][i]=0;
            while(!q.empty()){
                int x=q.front().x,step=q.front().step;
                q.pop();
                for(int j=0;j<g[x].size();j++){
                    int nx=g[x][j];
                    if(dis[i][nx]>step+1){
                        dis[i][nx]=step+1;
                        q.push({nx,dis[i][nx]});
                    }
                }
            }
            while(!q.empty()){
                q.pop();
            }
            q.push({i,0});
            while(!q.empty()){
                int x=q.front().x,step=q.front().step;
                q.pop();
                if(dis[i][x]==step)
                    num[i][x]++;
                if(dis[i][x]<step)
                    continue;
                for(int j=0;j<g[x].size();j++){
                    int nx=g[x][j];
                    q.push({nx,step+1});
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(num[i][j]==2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
}
