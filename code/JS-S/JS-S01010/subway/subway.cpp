#include<bits/stdc++.h>
using namespace std;
const int TWT=500010;
int c, n, m, d, q;
int inandout[TWT];
vector<int> xianlu[TWT],huancheng[TWT];
vector<int> where_can_i_change[TWT],where_is_me[TWT];
struct node
{
    int point;
    int time;
    int come_from;
};
bool vis[TWT];
void bfs(int start_point,int end_point){
    deque<node> q;
    memset(vis,false,sizeof(vis));
    q.push_front({start_point,inandout[start_point],-1});
    while(!q.empty()){
        int u,b,come;
        u=q.front().point;
        b=q.front().time;
        come=q.front().come_from;
        q.pop_front();
        if(u==end_point){
            printf("%d",time+inandout[end_point]+huancheng[come][where_is_me[come][end_point]]);
            return ;
        }
        for(int i=0;i<where_can_i_change[u].size();i++){
            if(come!=where_can_i_change[u][i]){
                int ttime=b;
                if(come!=-1) ttime+=huancheng[come][where_is_me[come][u]];//go to the hall
                ttime+=huancheng[where_can_i_change[u][i]][where_is_me[where_can_i_change[u][i]][i]];//go to the platfrom
                int t=where_is_me[where_can_i_change[u][i]][u];
                if(t==0){
                    if(vis[t+1]==0){
                        vis[t+1]=1;
                        node tmp;
                        tmp.come_from=where_can_i_change[u][i];
                        tmp.point=xianlu[where_can_i_change[u][i]][t+1];
                        tmp.time=ttime;
                        q.push_back(tmp);
                    }
                }
                else if(t==xianlu[where_can_i_change[u][i]].size()-1){
                    if(vis[t-1]==0){
                        vis[t-1]=1;
                        node tmp;
                        tmp.come_from=where_can_i_change[u][i];
                        tmp.point=xianlu[where_can_i_change[u][i]][t-1];
                        tmp.time=ttime;
                        q.push_back(tmp);
                    }
                }
                else{
                    if(vis[t+1]==0){
                        vis[t+1]=1;
                        node tmp;
                        tmp.come_from=where_can_i_change[u][i];
                        tmp.point=xianlu[where_can_i_change[u][i]][t+1];
                        tmp.time=ttime;
                        q.push_back(tmp);
                    }
                    if(vis[t-1]==0){
                        vis[t-1]=1;
                        node tmp;
                        tmp.come_from=where_can_i_change[u][i];
                        tmp.point=xianlu[where_can_i_change[u][i]][t-1];
                        tmp.time=ttime;
                        q.push_back(tmp);
                    }
                }
            }
            else{
                int t=where_is_me[come][u];
                if(t==0){
                    if(vis[t+1]==0){
                        vis[t+1]=1;
                        node tmp;
                        tmp.come_from=come;
                        tmp.point=xianlu[come][t+1];
                        tmp.time=b;
                        q.push_front(tmp);
                    }
                }
                else if(t==xianlu[come].size()-1){
                    if(vis[t-1]==0){
                        vis[t-1]=1;
                        node tmp;
                        tmp.come_from=come;
                        tmp.point=xianlu[come][t-1];
                        tmp.time=b;
                        q.push_front(tmp);
                    }
                }
                else{
                    if(vis[t+1]==0){
                        vis[t+1]=1;
                        node tmp;
                        tmp.come_from=come;
                        tmp.point=xianlu[come][t+1];
                        tmp.time=b;
                        q.push_front(tmp);
                    }
                    if(vis[t-1]==0){
                        vis[t-1]=1;
                        node tmp;
                        tmp.come_from=come;
                        tmp.point=xianlu[come][t-1];
                        tmp.time=b;
                        q.push_front(tmp);
                    }
                }

            }
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&inandout[i]);
    }
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        for(int j=0;j<t;j++){
            int u,v;
            xianlu[i].push_back(u);
            huancheng[i].push_back(v);
            where_can_i_change[u].push_back(i);
            where_is_me[u].push_back(j);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        bfs(x,y);
    }
    return 0;
}
