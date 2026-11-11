#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(int)a;i<(int)b;i++)

using namespace std;
struct tr{
    int sta;
    int tosta;
};
struct qu{
    int from;
    int to;
};
int c,n,m,d,q,station[500005],dis[500005],vis[500005];
vector<tr> train[505];
vector<qu> query;

void bfs(int u){
    queue<int> que;
    For(i,1,n+1){
        For(j,1,n+1){
           if(train[i].sta==u){
                que.push(train[i].sta);
           }
        }
    }
    while(!que.empty()){
        int v=que.front();
        que.pop();vis[v]=1;
        for(auto E:train[v]){
            dis[E]++;
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    For(i,1,m+1){
        cin>>station[i];
    }
    For(i,1,n+1){
        int k;
        cin>>k;
        For(j,1,k+1){
            int x,y;
            cin>>x>>y;
            train[i].push_back((tr){x,y});
        }
    }
    For(i,0,q){
        int x,y;
        cin>>x>>y;
        query.push_back((qu){x,y});
    }
    For(i,0,q){
        int t=0;
        dis[5005];
        t+=station[query[i].from];
        bfs(station[query[i]].from);
        cout<<dis[station[query[i].to]]<<"\n";
        memset(dis,0,sizeof(int));
    }
    return 0;
}






