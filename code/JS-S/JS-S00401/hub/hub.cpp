#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dis[100005],dis1[100005];
vector<int>g[100005];
        queue<int>q;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=0;i<=100000;i++)dis[i]=0x3f3f3f3f,dis1[i]=0x3f3f3f3f,g[i].clear();
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dis[1]=0;
        q.push(1);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<g[x].size();i++){
                int to=g[x][i];
                if(dis[to]>dis[x]+1){
                    dis[to]=dis[x]+1;
                    q.push(to);
                }
            }
        }
        int mxp,mx=0;
        for(int i=1;i<=n;i++){
            if(dis[i]>mx){
                mx=dis[i];
                mxp=i;
            }
        }
        dis1[mxp]=0;
        q.push(mxp);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<g[x].size();i++){
                int to=g[x][i];
                if(dis1[to]>dis1[x]+1){
                    dis1[to]=dis1[x]+1;
                    q.push(to);
                }
            }
        }
        mx=0;
        for(int i=1;i<=n;i++)mx=mx>dis1[i]?mx:dis1[i];
        cout<<(mx+1)/2<<'\n';
    }
    return 0;
}
