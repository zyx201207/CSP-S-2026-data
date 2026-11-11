#include<bits/stdc++.h>
using namespace std;
int c,T,n,d;
vector<pair<int,int>> ve1[200005],ve2[200005];
bool vis1[200005],vis2[200005];int dis1[200005],dis2[200005];
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            int u,v;
            ve[u]
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q1;
        dis1[1]=0;q1.push({0,1});
        while(!q1.empty()){
            int d=q1.top().first;
            int u=q1.top().second;
            if(vis1[u]==1)continue;
            vis1[u]=1;
            for(auto i:ve1[u]){
                int v=i.first;
                int w=i.second;
                if(dis1[v]>d+w){
                    dis1[v]=d+w;
                    q1.push({dis1[v],v});
                }
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q2;
        dis[1]=0;q2.push({0,1});
        while(!q2.empty()){
            int d=q2.top().first;
            int u=q2.top().second;
            if(vis2[u]==1)continue;
            vis2[u]=1;
            for(auto i:ve2[u]){
                int v=i.first;
                int w=i.second;
                if(dis2[v]>d+w){
                    dis2[v]=d+w;
                    q2.push({dis[v],v});
                }
            }
        }
    }
    
    return 0;
    fclose(stdin);
    fclose(stdout);
}
