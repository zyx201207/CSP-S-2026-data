#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t,n,k,deep[1000006][2],updeep[1000006],from[1000006],upfrom[1000006],del[2];
vector<int> e[1000006];
struct ROADS{
    int id,deep;
};
bool operator<(ROADS a,ROADS b){
        return a.deep<b.deep;
    }
priority_queue<ROADS> road;
bool isdel(int u,int v){
    return (del[0]==u&&del[1]==v) || (del[1]==u&&del[0]==v);
}
int dfs1(int u,int fa){
    for(auto v:e[u]){
        if(v!=fa && !isdel(u,v)){
            int t=dfs1(v,u);
            if(t>=deep[u][0]){
                deep[u][1]=deep[u][0];
                deep[u][0]=t;
                from[u]=v;
            }
        }
    }
    return deep[u][0]+1;
}
void dfs2(int u,int fa){
    for(auto v:e[u]){
        if(v!=fa && !isdel(u,v)){
            updeep[v]=updeep[u]+1;
            if(from[u]!=v) updeep[v]=max(updeep[v],deep[u][0]+1);
            else updeep[v]=max(updeep[v],deep[u][1]+1);
            upfrom[v]=u;
            dfs2(v,u);
        }
    }
}
void dfsmin(int u,int fa,int &mindeep,int &mark){
    if(mindeep>max(updeep[u],deep[u][0])){
        mindeep=max(updeep[u],deep[u][0]);
        mark=u;
    }
    for(auto v:e[u]){
        if(v!=fa && !isdel(u,v)){
            dfsmin(v,u,mindeep,mark);
        }
    }
}
int findmid(int x){
    memset(deep,0,sizeof(deep));
    memset(updeep,0,sizeof(updeep));
    dfs1(x,0);
    dfs2(x,0);
    int mid=x,mindeep=INT_MAX;
    dfsmin(x,0,mindeep,mid);
    return mid;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int mid=findmid(1);
        int m1,m2;
        if(updeep[mid]>deep[mid][0]){
            del[0]=upfrom[mid];
            del[1]=mid;
            m1=findmid(upfrom[mid]);
            m2=findmid(mid);
        }
        else{
            del[0]=from[mid];
            del[1]=mid;
            m1=findmid(mid);
            m2=findmid(from[mid]);
        }
        //cout<<del[0]<<del[1]<<mid<<' '<<m1<<' '<<m2<<'\n';
        if(k==2) cout<<max(max(updeep[m1],deep[m1][0]),max(updeep[m2],deep[m2][0]))<<'\n';
        else{
            while(!road.empty()) road.pop();
            for(auto u:e[m1]){
                if(!isdel(u,m1)){
                    if(u==upfrom[m1]) road.push({u,updeep[m1]});
                    else road.push({u,deep[u][0]+1});
                }
            }
            for(auto u:e[m2]){
                if(!isdel(u,m2)){
                    if(u==upfrom[m2]) road.push({u,updeep[m2]});
                    else road.push({u,deep[u][0]+1});
                }
            }
            while(!road.empty()){
                ROADS now=road.top();
                road.pop();
                k--;
                if(k<=0) break;
                for(auto u:e[now.id]){
                    if(!isdel(u,now.id)){
                        if(u==upfrom[now.id]) road.push({u,updeep[now.id]});
                        else road.push({u,deep[u][0]+1});
                    }
                }
            }
            cout<<road.top().deep<<'\n';
        }
        for(int i=1;i<=n;i++) e[i].clear();
    }
    return 0;
}
