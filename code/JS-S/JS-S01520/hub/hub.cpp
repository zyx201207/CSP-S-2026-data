#include<bits/stdc++.h>
using namespace std;

int c,t; 
int n,k;

set<int> mp[1000006]={};

int fa[1000006]={};

int find(int x){
    if(fa[x]==x)return x;

    return fa[x]=find(fa[x]);
}

void merge(int x,int y){
    fa[find(x)]=find(y);
    return ;
}

set<int>s;

int dis[1000006]={};

const int inf=0x3f3f3f3f;

int bfs(){
    fill(dis+1,dis+n+1,inf);
    int ret=0;

    queue<int>q;

    for(auto &node:s){
        dis[node]=0;

        q.push(node);
    }

    while(!q.empty()){
        int frt=q.front();
        q.pop();

        for(auto &v:mp[frt]){
            if(dis[v]==inf){
                q.push(v);
                dis[v]=dis[frt]+1;

                ret=max(ret,dis[v]);
            }
        }
    }

    return ret;
}

int dfs(int num){
    if(num==n+1){
        if(s.size()!=k)return inf;

        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(auto &a:s){
            for(auto &b:s){
                if(mp[a].find(b)!=mp[a].end())merge(a,b);
            }
        }

        set<int>st;
        for(auto &node:s){
            st.insert(find(node));
        }

        if(st.size()>2)return inf;

        return bfs();

    }

    int ret=inf;

    ret=min(ret,dfs(num+1));


    s.insert(num);

    ret=min(ret,dfs(num+1));

    s.erase(num);


    return ret;
}




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;

    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            mp[u].insert(v);
            mp[v].insert(u);
        }

        cout<<dfs(1)<<endl;


        for(int i=1;i<=n;i++){
            mp[i].clear();
        }
    }

}