#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k1[510],dis[5*100010+510],w[5*100010+510];
vector<pair<int,int>>k[5*100010+510];
void bfs(int x){
    memset(dis,-1,sizeof dis);
    priority_queue<pair<int,int>>q;
    q.push({0,x});
    while(!q.empty()){
        int q1=q.top().first,q2=q.top().second;
        q.pop();
        if(dis[q2]!=-1&&dis[q2]<q1)continue;
        //cout<<k[q2].size()<<endl;
        for(int i=0;i<k[q2].size();i++){
            int a=k[q2][i].first,b=k[q2][i].second;
            if(dis[a]>q1+b||dis[a]==-1){
                dis[a]=q1+b;
                q.push({dis[a],a});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k1[i];
        int x,y;
        for(int j=1;j<=k1[i];j++){
            cin>>x>>y;
            k[m+i].push_back({x,y});
            k[x].push_back({m+i,y});
            //cout<<k[1].size()<<endl;
        }
    }
    int x1=0;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x1!=x)bfs(x);
        cout<<dis[y]+w[x]+w[y]<<endl;
        x1=x;
    }
    return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

